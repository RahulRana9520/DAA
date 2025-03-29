#include <iostream>
using namespace std;

int lower(int z[], int low, int high, int s) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        cout << "Lower bound check: low=" << low << ", high=" << high << ", mid=" << mid << endl;
        if (z[mid] < s) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int upper(int z[], int low, int high, int s) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        cout << "Upper bound check: low=" << low << ", high=" << high << ", mid=" << mid << endl;
        if (z[mid] <= s) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int freq(int z[], int n, int s) {
    cout << "Calculating frequency for " << s << endl;
    int l = lower(z, 0, n, s);
    int u = upper(z, 0, n, s);
    return u - l;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int z[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> z[i];
    }
    int s;
    cout << "Enter the number to find frequency: ";
    cin >> s;
    cout << "Frequency of " << s << " is " << freq(z, n, s) << endl;
    return 0;
}