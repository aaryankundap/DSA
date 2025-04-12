//PROBLEM STATMENT
//You are given an integer n. Return the value of n! or n factorial.
//factorial of a number is the product of all positive integers less than or equal to that number.

#include <bits\stdc++.h>
using namespace std;
class Solution{
    public:
        int factorial(int n){
            if(n==0){
                return 1;
            }
            return n*factorial(n-1);
        }
};

int main(){
    int n;
    cout<<"enter a number:"<<endl;
    cin>>n;

    Solution sol;
    int result=sol.factorial(n);
    cout<<result<<endl;
    return 0;
}