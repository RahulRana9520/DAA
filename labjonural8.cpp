
#include <iostream>
using namespace std;
int selection(int arr[], int s) {
    int c = 0, sw = 0;
    for (int i = 0; i < s - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < s; j++) {
            c++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            sw++;
        }
    }
    cout << "Comparisons: " << c << endl;
    cout << "Swaps: " << sw << endl;
    return 0;
}
int main() {
    int s;
    cout << "Enter the size of the array: ";
    cin >> s;
    
    int arr[s];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < s; i++) {
        cin >> arr[i];
    }
    selection(arr, s);
    cout << "Sorted array: ";
    for (int i = 0; i < s; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}