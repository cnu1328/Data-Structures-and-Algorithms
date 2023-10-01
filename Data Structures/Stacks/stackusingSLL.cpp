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

node *push(node *top,int val){
    
    node *nn = new node(val);
    
    if(top == NULL){
    	return nn;
    }
    nn->next = top;
    return nn;
}
void display(node *top){
    node *temp = top;
    if(top==NULL){
    	cout<<"NO stack present"<<endl;
    	return;
    }
    
    while(temp!=NULL){
    	cout<<temp->data<<",";
    	temp = temp->next;
    }
    cout<<endl;
    
    return;
  
}

int pop(node *&top){
    if(top == NULL){
    	cout<<"Stack is Under Flow"<<endl;
    	return -1;
    }
    int x = top->data;
    node *temp = top;
    top = top->next;
    delete(temp);
    return x;
}

int peek(node *top){
    if(top == NULL){
    	cout<<"No stack Present"<<endl;
    	return -1;
    }
    
    return top->data;
}

int main(){
    node *top = NULL;
    cout<<"Enter number of node you create : "<<endl;
    int n,a;
    cin>>n;
    while(n--){
    	cin>>a;
    	top = push(top,a);
    }
    cout<<"Total elements in stack : "<<endl;
    display(top);
    
    cout<<"Element POPed from Stack : "<<endl;
    cout<<pop(top)<<endl;
    
    cout<<"Total elements in stack : "<<endl;
    display(top);
    
    cout<<"Top Element of the Stack : "<<endl;
    cout<<peek(top)<<endl;
    
    cout<<"All Elements are poped from stack: "<<endl;
    cout<<pop(top)<<","<<pop(top)<<","<<pop(top)<<","<<pop(top)<<"," <<pop(top)<<endl;
    
    display(top);
    
}
