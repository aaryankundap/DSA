#include<bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int> &arr,int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    return arr;
}

int main(){
    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;

    vector<int> arr(n);
    cout<<"The elements are: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> result=rotateArray(arr,n);
    cout<<"Rotated array is: "<<endl;

    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}