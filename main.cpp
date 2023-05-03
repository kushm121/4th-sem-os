#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[8] = { 176, 79, 34, 60, 92, 11, 41, 114 };
    int head = 50;
    int n = 8;
    int index;
    int min;
    int distance = 0;
    int visited[8] = {0};

    for (int i=0; i<n; i++){
        index = 0;
        min = INT_MAX;
        for (int j=0; j<n; j++){
                if (visited[j] == 0 && abs(head - arr[j]) < min){
                    index = j;
                    min = abs(head - arr[j]);
                }
        }
        cout << arr[index] << " ";
        visited[index] = 1;
        head = arr[index];
        distance += min;
    }

    cout << "\n"<< distance;
}