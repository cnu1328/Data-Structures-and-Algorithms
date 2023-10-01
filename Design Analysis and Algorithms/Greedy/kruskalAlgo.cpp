#include<bits/stdc++.h>

using namespace std;

int findminimum(vector<vector<int>>& adjMatrix, int &u, int &v) {
    int mini = INT_MAX;
    for(int i=0; i<adjMatrix.size(); i++) {
        for(int j=0; j<adjMatrix[i].size(); j++) {
            if(adjMatrix[i][j] < mini && adjMatrix[i][j] !=0) {
                mini = adjMatrix[i][j];
                u = i;
                v = j;
            }
        }
    }


    return mini;
}

int findparent(vector<int>& parent, int n, int child) {

    while(parent[child] != -1) {
        child = parent[child];
    }

    return child;
}

void kka(vector<vector<int>>& adjMatrix, int n) {
    vector<int> parent(n, -1);

    int u,v;
    for(int i=0; i<n-1; i++) {
        int mini = findminimum(adjMatrix, u, v);

        int pu = findparent(parent, n, u);
        int pv = findparent(parent, n, v);

        if(pu != pv) {
            parent[pv] = pu;
            cout<<u<<" -> "<<v<<" = "<<mini<<endl;
            adjMatrix[u][v] = 0;
            adjMatrix[v][u] = 0;
        }


    }
    return;
}

int main() {

    /*cout<<"Enter number number of rows and columns : "<<endl;
    int n;
    cin>>n;
    // (n, vector<int> (n,0));*/
    vector<vector<int>> adjMatrix {
                                    {0,2,0,6,0},
                                    {2,0,3,8,5},
                                    {0,3,0,0,7},
                                    {6,8,0,0,9},
                                    {0,5,7,9,0}
                                  };

    //cout<<"Enter adjacent matrix values : "<<endl;

    /*
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>adjMatrix[i][j];
        }
    }
    */

    kka(adjMatrix, adjMatrix.size());

}
