#include<iostream>
using namespace std;

int binarySearch(int a[],int low,int high,int target){
    if(low>high){
        return -1;
    }
    int mid = low + (high-low)/2;
    if(a[mid]==target){
        return mid;
    }
    if(a[mid]<target){
        return binarySearch(a,mid+1,high,target);
    }else{
        return binarySearch(a,low,mid-1,target);
    }
}

int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int a[n];
    cout<<"Enter the element of an array:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int target;
    cout<<"Enter the target:";
    cin>>target;
    int result = binarySearch(a,0,n-1,target);
    
    if(result != -1){
        cout<<"Element found at index: "<<result<<endl;
    }else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}
