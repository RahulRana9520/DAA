#include <iostream>
using namespace std;

void countSort(int arr[], int n) {
    // Find max element to size the count array
    int maxElem = arr[0];
    for(int i = 1; i < n; i++)
        maxElem = max(maxElem, arr[i]);

    int count[maxElem + 1] = {0};

    // Count occurrences
    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    // Build sorted array
    int index = 0;
    for(int i = 0; i <= maxElem; i++) {
        while(count[i]-- > 0)
            arr[index++] = i;
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    countSort(arr, n);

    cout << "Sorted array using Count Sort:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
