#include <bits/stdc++.h>
using namespace std;

int linearSearch(int n, int num,vector<int> &arr){
    for(int i=0;i<num;i++){
        if(arr[i]==num) return num;
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;

    int key;
    cout<<"Enter the number u want to search: "<<endl;
    cin>>key;

    vector<int> arr(n);
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int result= linearSearch(n,key,arr);
    cout<<result;
    

    return 0;
}