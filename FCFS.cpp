#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter total number of processes: ";
    cin >> n;

    int at[n], bt[n], ct[n], tat[n], wt[n], pid[n];

    // Taking input
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time and Burst Time for Process P" << pid[i] << ": ";
        cin >> at[i] >> bt[i];
    }

    // Sorting processes based on Arrival Time using selection sort-like method with sort()
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[j] < at[i]) {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < at[i]) {
            currentTime = at[i];  // CPU remains idle
        }
        ct[i] = currentTime + bt[i];  // Completion Time
        currentTime = ct[i];

        tat[i] = ct[i] - at[i];  // Turnaround Time
        wt[i] = tat[i] - bt[i];  // Waiting Time
    }

    // Display results
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\n";
    }

    return 0;
}
