#include<iostream>
using namespace std;
void merge(int arr[],int l,int mid,int h,int n)
{
    int temp[n];
    int left=l;
    int right=mid+1;
    int k=0;
    while(left<=mid && right<=h)
    {
        if(arr[left]<=arr[right])
        {
          temp[k]=arr[left];
          left++;
          k++;
        }
        else{
            temp[k]=arr[right];
            k++;
            right++;
        }
    }
    while(left<=mid)
    {
        temp[k]=arr[left];
        k++;
        left++;
    }
   while(right<=h)
   {
      temp[k]=arr[right];
      k++;
      right++;
   }
 
   for(int i=l;i<=h;i++)
   {
    arr[i]=temp[i-l];
   }
 
}
void mergesort(int arr[],int l,int h, int n)
{
    if(l==h) return;
    int mid=(l+h)/2;
    mergesort(arr,l,mid,n);
    mergesort(arr,mid+1,h,n);
    merge(arr,l,mid,h,n);
}

void existSum(int arr[],int left, int right,int n,int key){
    int sum = 0;
    while(sum!=key){
        sum=arr[left]+arr[right];
        if(sum==key){
            cout<<"index:"<<left;
            cout<<"index:"<<right;
        }else if(arr[right]>sum){
            right=right-1;
        }else{
            left=left-1;
        }
    }
}
int main(){
    int n;
    cout<<"Enter the size of an array:";
    cin>>n;
    int arr[n];
    cout<<"enter array elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    mergesort(arr,0,n-1,n);

    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
    int key;
    cout<<"Enter the key:";
    cin>>key;
    existSum(arr,0,n-1,n,key);
    return 0;
}