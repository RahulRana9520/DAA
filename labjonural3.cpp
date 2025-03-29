#include <iostream>
using namespace std;
void ExpontialSearch(int arr[], int n, int key) {
    static int comparisons = 0;
    if (arr[0] == key) {
        cout << "Present at index 0\nNumber of comparisons: 1" << endl;
        return;
    }
    int i = 1;
    while (i < n && arr[i] <= key) {
        i *= 2;
        comparisons++;
    }
    int low = i / 2;                    // Lower bound of the identified range
    int high = (i < n) ? i : n - 1;     // Upper bound (either i or last index)
    for (int j = low; j <= high; j++) {
        comparisons++;
        if (arr[j] == key) {
            cout << "Present at index " << j << "\nNumber of comparisons: " << comparisons <<
            endl;
            comparisons = 0;
            return;
        }
    }
    cout << "Target is not found in the given array\n";
    cout << "Number of comparisons: " << comparisons << endl;
    comparisons = 0;
}
int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n, key;
        cout << "Enter the size of array: ";
        cin >> n;
        int arr[n];
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++)
        cin >> arr[i];
        cout << "Enter the target: ";
        cin >> key;
        ExpontialSearch(arr, n, key);
    }
    return 0;
}