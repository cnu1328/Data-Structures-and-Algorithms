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

void push(int val){
    if(top>=size-1){
        cout<<"Stack overflow"<<endl;
        return;

    }

    s[++top]=val;


}

int pop(){
    if(top == -1){
        cout<<"Stack Under flow"<<endl;
        return -1;
    }
    return s[top--];
}

void DFS(node *adjList[]){
    int visited[size];
    for(int i=0;i<size;i++)
        visited[i]=0;
    int sv =0;
    push(sv);
    while(top>=0){
        int ele = pop();
        node *temp = adjList[ele];
        if(visited[ele]==0){
                cout<<ele<<", ";
                visited[ele]=1;
        }
        while(temp){

            if(visited[temp->data]==0){
                push(temp->data);
            }
            temp = temp->next;
        }
    }
}

void insert(node *adjList[],int des,int sr){
    node *dest = new node(des);
    dest->next = adjList[sr];
    adjList[sr]=dest;

    node *src = new node(sr);
    src->next = adjList[des];
    adjList[des] = src;
}



void display(node *adjList[]){
    for(int i=0;i<size;i++){
        cout<<i<<" -> ";
        node *temp = adjList[i];
        while(temp){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}

int main(){
    node* adjList[size];
    for(int i=0;i<size;i++)
        adjList[i]=NULL;
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

    DFS(adjList);
}





























/*#include<iostream>
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

int front = -1;
int rear = -1;
int Q[size];


void insert(node *adjList[],int des,int sr){
    node *dest = new node(des);
    dest->next = adjList[sr];
    adjList[sr] = dest;

    node *src = new node(sr);
    src->next = adjList[des];
    adjList[des]=src;

}

void enq(int sv){
    if(rear>=size-1){
        cout<<"Queue Overflow"<<endl;
        return;
    }
    else if(front==-1 && rear ==-1){
        front = rear = 0;
    }
    else
        rear++;
    Q[rear]=sv;
}

int deq(){
    if(front==-1 || front>rear){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    return Q[front++];


}



void BFS(node *adjList[]){
    int visited[size];
    for(int i=0;i<size;i++){
        visited[i]=0;
    }
    int sv=0;
    enq(sv);
    visited[sv]=1;
    while(front<=rear){
        int ele = deq();
        cout<<ele<<", ";
        node *temp = adjList[ele];
        while(temp){
            if(visited[temp->data]==0){
                enq(temp->data);
                visited[temp->data]=1;
            }
            temp=temp->next;
        }

    }
}


void display(node *adjList[]){
    for(int i=0;i<size;i++){
        node *temp = adjList[i];
        cout<<i<<" -> ";
        while(temp){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}




int main(){
    node *adjList[size];
    for(int i=0;i<size;i++){
        adjList[i]=NULL;
    }

    insert(adjList,0,  5);
    insert(adjList,0,  3);
    insert(adjList,5,  2);
    insert(adjList,5,  1);
    insert(adjList,3,  4);
    insert(adjList,3,  2);
    insert(adjList,2,  7);
    insert(adjList,1,  7);
    insert(adjList,4,  7);
    insert(adjList,1,  7);
    display(adjList);
    BFS(adjList);
}

*/
