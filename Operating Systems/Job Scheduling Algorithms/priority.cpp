#include <iostream>
#include <algorithm>
using namespace std;

struct Process
{
    int id, at, bt, pr, ft;
    float tat, wt;
};

Process p[10];

int Input()
{
    int n;
    cout << "Enter total number of processes: ";
    cin >> n;
    cout << "\nEnter Arrival Time, Burst Time and Priority for each process:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "P[" << i  << "]: ";
        cin >> p[i].at >> p[i].bt >> p[i].pr;
        p[i].id = i;
    }
    return n;
}

bool Compare(Process p1, Process p2)
{
    if (p1.pr < p2.pr)
    {
        return true;
    }
    return false;
}

int main()
{
    int n = Input();
    sort(p + 2, p + n + 1, Compare);

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            p[i].ft = p[i].bt + p[i].at;
            p[i].tat = p[i].ft - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }
        else
        {
            p[i].ft = p[i-1].ft + p[i].bt;
            p[i].tat = p[i].ft - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }
    }

    float avwt = 0, avtat = 0;

    cout << "\nProcess ID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time";
    for (int i = 1; i <= n; i++)
    {
        cout <<"\n"<< p[i].id << "\t\t" << p[i].at << "\t\t" << p[i].bt << "\t\t" << p[i].pr << "\t\t" << p[i].ft << "\t\t" << p[i].tat << "\t\t" << p[i].wt;

        avwt += p[i].wt;
        avtat += p[i].tat;
    }

    avwt /= n;
    avtat /= n;

    cout << "\n\nAverage Waiting Time: " << avwt;
    cout << "\nAverage Turnaround Time: " << avtat;
}




// #include <iostream>
// using namespace std;

// int main() {
//     int n, at[20], bt[20], wt[20], tat[20], ct[20], p[20], pri[20], i, j;
//     float avwt = 0, avtat = 0;
//     cout << "Enter total number of processes: ";
//     cin >> n;
//     cout << "\nEnter Arrival Time, Burst Time and Priority for each process:\n";
//     for (i = 0; i < n; i++) {
//         cout << "P[" << i + 1 << "]: ";
//         cin >> at[i] >> bt[i] >> pri[i];
//         p[i] = i + 1;
//     }
//     // sorting the processes according to arrival time
//     // sorting the processes according to arrival time and priority
//     for (i = 0; i < n - 1; i++) {
//     for (j = i + 1; j < n; j++) {
//         if (at[i] > at[j] || (at[i] == at[j] && pri[i] > pri[j])) {
//             swap(at[i], at[j]);
//             swap(bt[i], bt[j]);
//             swap(pri[i], pri[j]);
//             swap(p[i], p[j]);
//         }
//     }
// }

//     ct[0] = at[0] + bt[0];
//     // calculating completion time for each process
//     for (i = 1; i < n; i++) {
//         ct[i] = max(ct[i-1] + bt[i], at[i] + bt[i]);
//     }
//     wt[0] = 0;
//     // waiting time for first process is 0
//     // calculating waiting time
//     for (i = 1; i < n; i++) {
//         wt[i] = 0;
//         for (j = 0; j < i; j++) {
//             wt[i] += bt[j];
//         }
//         wt[i] -= at[i];
//         if (wt[i] < 0) {
//             wt[i] = 0;
//         }
//     }
//     cout << "\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tWaiting Time\tTurnaround Time";
//     // calculating turnaround time
//     for (i = 0; i < n; i++) {
//         tat[i] = bt[i] + wt[i];
//         avwt += wt[i];
//         avtat += tat[i];
//         cout << "\nP[" << p[i] << "]\t" << at[i] << "\t\t" << bt[i] << "\t\t" << pri[i] << "\t\t" << ct[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
//     }
//     avwt /= i;
//     avtat /= i;
//     cout << "\n\nAverage Waiting Time: " << avwt;
//     cout << "\nAverage Turnaround Time: " << avtat;
//     return 0;
// }

