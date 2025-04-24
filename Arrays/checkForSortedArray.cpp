#include<bits/stdc++.h>
using namespace std;

int isSorted(int n,vector<int> &arr){
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){

        }
        else{
            return false;
        }
    }
    return true;   
}


int main(){
    int n;
    cout<<"Enter the numbers of elements: "<<endl;
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result=isSorted(n,arr);
    cout<<result;
    return 0;
}