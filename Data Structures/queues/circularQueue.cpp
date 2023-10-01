#include<iostream>

using namespace std;

class Queue{
    
    int front, rear;
    
    int size;
    int *arr;
    
public:
 	Queue(int s){
 	    front = -1;rear = -1;
 	    size = s;
 	    arr = new int[s];
 	}
 	
 	void enQueue(int value);
 	int deQueue();
 	int top();
 	void display();
};

void Queue::enQueue(int value){
    if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
    	cout<<"Queue is Full"<<endl;
    }
    else if(front==-1){
    	front = 0;rear =0;
    	arr[rear] = value;
    }
    else if(rear == size-1 && front !=0){
    	rear = 0;
    	arr[rear] = value;
    }
    else{
    	rear++;
    	arr[rear] = value;
    }
    
}
int Queue::deQueue(){
    if(front==-1){
    	cout<<"Queue is Empty"<<endl;
    	return -1;
    }
    int data = arr[front];
    if(rear == front){
    	front = rear = -1;
    }
    else if(front == size-1)
    	front = 0;
    else
    	front = front+1;
    return data;
}

int Queue::top(){
    if(front == -1){
    	cout<<"Queu is empty "<<endl;
    	return -1;
    }
    
    return arr[front];
}

void Queue::display(){
	if(front ==-1){
	    cout<<"Queue is emtpy"<<endl;
	    return;
	}
	if(rear>=front){
		for(int i=front;i<=rear;i++){
		 	cout<<arr[i]<<",";
		}	
	}
	else{
		for(int i=front;i<=size-1;i++)
			cout<<arr[i]<<",";
		for(int i=0;i<=rear;i++)
			cout<<arr[i]<<",";
	}

}

int main(){
    
    cout<<"enter number of Elements in Queue"<<endl;
    int num,ele;
    cin>>num;
    Queue q(num);
    
    while(num--){
    	cin>>ele;
    	q.enQueue(ele);
    }
    
    cout<<"Elements present in Queue"<<endl;
    q.display();
    cout<<endl;
    
    cout<<"Dequeued Element is "<<q.deQueue()<<endl;
    
    q.enQueue(3);
    
    q.display();
    cout<<endl;
    
    cout<<"Dequeued Element is "<<q.deQueue()<<endl;
    
    q.enQueue(3);
    
    q.display();
    cout<<endl;
    cout<<"top element in queue"<<q.top()<<endl;
    
}

