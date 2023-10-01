
#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
    node(int val){
    	data = val;
    	next = NULL;
    }
};

void display(node *head){
    if(head == NULL)
    	cout<<"NO LINKED IS PRESENT"<<endl;
    else{
    node *temp = head;
    /*while(temp->next!=head){
    	cout<<temp->data<<",";
    	temp = temp->next;
    }
    cout<<temp->data;
    }*/
    //int i=0;
    do{
    	cout<<temp->data<<",";
    	temp = temp->next;
    	//i++;
    }while(temp!=head);//i<=10);

    }
}


void search(node *head, int sval){
    if(head == NULL){
    	cout<<"NO LINKEDLIST IS Present"<<endl;
    }
    else{
    	int f=0,pos =1;
    	node *temp = head;
    	while(temp->next!=head){
    	    if(temp->data == sval){
    	    	f=1;
    	    	break;
    	    }
    	    else{
    	    	temp= temp->next;
    	    	pos++;
    	    }
    	}
    	if(f==1 || temp->data == sval)
    	    cout<<"Your Search is Found! at position : "<<pos<<endl;
    	else
    	    cout<<"YOUr SEarch is not found!"<<endl;
    }
}


int count(node *head){
    int res = 1;
    node *temp = head;
    while(temp->next !=head){
    	temp=temp->next;
    	res++;
    }
    return res;
}

int countinloop(node *head){
    node *slow = head,*fast = head;

    while(slow && fast && fast->next){
   	fast = fast->next->next;
   	slow = slow->next;
   	if(slow == fast)
   		return count(slow);
    }
    return 0;
}




int main(){
    node *head = NULL;
    head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    head->next->next->next->next = new node(50);
    head->next->next->next->next->next = head;
    cout<<"YOUR LINKED LIST Is : ";
    display(head);
    cout<<endl<<endl;

    cout<<"Searching element in circular singly linked list : "<<endl;
    search(head,9);
    cout<<endl<<endl;

    cout<<"Count in loop : ";
    cout<<countinloop(head)<<endl;
    cout<<endl;



}
