#include<iostream>
#include<stack>

using namespace std;

struct node{

    int data;
    node *next;

    node(int x){
    	data = x;
    	next = NULL;
    }

};



void push(node *&rear,node *&front,int val){

    node *nn = new node(val);

    if(rear == NULL){
    	rear = front = nn;
    	return;
    }
    rear->next = nn;
    rear = nn;
    return;
}

void display(node *front){
    if(front==NULL){
    	cout<<"NO Queue present"<<endl;
    	return;
    }
    node *temp = front;
    while(temp!=NULL){
    	cout<<temp->data<<",";
    	temp = temp->next;
    }
    cout<<endl;

    return;

}

int pop(node *&front){
    if(front == NULL){
    	cout<<"Stack is Under Flow"<<endl;
    	return -1;
    }
    int x = front->data;
    node *temp = front;
    front = front->next;
    delete(temp);
    return x;
}

int peek(node *front){
    if(front == NULL){
    	cout<<"No stack Present"<<endl;
    	return -1;
    }

    return front->data;
}

bool isempty(node *front){
    if(front == NULL)
        return true;
    else
        return false;
}


int main(){
    node *rear = NULL,*front = NULL;
    cout<<"Enter number of node you create : "<<endl;
    int n,a;
    cin>>n;
    while(n--){
    	cin>>a;
    	push(rear,front,a);
    }
    cout<<"Total elements in stack : "<<endl;
    display(front);

    cout<<"Element POPed from Stack : "<<endl;
    cout<<pop(front)<<endl;
    cout<<"Total elements in stack : "<<endl;
    display(front);

    cout<<"Top Element of the Stack : "<<endl;
    cout<<peek(front)<<endl;

    cout<<"Element POPed from Stack : "<<endl;
    cout<<pop(front)<<endl;
    cout<<"Total elements in stack : "<<endl;
    display(front);

    cout<<"Top Element of the Stack : "<<endl;
    cout<<peek(front)<<endl;

    cout<<"Element POPed from Stack : "<<endl;
    cout<<pop(front)<<endl;
    cout<<"Total elements in stack : "<<endl;
    display(front);

    cout<<"Top Element of the Stack : "<<endl;
    cout<<peek(front)<<endl;

    cout<<"Element POPed from Stack : "<<endl;
    cout<<pop(front)<<endl;
    cout<<"Total elements in stack : "<<endl;
    display(front);

    cout<<"Top Element of the Stack : "<<endl;
    cout<<peek(front)<<endl;

    cout<<"Element POPed from Stack : "<<endl;
    cout<<pop(front)<<endl;
    cout<<"Total elements in stack : "<<endl;
    display(front);

    cout<<"Top Element of the Stack : "<<endl;
    cout<<peek(front)<<endl;

    cout<<isempty(front)<<endl;


}
