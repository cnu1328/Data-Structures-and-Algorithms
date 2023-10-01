#include<iostream>

using namespace std;

#define n 20

class queue{
    
    int *arr;
    int front;
    int rear;
    
    public:
    	queue(){
    	    arr = new int[n];
    	    front = -1;
    	    rear = -1;
    	}
    	
    	void enqueue(int x){
    	    if(rear == n-1){
    	    	cout<<"Queue overflow"<<endl;
    	    	return;
    	    }
    	    
    	    arr[++rear] =x;
    	    
    	    if(front == -1)
    	    	front++; 
    	    
    	}
    	
    	void dequeue(){
    	    if(front == -1 || front>rear){
    	    	cout<<"NO elements present in Queue"<<endl;
    	    	return;
    	    }
    	    
    	    front++;
    	}
    	
    	int peek(){
    	    if(front == -1 || front>rear){
    	    	cout<<"NO elements present in Queue"<<endl;
    	    	return 0;
    	    }
    	    
    	    return arr[front];
    	}
    	
    	bool empty(){
    	    if(front == -1 || front>rear){
    	    	return true;
    	    }
    	    return false;
    	}
};

int main(){
    
    class queue q;
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    
    cout<<q.peek()<<endl;
    q.dequeue();
    
    cout<<q.peek()<<endl;
    q.dequeue();
    
    cout<<q.peek()<<endl;
    q.dequeue();
    
    cout<<q.peek()<<endl;
    q.dequeue();
    
    cout<<q.peek()<<endl;
    q.dequeue();
    
    cout<<q.peek()<<endl;
    
    

}
