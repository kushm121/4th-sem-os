#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkval(deque<int> q, int val){
    bool flag = false;
    int l = q.size();
    for (int i=0; i<l; i++){
        if (q[i] == val){
            flag = true;
            break;
        }
    }
    return flag;
}

int main(){
    deque<int> q;
    int n;
    cout << "enter number of pages:";
    cin >> n;
    int pages[n];
    int buffer;
    cout << "enter buffer:";
    cin >> buffer;
    int fault=0, hit=0;

    for (int i=0; i<n; i++){
        cout << "enter page:";
        cin >> pages[i];
    }

    for (int i=0; i<n; i++){
        if (!checkval(q,pages[i])){
            if (q.size() < buffer){
                q.push_back(pages[i]);
                fault++;
            }
            else{
                q.pop_front();
                q.push_back(pages[i]);
                fault++;
            }
        }
        else{
            hit++;
        }
    }

    cout << "faults: " << fault <<"\n";
    cout << "hits: " << hit << "\n";
}