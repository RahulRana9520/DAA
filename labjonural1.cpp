// Q1- Given an array of nonnegative integers, design a linear algorithm and implement it using a
// program to find whether given key element is present in the array or not. Also, find total
// number of comparisons for each input case. (Time Complexity = O(n), where n is the size of
// input).

#include <iostream>
using namespace std;
void linearSearch(int arr[], int n, int key) {
int comparisons = 0;
for(int i = 0; i < n; i++) {
    comparisons++;
    if (arr[i] == key) {
        cout << "Present " << "\nNo of comparisons : "<<comparisons<< "\nIndex : " << i << endl;
        return;
    }
}
    cout << "Not Present " << "\nNo of comparisons : "<< comparisons << endl;
}

int main(){
int t;
cout<<"Enter the no of testcases : ";
cin >> t;
while(t--) {
    int n;
    cout<<"Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout<<"Enter the target value : ";
    int key;
    cin >> key;
    linearSearch(arr, n, key);
}
return 0;
}