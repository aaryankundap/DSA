#include <iostream>
#include <climits>
using namespace std;

const int MAX = 10;

class OBST {
public:
    int keys[MAX];               // Keys (assumed sorted)
    int freq[MAX];               // Access frequencies
    int cost[MAX + 1][MAX + 1];  // Cost matrix
    int root[MAX + 1][MAX + 1];  // Root matrix for structure
    int n;                       // Number of keys

    void insert() {
        cout << "Enter number of keys: ";
        cin >> n;
        cout << "Enter sorted keys and their frequencies:\n";
        for (int i = 0; i < n; i++) {
            cout << "Key[" << i << "]: ";
            cin >> keys[i];
            cout << "Freq[" << i << "]: ";
            cin >> freq[i];
        }
    }

    void buildOBST() {
        // Initialize diagonals to 0
        for (int i = 0; i <= n; i++)
            cost[i][i] = 0;

        // Initialize cost for length = 1
        for (int i = 0; i < n; i++) {
            cost[i][i + 1] = freq[i];
            root[i][i + 1] = i;
        }

        // Build OBST for chains of length 2 to n
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length;
                cost[i][j] = INT_MAX;

                int freqSum = 0;
                for (int k = i; k < j; k++) {
                    freqSum += freq[k];
                }

                for (int r = i; r < j; r++) {
                    int c = cost[i][r] + cost[r + 1][j] + freqSum;
                    if (c < cost[i][j]) {
                        cost[i][j] = c;
                        root[i][j] = r;
                    }
                }
            }
        }

        // Print cost matrix
        cout << "\nCost Matrix:\n";
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i >= j)
                    cout << "0\t";
                else
                    cout << cost[i][j] << "\t";
            }
            cout << endl;
        }

        cout << "\nMinimum cost of OBST: " << cost[0][n] << endl;
        cout << "Root of OBST: " << keys[root[0][n]] << endl;

        cout << "\nTree structure (Root indices):\n";
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i >= j)
                    cout << "-\t";
                else
                    cout << root[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    OBST tree;
    tree.insert();
    tree.buildOBST();
    return 0;
}
