#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an item with weight and value
struct Item {
    int value, weight;
};

// Comparator: sort items by value-to-weight ratio (descending)
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to return maximum value in knapsack
double fractionalKnapsack(int W, vector<Item>& items, int n) {
    // Step 1: Sort items by value/weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0; // Total value in knapsack
    for (int i = 0; i < n; i++) {
        if (W == 0)
            break;

        // If the item can be fully included
        if (items[i].weight <= W) {
            W -= items[i].weight;
            totalValue += items[i].value;
        }
        // If only a fraction of the item can be included
        else {
            totalValue += items[i].value * ((double)W / items[i].weight);
            W = 0; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    double maxValue = fractionalKnapsack(W, items, n);
    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}
