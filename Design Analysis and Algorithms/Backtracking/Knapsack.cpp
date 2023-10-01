#include<bits/stdc++.h>

using namespace std;

vector<int> weights, values, arr(20, 0);
int weight, maxSum = INT_MIN;

void solution(int n) {

    int sum = 0;

    for(int i=0; i<n; i++) {
        if(arr[i] == 1) {
            sum += weights[i];
        }
    }


    if(sum <= weight) {
        int valueSum = 0;
        for(int i=0; i<n; i++) {
                if(arr[i] == 1)
                    valueSum += values[i];
        }

        maxSum = max(maxSum, valueSum);
    }


}
void ks(int index, int n) {
    if(index == n) {
        solution(n);
    }

    else {
        for(int i=0; i<2; i++) {
            arr[index] = i;
            ks(index + 1, n);
        }
    }
}



void pSolution(int n) {
    int sum = 0;

    for(int i=0; i<n; i++) {
        if(arr[i] == 1) {
            sum += weights[i];
        }
    }

    if(sum <= weight) {
        int valueSum = 0;
        for(int i=0; i<n; i++) {
                if(arr[i] == 1)
                    valueSum += values[i];
        }

        if(valueSum == maxSum) {
            for(int i=0; i<n; i++) {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }


    }
}

void print_ks(int index, int n) {
    if(index == n)  {
        pSolution(n);
    }

    else {
        for(int i=0; i<2; i++) {
            arr[index] = i;
            print_ks(index+1, n);
        }
    }
}



int main() {
    weights = {3, 4, 6, 7, 8};
    values = {26, 16, 21, 15, 48};

    weight = 9;

    ks(0, weights.size());
    cout<<maxSum<<endl;
    print_ks(0, weights.size());




}
