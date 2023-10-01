#include<iostream>
#define size 10
using namespace std;

struct node {
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};

int front = -1;
int rear = -1;
int Q[size];

void enq(int val){
    if(rear >= size-1){
        cout<<"Queue is Full"<<endl;
    }
    else if(front==-1 && rear==-1){
        front = rear = 0;
    }
    else
        rear++;
    Q[rear]=val;
    return;
}

int deq(){
    if(front==-1 || front>rear){
        cout<<"Queue is Underflow"<<endl;
        return 0;
    }

    return Q[front++];
}

void BFS(node *adjList[]){
    int visited[size];
    for(int i=0;i<size;i++)
        visited[i]=0;
    int sv = 0;
    enq(sv);
    visited[sv]=1;
    while(front<=rear){
        int v = deq();
        cout<<v<<", ";
        node *temp = adjList[v];
        while(temp){
            if(visited[temp->data]==0){
                enq(temp->data);
                visited[temp->data]=1;
            }
            temp = temp->next;
        }

    }

}


void insert(node *adjList[],int s,int d){
    node *dest = new node(d);
    dest->next = adjList[s];
    adjList[s] = dest;

    node *src = new node(s);
    src->next = adjList[d];
    adjList[d] = src;
}

void display(node *adjList[]){
    for(int i=0;i<size;i++){
        node *temp = adjList[i];
        cout<<i;
        while(temp){
            cout<<"->"<<temp->data;
            temp = temp->next;
        }
        cout<<"NULL"<<endl;

    }
}

int main(){
    node *adjList[size];
    for(int i=0;i<size;i++){
        adjList[i] = NULL;
    }
    insert(adjList,0,  1);
    insert(adjList,0,  2);
    insert(adjList,1,  3);
    insert(adjList,1,  4);
    insert(adjList,2,  5);
    insert(adjList,2,  6);
    insert(adjList,4,  7);
    insert(adjList,3,  7);
    insert(adjList,6,  7);
    insert(adjList,5,  7);
    display(adjList);
    BFS(adjList);
}
