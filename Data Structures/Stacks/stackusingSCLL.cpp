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
    	nn->next = nn;
    	return nn;
    	
    }
    node *temp = top;
    while(temp->next!=top)
    	temp = temp->next;
    temp->next = nn;
    nn->next = top;
    return nn;
}

void display(node *top){
    
    
    if(top==NULL){
    	cout<<"NO stack present"<<endl;
    	return;
    }
    if(top->next == top){
    	cout<<top->data<<endl;
    	return;
    }
    node *temp = top;
    int i=0;
    do{
    	cout<<temp->data<<",";
    	i++;
    	temp = temp->next;
    }while(i<=10);//temp!=top); To check Circular or not
    cout<<endl;
    
    return;
  
}

int pop(node *&top){
    if(top == NULL){
    	cout<<"Stack is Under Flow"<<endl;
    	return -1;
    }
    if(top->next == top){
    	int x = top->data;
    	top = NULL;
    	return x;
    }
    int x = top->data;
    node *temp = top,*temp1 = top;
    
    while(temp->next!=top){
    	temp = temp->next;
    }
    top = top->next;
    temp->next = top;
    
    delete(temp1);
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
    cout<<pop(top)<<endl;
    cout<<pop(top)<<endl;
    cout<<pop(top)<<endl;
    cout<<pop(top)<<endl;
    cout<<pop(top)<<endl;
    
    cout<<"Top Element of the Stack : "<<endl;
    cout<<peek(top)<<endl;
    
    cout<<"Total elements in stack : "<<endl;
    display(top);
    
    
    
    
}
