#include <iostream>
using namespace std;

void bubble(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool binary(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return true;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int find(int arr[], int n, int k) {
    bubble(arr, n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (binary(arr, i + 1, n - 1, arr[i] + k)) {
            count++;
        }
    }
    
    return count;
}


int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    cout << "Count: " << find(arr, n, k) << endl;
    return 0;
}