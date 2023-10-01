
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> v(10, 0);
int miniSum = INT_MAX;

void solution(int n) {
    int sum = 0;
    for(int i=0; i<n-1; i++) {
        sum += adj[v[i]][v[i+1]];
    }

    sum += adj[v[n-1]][v[0]];

    miniSum = min(sum, miniSum);
}

bool issafe(int index, int pos) {
    if(index == pos-1) {
        for(int j=1; j<index; j++) {
            if(v[j] == pos || adj[v[index-1]][pos] == 0 || adj[pos][v[0]] == 0)
                return false;
        }

        return true;
    }
    else {
        for(int j = 1; j<index; j++) {
        if(v[j] == pos || adj[v[index-1]][pos] == 0)
            return false;
        }

        return true;
    }
}

void hamit(int index, int n) {
    if(index == n) {
        solution(n);
    }

    else {
        for(int i=1; i<n; i++) {
            if(issafe(index, i)) {
                v[index] = i;
                hamit(index+1, n);
            }
        }
    }
}


int main() {
    adj = {{0, 2, 3, 6},
           {2, 0, 5, 4},
           {3, 5, 0, 7},
           {6, 4, 7, 0}};
    v[0] = 0;
    hamit(1, adj.size());

    cout<<"Minimum Way is : "<<miniSum<<endl;
}
