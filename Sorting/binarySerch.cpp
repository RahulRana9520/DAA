#include<iostream>
using namespace std;

void binarySearch(int a[],int n,int target){
    int left=0;
    int right=n-1;
    bool found=false;
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]==target){
            cout<<"found:"<<target;
            found=true;
            break;
        }
        if(target<a[mid]){
            right=mid-1;
        }
        if(target>a[mid]){
            left=mid+1;
        }
    }
    if(!found){
        cout<<"Not found!";
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
    binarySearch(a,n,target);
}