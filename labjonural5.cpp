#include<iostream>
using namespace std;
int main(){   
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n],i;
    cout<<"enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=n-1;i>=2;i--)
    {
        int low=0;
        int high=n-1;
        int target=arr[i];
        while(low<high)
        {
            int sum=arr[low]+arr[high];
            if(sum==target)
            {
                cout<<low <<" "<<high <<" "<<i<<endl;
                low++;
                high--;
            }
            else if(sum<target)
            {
                low++;
            }
            else high--;
        }
    }
    return 0;
}