#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class process{
public:
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time = 0;
    int turnaround_time = 0;
    int waiting_time = 0;
};

void bubblesort(process p[10], int n){
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (p[j].burst_time > p[j+1].burst_time){
                swap(p[j], p[j+1]);
            }
        }
    }
}

int main(){
    process p[10];
    int n,id,at,bt;
    int time = 0;
    float avgwt = 0, avgtat = 0;
    cout << "enter no of process:";
    cin >> n;
    for (int i=0; i<n; i++){
        cout << "enter process id:";
        cin >> id;
        p[i].pid = id;

        cout << "enter arrival time:";
        cin >> at;
        p[i].arrival_time = at;

        cout << "enter burst time:";
        cin >> bt;
        p[i].burst_time = bt;
    }
    bubblesort(p,n);

    queue<process> q;
    int visited[10] = {0};

    while(q.size() != n) {
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= time && visited[i] != 1) {
                q.push(p[i]);
                time += p[i].burst_time;
                visited[i] = 1;
                p[i].completion_time = time;
                p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
                p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                break;
            }
        }
    }

    cout << "\n";
    cout << "gantt chart:";
    for (int i=0; i<n; i++){
        cout << (q.front()).pid << " ";
        q.pop();
    }
    cout << "\n";

    for (int i=0; i<n; i++){
        avgtat += p[i].turnaround_time;
        avgwt += p[i].waiting_time;
    }

    avgwt = avgwt/n;
    avgtat = avgtat/n;

    cout << "average turnaround time: " << avgtat;
    cout << "\n";
    cout << "average waiting time: " << avgwt;
}
