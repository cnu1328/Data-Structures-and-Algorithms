#include<bits/stdc++.h>

using namespace std;

vector<int> bin(10, 0);

void solution(int n) {
    for(int i=0; i<n; i++) {
        cout<<bin[i]<<" ";
    }
    cout<<endl;
}

void binaryP(int index, int n) {
    if(index  == n) {
        solution(n);
        return;
    }
    else {
        for(int i=0; i<2; i++) {
            bin[index] = i;
            binaryP(index+1, n);
        }
    }
}

int main() {
    int n = 2;
    binaryP(0,n);
}
