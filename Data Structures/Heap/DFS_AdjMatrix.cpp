#include<iostream>
#define size 6

using namespace std;

int graph[size][size];
int visited[size] = {0};

void DFS(int graph[size][size],int current){
    int j;
    cout<<current<<", ";
    visited[current]=1;
    for(j=0;j<size;j++){
        if((graph[current][j]==1)&&(visited[j]==0))
            DFS(graph,j);
    }
}

int main(){
    int graph[size][size] = {{0,1,1,0,0,1},
                        {1,0,1,0,0,1},
                        {1,1,0,1,1,0},
                        {0,0,1,0,0,1},
                        {0,0,1,0,0,0},
                        {0,1,0,1,0,0}};
    DFS(graph,0);
}
