#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    int prio;
    node *next;
    node(int x,int p){
        data = x;
        prio = p;
        next = NULL;
    }
};

node *front = NULL;

void enqp(int val,int p){
    node *temp = front,*nn;
    nn = new node(val,p);
    if(front == NULL || p<front->prio){
        nn->next = front;
        front = nn;
    }

    else{
        while(temp->next!=NULL && temp->next->prio<=p)
            temp = temp->next;
        nn->next = temp->next;
        temp->next = nn;
    }
}

void dqp(){
    if(front == NULL)
        return;
    node *temp = front;
    front = front->next;
    free(temp);
}

void display(){
    node *temp = front;
    if(temp==NULL){
        cout<<"Queue is Emtpy"<<endl;
        return;
    }
    while(temp){
        cout<<temp->data<<", ";
        temp = temp->next;
    }

}

int top(){
    if(front==NULL)
        return -1;
    return front->data;
}

int main(){

    enqp(10,1);
    enqp(20,2);
    enqp(50,5);
    enqp(30,3);
    enqp(30,-1);

    display();
    dqp();
    cout<<top()<<endl;


}
