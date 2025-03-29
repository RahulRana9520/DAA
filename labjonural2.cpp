#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key, int &comparisons) {
    int left = 0, right = n - 1;
    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cout<<"Enter the size of array:";
    cin >> n;
    int arr[n];
    cout<<"Enter the elements of array:";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<< "Enter the target value:";
    int key;
    cin >> key;

    int comparisons = 0;
    int result = binarySearch(arr, n, key, comparisons);

    cout << "Index: "<< result << " " <<"Comparisons: " << comparisons << endl;

    return 0;
}