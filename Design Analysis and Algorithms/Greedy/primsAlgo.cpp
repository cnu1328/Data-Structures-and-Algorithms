#include<bits/stdc++.h>

using namespace std;

void primsMst(vector<vector<int>>& adjMatrix, int n) {
    vector<int> visited(n,0);

    visited[0] = 1;

    for(int l = 0; l<n-1; l++) {
        int mini = INT_MAX;
        int u,v;
        for(int i=0; i<n; i++) {
            if(visited[i] == 1) {
                for(int j=0; j<n; j++) {
                    if(visited[j] != 1 && adjMatrix[i][j] != 0) {
                        if(adjMatrix[i][j] < mini) {
                            mini = adjMatrix[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }


        }
        visited[v] = 1;
        cout<<u<<" -> "<<v<<" - "<<mini<<endl;

    }
}

int main() {

    cout<<"Enter number number of rows and columns : "<<endl;
    int m,n;
    cin>>m>>n;

    vector<vector<int>> adjMatrix(m, vector<int> (n,0));

    cout<<"Enter adjacent matrix values : "<<endl;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>adjMatrix[i][j];
        }
    }

    /*

    0 2 0 6 0
    2 0 3 8 5
    0 3 0 0 7
    6 8 0 0 9
    0 5 7 9 0


    0 -> 1 - 2
    1 -> 2 - 3
    1 -> 4 - 5
    0 -> 3 - 6

    */

    primsMst(adjMatrix, m);

}
