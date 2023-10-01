#include<iostream>

using namespace std;

struct node{
    node *prev;
    int data;
    node *next;
    node(int x){
    	data = x;
    	prev = next = NULL;
    }
};

struct node *tail = NULL;

node *push(node *top, int val){
    node *nn = new node(val);
    if(top == NULL){
    	tail = nn;
    	return nn;
    }
    nn->next = top;
    top->prev = nn;
    
    return nn;
    
    
    
}

void display(node *top){
    if(top== NULL){
    	cout<<"NO Stack"<<endl;
    	return;
    }
    node *temp = top;
    while(temp!=NULL){
    	cout<<temp->data<<",";
    	temp = temp->next;
    }
    
    return;
    
}

void displaly(node *tail){
    if(tail == NULL){
    	cout<<"NO Stack Present"<<endl;
    	return;
    }
    node *temp = tail;
    while(temp!=NULL){
    	cout<<temp->data<<",";
    	temp = temp->prev;
    }
    
}

int pop(node *&top){
    if(top == NULL){
    	cout<<"Stack Under flow"<<endl;
    	return -1;
    }
    if(top->next == NULL){
    	int x = top->data;
    	top =tail =  NULL;
    	return x;
    }
    node *temp= top;
    int x = top->data;
    top = top->next;
    top->prev = NULL;
    delete(temp)
    return x;

}

int peek(node *top){
    if(top == NULL){
    	cout<<"NO Stack ";
    	return -1;
    }
    return top->data;
}

int main(){
    
    node *top = NULL;
    cout<<"Enter number of Nodes : "<<endl;
    int n,a;
    cin>>n;
    while(n--){
    	cin>>a;
    	top = push(top,a);
    }
    cout<<"All elements Present in Stack"<<endl;
    display(top);
    
    cout<<endl<<"All elements Present in Stack"<<endl;
    displaly(tail);
    cout<<endl;
    
    cout<<"Poped element from Stack"<<endl;
    cout<<pop(top)<<endl;
    cout<<"All elements Present in Stack"<<endl;
    display(top);
    cout<<endl;
    
    cout<<"Top element of the list"<<endl;
    cout<<peek(top)<<endl;
    
    cout<<"Poped element from Stack"<<endl;
    cout<<pop(top)<<endl;
    cout<<"All elements Present in Stack"<<endl;
    display(top);
    cout<<endl;
    
    cout<<"Poped element from Stack"<<endl;
    cout<<pop(top)<<endl;
    cout<<"All elements Present in Stack"<<endl;
    display(top);
    cout<<endl;
    
    cout<<"Poped element from Stack"<<endl;
    cout<<pop(top)<<endl;
    cout<<"All elements Present in Stack"<<endl;
    display(top);
    cout<<endl;
    
    cout<<"Top element of the list"<<endl;
    cout<<peek(top)<<endl;
    
    cout<<"Poped element from Stack"<<endl;
    cout<<pop(top)<<endl;
    cout<<"All elements Present in Stack"<<endl;
    display(top);
    cout<<endl;
    
    cout<<"Top element of the list"<<endl;
    cout<<peek(top)<<endl;
}
