#include <iostream>
using namespace std;

class process{
public:
    int pid;
    int psize;
    int allocated = NULL;
};

class hole{
public:
    int hid;
    int hsize;
};

void first_fit(process p[], hole h[], int proc_num, int hole_num){
    for (int i=1; i<=proc_num; i++){
        for (int j=1; j<=hole_num; j++){
            if (h[j].hsize >= p[i].psize){
                p[i].allocated = h[j].hid;
                h[j].hsize = h[j].hsize - p[i].psize;
                break;
            }
        }
    }
}

void best_fit(process p[], hole h[], int proc_num, int hole_num){
    int bf;
    for (int i=1; i<=proc_num; i++){
        bf = 0;
        for (int j=1; j<=hole_num; j++){
            if (h[j].hsize >= p[i].psize){
                if (bf == 0)
                    bf = j;
                else if (h[bf].hsize > h[j].hsize)
                    bf = j;
            }
        }
        if (bf != 0){
            p[i].allocated = bf;
            h[bf].hsize = h[bf].hsize - p[i].psize;
        }
    }
}

void worst_fit(process p[], hole h[], int proc_num, int hole_num){
    int wf;
    for (int i=1; i<=proc_num; i++){
        wf = 0;
        for (int j=1; j<=hole_num; j++){
            if (h[j].hsize >= p[i].psize){
                if (wf == 0)
                    wf = j;
                else if (h[wf].hsize < h[j].hsize)
                    wf = j;
            }
        }
        if (wf != 0){
            p[i].allocated = wf;
            h[wf].hsize = h[wf].hsize - p[i].psize;
        }
    }
}

int main(){
    int proc_num, hole_num;
    int ps, hs;
    cout << "enter number of processes:";
    cin >> proc_num;
    cout << "enter number of holes:";
    cin >> hole_num;

    process p[proc_num];
    hole h[hole_num];

    for (int i=1; i<=proc_num; i++){
        cout << "enter process size:";
        cin >> ps;
        p[i].pid = i;
        p[i].psize = ps;
    }

    for (int i=1; i<=hole_num; i++){
        cout << "enter hole size:";
        cin >> hs;
        h[i].hid = i;
        h[i].hsize = hs;
    }

    cout << "pid  allocated" << "\n";
    best_fit(p,h,proc_num,hole_num);
    for (int i=1; i<=proc_num; i++){
        cout << p[i].pid << "  " << p[i].allocated << "\n";
    }
}
