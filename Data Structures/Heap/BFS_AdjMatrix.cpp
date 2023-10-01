#include<iostream>

#define size 6

using namespace std;

//int graph[size][size];
int visited[size] ={0};
int q[100];
int front =0,rear=0;

void enq(int val){
    q[rear++]=val;
}

int dq(){
    return q[front++];
}

int main(){
    int graph[size][size] = {{0,1,1,0,0,1},
                        {1,0,1,0,0,1},
                        {1,1,0,1,1,0},
                        {0,0,1,0,0,1},
                        {0,0,1,0,0,0},
                        {0,1,0,1,0,0}};
    int sv =0;
    enq(sv);
    visited[sv]=1;
    while(front !=rear){
        int current = dq();
        cout<<current<<", ";
        for(int i=0;i<size;i++){
            if((graph[current][i]==1) && (visited[i]==0)){
                visited[i]=1;
                enq(i);
            }
        }
    }
}

