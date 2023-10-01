#include<bits/stdc++.h>

using namespace std;

class stacknode{

public:
    int data;
    stacknode *next;

};

stacknode *createnode(int data){
    stacknode *nn = new stacknode();
    nn->data = data;
    nn->next = NULL;
    return nn;
}


void push(stacknode **top, int data){
    stacknode *nn = createnode(data);
    nn->next = *top;
    *top = nn;
}

int isEmpty(stacknode *top){
     if(top==-1)
	return false;
     else
     	return true;
}
int pop(stacknode **top){
    if(isEmpty(top))
    	return INT_MIN;
    stacknode *temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    delete(temp);
    
    return popped;
     
}


int peek(stacknode *top){
    if(isEmpty(top))
    	return INT_MIN;
    return top->data;
}



int main(){
    
    stacknode *top = NULL;
    int c,t;
    cout<<"Enter number of stacks elements : ";
    cin>>c;
    for(int i=0;i<c;i++){
    	cin>>t;
    	push(&top,t);
    }
    cout<<"Elements in stack : "<<endl;
    while(isEmpty(&top)){
    	cout<<peek(top)<<" ";
    	pop(&top);
    	
    }

}
