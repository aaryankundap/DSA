
// Question--> fibonacci series     ("Not the most optimised solution recursive solution just for the sake of practice")

#include<bits/stdc++.h>
using namespace std;

int f(int n){
    if(n<=1){
        return n;
    }
    int last=f(n-1);
    int slast=f(n-2);
    return f(n-1)+f(n-2);
}

int main(){
    int n;
    cout<<"Enter the value: ";
    cin>>n;
    cout<<f(n);
    return 0;
}


