#include <iostream>
#include <climits>
using namespace std;

#define MAX_NODES 100
#define INF INT_MAX

class PrimMST {
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    int totalNodes;

public:
    void createGraph();
    void displayGraph();
    void findMinimumSpanningTree();
};

// Create the graph by inputting edges
void PrimMST::createGraph() {
    cout << "Enter total number of offices (nodes): ";
    cin >> totalNodes;

    if (totalNodes <= 0 || totalNodes > MAX_NODES) {
        cout << "Invalid number of offices!" << endl;
        return;
    }

    // Initialize all edges to INF (no connection)
    for (int i = 0; i < totalNodes; i++) {
        for (int j = 0; j < totalNodes; j++) {
            adjacencyMatrix[i][j] = (i == j) ? 0 : INF;
        }
    }

    int totalEdges;
    cout << "Enter number of connections (edges): ";
    cin >> totalEdges;

    for (int i = 0; i < totalEdges; i++) {
        int fromNode, toNode, cost;
        cout << "Enter start office, end office, and cost: ";
        cin >> fromNode >> toNode >> cost;

        if (fromNode < 0 || fromNode >= totalNodes || 
            toNode < 0 || toNode >= totalNodes || 
            fromNode == toNode || cost <= 0) {
            cout << "Invalid input. Please try again." << endl;
            i--;
            continue;
        }

        adjacencyMatrix[fromNode][toNode] = cost;
        adjacencyMatrix[toNode][fromNode] = cost; // Undirected graph
    }
}

// Display the adjacency matrix
void PrimMST::displayGraph() {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < totalNodes; i++) {
        for (int j = 0; j < totalNodes; j++) {
            if (adjacencyMatrix[i][j] == INF)
                cout << "INF\t";
            else
                cout << adjacencyMatrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

// Prim's Algorithm implementation
void PrimMST::findMinimumSpanningTree() {
    int isIncluded[MAX_NODES] = {0}; // Track included nodes
    isIncluded[0] = 1; // Start from node 0

    int edgeCount = 0;
    int totalCost = 0;

    cout << "\nMinimum Spanning Tree Edges:\n";

    while (edgeCount < totalNodes - 1) {
        int minCost = INF;
        int from = -1, to = -1;

        for (int i = 0; i < totalNodes; i++) {
            if (isIncluded[i]) {
                for (int j = 0; j < totalNodes; j++) {
                    if (!isIncluded[j] && adjacencyMatrix[i][j] < minCost) {
                        minCost = adjacencyMatrix[i][j];
                        from = i;
                        to = j;
                    }
                }
            }
        }

        if (from == -1 || to == -1) {
            cout << "The graph is disconnected. MST not possible.\n";
            return;
        }

        isIncluded[to] = 1;
        totalCost += adjacencyMatrix[from][to];
        cout << "Office " << from << " --> Office " << to << " [Cost: " << adjacencyMatrix[from][to] << "]\n";
        edgeCount++;
    }

    cout << "Total Minimum Cost to Connect Offices: " << totalCost << endl;
}

// Driver Code
int main() {
    PrimMST officeNetwork;
    officeNetwork.createGraph();
    officeNetwork.displayGraph();
    officeNetwork.findMinimumSpanningTree();
    return 0;
}
