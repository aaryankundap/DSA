#include <bits/stdc++.h>
using namespace std;

void leftrotate(vector<int> &arr, int n, int k) {
    k = k % n; // In case k > n
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}

int main() {
    int n;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;

    vector<int> arr(n);
    cout<<"The elements are: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter value for k: "<<endl;
    cin>>k;

    leftrotate(arr,n,k);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

