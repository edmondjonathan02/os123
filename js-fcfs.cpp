#include <iostream>
using namespace std;

void fcfs()
{
    int n, i, j, p[20], bt[20], wt[20], tat[20], pos, temp, total = 0;
    float avg_tat, avg_wt;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "Enter the burst time of P" << i + 1 << ": ";
        cin >> bt[i];
        p[i] = i + 1;
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
        total += wt[i];
    }
    avg_wt = (float)total / n;
    total = 0;

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        total += tat[i];
        cout << "P" << p[i] << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    avg_tat = (float)total / n;
    cout << "\nAverage waiting time: " << avg_wt << endl;
    cout << "Average turnaround time: " << avg_tat << endl;
}

int main()
{
    fcfs();
    return 0;
}

/*OUTPUT
Enter the number of processes: 3
Enter the burst time of P1: 6
Enter the burst time of P2: 3
Enter the burst time of P3: 2

Process Burst Time      Waiting Time    Turnaround Time
P1      6               0               6
P2      3               6               9
P3      2               9               11

Average waiting time: 5
Average turnaround time: 8.66667*/
