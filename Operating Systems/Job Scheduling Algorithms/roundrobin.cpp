#include <iostream>
#include <queue>
using namespace std;
struct Process
{
	int id, at, bt, ft;
	float wt, tat;
};
Process p[10], p1[10];
queue<int> q1;
int Input()
{
	int n;
	cout << "Enter total number of processes: ";
	cin >> n;
    cout << "\nEnter Arrival Time and Burst Time for each process:\n";
	for (int i = 1; i <= n; i++)
	{
		cout << "P[" << i  << "]: ";
		cin >> p[i].at >> p[i].bt;
		p[i].id = i;
	}
	for (int i = 1; i <= n; i++)
	{
		p1[i] = p[i];
	}
	return n;
}
void Logic(int n)
{
	int i = 1, m, Q_t, val;
	cout << "Enter time quantum:";
	cin >> Q_t;
	val = p1[1].at;
	for (i = 1; i <= n && p1[i].at <= val; i++)
	{
		q1.push(p1[i].id);
	}
	while (!q1.empty())
	{
		m = q1.front();
		q1.pop();
		if (p1[m].bt >= Q_t)
		{
			val = val + Q_t;
			p1[m].bt -=Q_t;
		}
		else
		{
			val = val + p1[m].bt;
			p1[m].bt = 0;

		}
		while (i <= n && p1[i].at <= val)
		{
			q1.push(p1[i].id);
			i++;
		}
		if (p1[m].bt > 0)
		{
			q1.push(p[m].id);
		}
		else
		{
			p[m].ft = val;
		}
	}
}
void TurnWait(int n){
	for(int i=1;i<=n;i++){
		p[i].tat = p[i].ft - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
		p[0].tat = p[0].tat + p[i].tat;
		p[0].wt = p[0].wt + p[i].wt;
	}
	p[0].tat =p[0].tat /n;
	p[0].wt =p[0].wt /n;
}
void Display(int n){
	cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time";
	for(int i=1;i<=n;i++){
		cout << "\nP[" << i << "]\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].ft<<"\t\t"<<p[i].tat<<"\t\t"<<p[i].wt;
	}
	cout<<endl;
	cout<<"\nAverage Turnaround time: "<<p[0].tat;
	cout<<"\nAverage waiting time: "<<p[0].wt;
}
int main()
{
	int n = Input();
	Logic(n);
	TurnWait(n);
	Display(n);
}


// #include <iostream>
// #include <vector>

// using namespace std;

// struct Process {
//     int id;
//     int arrival_time;
//     int burst_time;
//     int remaining_time;
//     int completion_time;
//     int turnaround_time;
//     int waiting_time;
// };

// int main() {
//     int n, time_quantum;
//     cout << "Enter the number of processes: ";
//     cin >> n;
//     cout << "Enter the time quantum: ";
//     cin >> time_quantum;
    
//     vector<Process> processes(n);
//     for (int i = 0; i < n; i++) {
//         cout << "Enter arrival time and burst time for process " << i+1 << ": ";
//         cin >> processes[i].arrival_time >> processes[i].burst_time;
//         processes[i].id = i+1;
//         processes[i].remaining_time = processes[i].burst_time;
//     }
    
//     int current_time = 0;
//     int total_waiting_time = 0;
//     int total_turnaround_time = 0;
//     int last_completed_time = 0;
    
//     bool all_processes_completed;
//     do {
//         all_processes_completed = true;
//         for (int i = 0; i < n; i++) {
//             Process& current_process = processes[i];
//             if (current_process.remaining_time > 0) {
//                 all_processes_completed = false;
//                 int executed_time = min(time_quantum, current_process.remaining_time);
//                 current_process.remaining_time -= executed_time;
//                 current_time += executed_time;
                
//                 if (current_process.remaining_time == 0) {
//     current_process.completion_time = current_time;
//     current_process.turnaround_time = current_process.completion_time - current_process.arrival_time;
//     current_process.waiting_time = current_process.turnaround_time - current_process.burst_time;
//     total_waiting_time += current_process.waiting_time;
//     total_turnaround_time += current_process.turnaround_time;
//     last_completed_time = current_process.completion_time;
// } else if (i == n-1) {
//     i = -1;  // start from the beginning
// }

//             }
//         }
//         if (all_processes_completed) {
//             break;
//         }
//         if (current_time == last_completed_time) {
//             current_time++;
//         }
//     } while (true);
    
//     double avg_waiting_time = static_cast<double>(total_waiting_time) / n;
//     double avg_turnaround_time = static_cast<double>(total_turnaround_time) / n;
    
//     cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
//     for (Process p : processes) {
//         cout << p.id << "\t\t" << p.arrival_time << "\t\t" << p.burst_time << "\t\t";
//         if (p.completion_time > 0) {
//             cout << p.completion_time << "\t\t";
//             cout << p.turnaround_time << "\t\t\t" << p.waiting_time << endl;
//         } else {
//             cout << "Not Completed\n";
//         }
//     }
    
//     cout << "Average Waiting Time: " << avg_waiting_time << endl;
//     cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
    
//     return 0;
// }

