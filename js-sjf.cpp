#include <iostream>
using namespace std;

void sjf()
{
    int n, i, j, p[20], bt[20], wt[20], tat[20], pos, temp, total = 0;
    float avg_wt, avg_tat;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "Enter the burst time of P" << i + 1 << ": ";
        cin >> bt[i];
        p[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[pos])
            {
                pos = j;
            }
        }
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
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
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        cout << "P" << p[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    avg_tat = (float)total / n;

    cout << "\nAverage waiting time: " << avg_wt << endl;
    cout << "Average turnaround time: " << avg_tat << endl;
}

int main()
{
    sjf();
    return 0;
}

/*OUTPUT
Enter the number of processes: 4
Enter the burst time of P1: 8
Enter the burst time of P2: 5
Enter the burst time of P3: 2
Enter the burst time of P4: 3

Process Burst Time      Waiting Time    Turnaround Time
P3              2               0               2
P4              3               2               5
P2              5               5               10
P1              8               10              18

Average waiting time: 4.25
Average turnaround time: 8.75*/
