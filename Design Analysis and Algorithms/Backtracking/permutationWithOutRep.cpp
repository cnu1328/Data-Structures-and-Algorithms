#include<bits/stdc++.h>

using namespace std;

vector<int> v(5,0);

void solution(int n) {
    for(int k = 1; k<=n; k++) {
        cout<<v[k]<<", ";
    }
    cout<<endl;
}

bool isSafe(int index, int col) {

    for(int j = 1; j<index; j++) {
        if(v[j] == col)
            return false;
    }

    return true;

}

void permutation(int index, int n) {
    if(index == n+1) {
        solution(n);
    }

    else {
        for(int i=1; i<=n; i++) {
            if(isSafe(index, i)) {
                v[index] = i;
                permutation(index+1, n);
            }
        }
    }
}

int main() {
    int n = 3;
    permutation(1, n);
}
