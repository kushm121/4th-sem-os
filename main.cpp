#include <iostream>
using namespace std;

int main(){
    int num_proc, num_res;
    cout << "enter number of processes: ";
    cin >> num_proc;
    cout << "enter number of resources: ";
    cin >> num_res;
    int allocate[num_proc][num_res], max[num_proc][num_res], need[num_proc][num_res];
    int available[num_res];
    int finish[5] = {0};
    int safe_sequence[num_proc];
    int index = 0;

    //allocated matrix
    for (int i=0; i<num_proc; i++){
        for (int j=0; j<num_res; j++){
            cout << "enter allocated for process" << i << " resource" << j << ": ";
            cin >> allocate[i][j];
        }
    }

    //max matrix
    for (int i=0; i<num_proc; i++){
        for (int j=0; j<num_res; j++){
            cout << "enter max for process" << i << " resource" << j << ": ";
            cin >> max[i][j];
        }
    }

    //available resources
    for (int i=0; i<num_res; i++){
        cout << "enter available for resource" << i << ": ";
        cin >> available[i];
    }

    //need matrix
    for (int i=0; i<num_proc; i++){
        for (int j=0; j<num_res; j++){
            need[i][j] = max[i][j] - allocate[i][j];
        }
    }

    for (int i=0; i<num_proc; i++){
        for (int j=0; j<num_proc; j++){
            if (finish[j] == 0){ //unfinished process
                bool flag = true;
                for (int k=0; k<num_res; k++){
                    if (need[j][k] > available[k]){ //not enough resources
                        flag = false;
                        break;
                    }
                }

                if (flag == true){
                    safe_sequence[index++] = j; //safe sequence generated
                    for (int x=0; x<num_res; x++){
                        available[x] += allocate[j][x]; //allocating resources
                    }
                    finish[j] = 1; //process finished
                }
            }
        }
    }

    cout << "safe sequence: \n";
    int l = sizeof(safe_sequence)/ sizeof(int);
    for (int i=0; i<l; i++){
        cout << safe_sequence[i] << " ";
    }
}