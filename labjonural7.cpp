#include <iostream>
#include <vector>
using namespace std;
void insertion(vector<int>& arr, int& comparison, int& shift) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j]) {
            comparison++; 
            arr[j + 1] = arr[j]; 
            shift++; 
            j--;
        }
        if (j >= 0) {
            comparison++;  // One extra comparison when the while loop breaks
        }
        arr[j + 1] = temp;  // Insert element at the correct position
        shift++; 
    }
}
int main(){
    int testinput;
    cout<<"Enter number of test case:";
    cin>>testinput;
    while(testinput--){
        cout<<"Enter the size of array:";
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int comparison=0, shift=0;
    insertion(arr,comparison,shift);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nComparisons: "<<comparison<<"\nShifts: "<<shift<<endl;
    }
    return 0;
}