#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> v(10, 0);

void solution(int n) {
    for(int k = 0; k<n; k++) {
        cout<<v[k]<<"->";
    }
    cout<<v[0]<<endl;
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
           {2, 0, 1, 3},
           {3, 1, 0, 2},
           {6, 3, 2, 0}};
    v[0] = 0;
    hamit(1, adj.size());
}
