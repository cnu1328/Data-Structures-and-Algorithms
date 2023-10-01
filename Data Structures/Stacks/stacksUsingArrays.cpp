//C++ program to implement basic stack operations using array

#include<iostream>
#include<stack>

using namespace std;

#define MAX 5

class Stack{
    int top;

public:
	int a[MAX]; //maximum size of stack

	Stack() {
	    top = -1;
    }
	void push(int x);
	int pop();
	int peek();
	bool isEmpty();
	void display();
};

void Stack::push(int x){
    if(top >= (MAX-1)){
    	cout<<"Stack Overflow"<<endl;
    	return;
    }
    a[++top] = x;
    return;
}

int Stack::pop(){
    if(top<0){
	cout<<"Stack Underflow"<<endl;
	return 0;
    }
    int x= a[top--];
    return x;
}


int Stack::peek(){
    if(top<0){
    	cout<<"Stack is Empty"<<endl;
    	return 0;
    }
    if(top>=(MAX-1)){
        cout<<"Stack is Overflow"<<endl;
        return -1;
    }

    int x = a[top];
    return x;
}

bool Stack::isEmpty(){
    return (top<0);
}

void Stack::display(){
    int x = top;
    if(top<0)
    	cout<<"Stack is empty"<<endl;
    else{
    	for(int i=x;i>=0;i--)
    	    cout<<a[i]<<" ";
    }
}

int main(){
    class Stack s;
    int n,x;
    cout<<"Enter number of elements you enter : ";
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>x;
    	s.push(x);
    }
    cout<<s.pop()<<" Popped from Stack"<<endl;
    cout<<endl;
    cout<<"Top element is : "<<s.peek()<<endl;
    cout<<endl;
    s.display();
    /*cout<<"Elements present in stack : "<<endl;
    while(!s.isEmpty()){
    	cout<<s.peek()<<" ";
    	s.pop();
    }

    cout<<endl<<"Top element is : "<<s.peek()<<endl;
    cout<<endl;
    return 0;
    */
}



//Apna Collage











