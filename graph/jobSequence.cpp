#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent a job
struct Job {
    char id;
    int deadline;
    int profit;
};

// Comparator function to sort jobs by profit (descending)
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(Job jobs[], int n) {
    // Step 1: Sort jobs by profit
    sort(jobs, jobs + n, compare);

    // Step 2: Find max deadline to define slots
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, jobs[i].deadline);

    // Step 3: Initialize time slots as empty
    vector<char> schedule(maxDeadline + 1, '-'); // index 1 to maxDeadline

    int totalProfit = 0;
    int jobCount = 0;

    // Step 4: Try to place each job in the latest available slot before deadline
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (schedule[j] == '-') {
                schedule[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }

    // Output
    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (schedule[i] != '-')
            cout << schedule[i] << " ";
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
    cout << "Total Jobs Done: " << jobCount << endl;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    Job jobs[n];

    cout << "Enter job id, deadline, and profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobSequencing(jobs, n);

    return 0;
}
