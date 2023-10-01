#include<bits/stdc++.h>

using namespace std;

vector<int> weights, arr(10, 0);
int weight;

void solution(int n) {
    int sum = 0;

    for(int i=0; i<n; i++) {
        if(arr[i] == 1) {
            sum += weights[i];
        }
    }
    if(sum == weight) {
        for(int i=0; i<n; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

void ss(int index, int n) {
    if(index == n) {
        solution(n);
        return;
    }

    else {
        for(int i=0; i<2; i++) {
            arr[index] = i;
            ss(index + 1, n);
        }
    }
}

int main() {
    weight = 10;
    weights = {5, 5, 5 ,5, 5};
    ss(0, 5);
}
