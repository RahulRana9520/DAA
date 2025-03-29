#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftArr(n1), rightArr(n2);
    for (int i = 0; i < n1; i++){
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++){
        rightArr[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
    if (leftArr[i] <= rightArr[j]) {
        arr[k] = leftArr[i];
        i++;
    } else {
        arr[k] = rightArr[j];
        j++;
    }
    k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergesort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
bool duplicate(vector<int>& arr) {
    mergesort(arr, 0, arr.size() - 1); 
    for (int i = 1; i < arr.size(); i++){
    if (arr[i] == arr[i - 1]) {
        return true; 
    }
    }
return false;
}

int main() {
    int testCases;
    cin >> testCases; 
    while (testCases--) {
        int n;
        cin >> n; 
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; 
        }
        if (duplicate(arr)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}