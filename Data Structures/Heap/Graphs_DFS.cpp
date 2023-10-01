#include<iostream>
#define size 10

using namespace std;

struct node{
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};

int top = -1;
int s[size];


void insert(node *adjList[],int s,int d){
    node *dest = new  node(d);
    dest->next = adjList[s];
    adjList[s]= dest;

    node *src = new node(s);
    src->next = adjList[d];
    adjList[d]= src;
}

void push(int val){
    if(top>=size-1){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    s[++top]=val;
}

int pop(){
    if(top==-1){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    return s[top--];
}

void DFS(node *adjList[]){
    int visited[size];
    for(int i=0;i<size;i++)
        visited[i]=0;
    int sv = 0;
    push(sv);
    while(top>=0){
        int v = pop();
        if(visited[v]==0){
            cout<<v<<", ";
            visited[v]=1;
        }
        node *temp = adjList[v];
        while(temp){
            if(visited[temp->data]==0)
                push(temp->data);
            temp = temp->next;
        }

    }

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
    for(int i=0;i<size;i++)
        adjList[i]=NULL;

    insert(adjList,0,  1);
    insert(adjList,0,  2);
    insert(adjList,1,  3);
    insert(adjList,1,  4);
    insert(adjList,2,  5);
    insert(adjList,2,  6);
    insert(adjList,3, 7);
    insert(adjList,4,  7);
    insert(adjList,5,  7);
    insert(adjList,6,  7);

    display(adjList);
    DFS(adjList);

}
