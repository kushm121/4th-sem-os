#include <bits/stdc++.h>
using namespace std;

class process{
public:
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int tat;
    int wt;
    int bt;
};
bool comp(process p1,process p2){
    return (p1.arrival_time<p2.arrival_time);
}
int main(){
    int n;
    cout<<"enter number of processes"<<endl;
    cin>>n;
    process p[n];
    queue<int>readyQ;
    int timequanta;
    for (int i = 0; i < n; i++)
    {
        cin>>p[i].pid>>p[i].arrival_time>>p[i].burst_time;
        p[i].bt = p[i].burst_time;
    }
    sort(p,p+n,comp);
    cin>>timequanta;
    readyQ.push(0);
    int current_time=0;
    int completed = 1;
    vector<int>ans;
    while(!readyQ.empty()){
        int pno = readyQ.front();
        ans.push_back(p[pno].pid);
        readyQ.pop();
        if(p[pno].burst_time >=timequanta)
            current_time += timequanta;
        else
            current_time += p[pno].burst_time;
        if(p[pno].burst_time >= timequanta)
            p[pno].burst_time -= timequanta;
        else
            p[pno].burst_time = 0;

        p[pno].completion_time = current_time;
        while(1){
            if(completed<n && p[completed].arrival_time <= current_time){
                readyQ.push(completed);
                completed++;
            }
            else break;
        }
        if(p[pno].burst_time>0)readyQ.push(pno);
    }
    double avg_tat=0.0,avg_wt=0.0;
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].completion_time - p[i].arrival_time;
        p[i].wt = p[i].tat - p[i].bt;
        avg_tat += p[i].tat*1.0/n;
        avg_wt += p[i].wt*1.0/n;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<p[i].pid<<"\t"<<p[i].arrival_time<<"\t"<<p[i].bt<<"\t"<<p[i].completion_time<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<endl;
    }
    for (auto &&i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl<<avg_tat<<"\t"<<avg_wt;

}