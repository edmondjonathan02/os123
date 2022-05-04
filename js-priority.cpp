#include <iostream>
using namespace std;

void priority()
{
    int n, i, j, p[20], pr[20], bt[20], wt[20], tat[20], pos, temp, total = 0;
    float avg_wt, avg_tat;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cout << "Enter the burst time of process" << i + 1 << ": ";
        cin >> bt[i];
        cout << "Enter the priority of process" << i + 1 << ": ";
        cin >> pr[i];
        p[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
            {
                pos = j;
            }
        }
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
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
    priority();
    return 0;
}

/*OUTPUT
Enter the number of processes: 4
Enter the burst time of process1: 6
Enter the priority of process1: 2
Enter the burst time of process2: 7
Enter the priority of process2: 1
Enter the burst time of process3: 4
Enter the priority of process3: 2
Enter the burst time of process4: 5
Enter the priority of process4: 4

Process Burst Time      Waiting Time    Turnaround Time
P2              7               0               7
P1              6               7               13
P3              4               13              17
P4              5               17              22

Average waiting time: 9.25
Average turnaround time: 14.75*/
