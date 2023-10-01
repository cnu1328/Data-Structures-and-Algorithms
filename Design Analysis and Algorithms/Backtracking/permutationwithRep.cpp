#include<bits/stdc++.h>

using namespace std;

vector<int> v(5, 0);

void solution(int n) {
    for(int i=1; i<=n; i++) {
        cout<<v[i]<<", ";
    }
    cout<<endl;
}

void permutation(int index, int n) {
    if(index == n+1) {
        solution(n);
    }

    else {
        for(int i=1; i<=n; i++) {
            v[index] = i;
            permutation(index+1, n);
        }
    }
}

int main() {
    int n = 3;
    permutation(1, n);
}
