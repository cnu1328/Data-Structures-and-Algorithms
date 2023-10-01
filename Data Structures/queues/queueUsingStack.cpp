//Not working

#include<iostream>
#include<stack>

using namespace std;

struct queue{

    stack<int> a;
    stack<int> b;

    void push(int x){
    	a.push(x);

    }

    int pop(){
    	if(a.empty()){
    		cout<<"Queue is Empty"<<endl;
    		return -1;
    	}

    	if(b.empty()){
    	    while(!a.empty()){
    	    	b.push(a.top());
    	    	a.pop();
    	    }
    	}
    	int te = b.top();
    	b.pop();
    	return te;
    }


    /*int pop(){
    	if(a.empty()){
    		cout<<"Queue is empty"<<endl;
    		return -1;

    	}
    	int x = a.top();
    	a.pop();
    	if(a.empty()){
    	    return x;
    	}

    	int item = pop();

    	a.push(x);
    	return item;



    }*/

    int top(){
    	if(a.empty()){ //&& b.empty()){
    		cout<<"Queue is Empty"<<endl;
    		return -1;
    	}

    	return a.top();
    }

    bool empty(){
    	if(a.empty()){ //&& b.empty())
    		return true;
    	}
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
    q.push(7);

    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;




}



