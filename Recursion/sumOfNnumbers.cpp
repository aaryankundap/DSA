//PROBLEM STATEMENT
// *****Given an integer N, return the sum of first N natural numbers. Try to solve this using recursion.****


#include <bits/stdc++.h>
using namespace std;

class Solution{	
	public:
		int NnumbersSum(int N,int sum){
			if(N<1)
            {
                return sum;
            }
            return NnumbersSum(N-1,sum+N);
		}
};

int main(){
    Solution sol;
    int N;
    cout<<"Enter the number "<<endl;
    cin>>N;

    int result = sol.NnumbersSum(N,0);
    cout<<result<<endl;

    return 0;
}