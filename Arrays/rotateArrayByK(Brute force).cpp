#include<bits/stdc++.h>
using namespace std;

//brute force solution
void leftRotate(vector<int> &arr,int n,int k){
    k=k%n; // gets number of places to be replaced .It is useful when the value of k is greater than n as k will always be multiple of n

    vector<int> temp(k);
    for(int i=0;i<k;i++){
        temp[i]=arr[i];
    }

    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }

    for(int i=n-k;i<n;i++){
        arr[i]=temp[i-(n-k)];
    }
}


int main(){
    int n;
    cout<<"Enter the elements: "<<endl;
    cin>>n;

    vector<int> arr(n);
    cout<<"The elements are: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter by how many places u want to rotate the array: "<<endl;
    cin>>k;

    leftRotate(arr,n,k);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
