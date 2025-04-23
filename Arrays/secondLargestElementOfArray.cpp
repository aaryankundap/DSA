#include<bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> &arr,int n){
    int largest=arr[0];
    int slargest=-1;
    for(int i = 1 ;i<n;i++){
        if(arr[i]>largest){
            slargest=largest;
            largest=arr[i];
        }
    }
    return slargest;
}

int secondSmallest(vector<int> &arr,int n){
    int smallest=arr[0];
    int secSmallest=INT_MAX;
    for(int i=1;i<n;i++){
        if(arr[i]<smallest){
            secSmallest=smallest;
            smallest=arr[i];
        }
    }
    return secSmallest;
}


vector<int> getSecondOrderElement(int n,vector<int> &arr){
    int sLargest=secondLargest(arr,n);
    int sSmallest=secondSmallest(arr,n);
    return {sLargest,sSmallest};
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

    vector<int> result=getSecondOrderElement(n,arr);
    cout<<"Second largest element: "<<result[0]<<endl;
    cout<<"Second smallest element: "<<result[1];
    return 0;
}