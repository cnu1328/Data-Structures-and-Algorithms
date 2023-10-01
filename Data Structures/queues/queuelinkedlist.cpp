#include<iostream>

using namespace std;

struct node{
    int data;
    node *next;
    node(int val){
    	data = val;
    	next = NULL;
    }
};


struct queue{
    node *front;
    node *rear;
    
    queue(){
    	front = NULL;
    	rear = NULL;
    }
    

void push(int x){
    node *nn = new node(x);
    
    if(front == NULL){
    	front = nn;
    	rear = nn;
    }
    
    rear->next = nn;
    rear = nn; 
}

int pop(){
    if(front == NULL){
    	cout<<"Queue underflow"<<endl;
    	return -1;
    }
    
    node *del = front;
    
    int a = front->data;
    
    front = front->next;
    delete(del);
    
    return a;
    
}

int peek(){
    if(front == NULL){
    	cout<<"NO elements in Queue"<<endl;
    	return -1;
    }
  
    return front->data;
    
}

bool empty(){
    if(front == NULL)
    	return true;
    return false;
}
};	

int main(){
    queue q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    
}






