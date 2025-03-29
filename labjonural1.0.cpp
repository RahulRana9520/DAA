#include <iostream>
using namespace std;
int linearSearchRecursive(int arr[], int n, int key, int index) {
    static int comparisons = 0;
    comparisons++;
    if (index == n) {
        cout << "Not Present\nNo of comparisons: " << comparisons << endl;
        comparisons = 0;
        return -1;
    }
    if (arr[index] == key) {
        cout << "Present\nNo of comparisons: " << comparisons << "\nIndex: " << index << endl;
        comparisons = 0;
        return index;
    }
    return linearSearchRecursive(arr, n, key, index + 1);
}
int main() {
int t;
cout << "Enter the number of test cases: ";
cin >> t;
while (t--) {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter the target value: ";
    int key;
    cin >> key;
    linearSearchRecursive(arr, n, key, 0);
}
return 0;
}