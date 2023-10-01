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



node *insertathead(node *head, int val){
    if(head == NULL){
    	return new node(val);
    }
    else{

    	node *temp = head;
    	node *nn = new node(val);
    	nn->next = head;
    	while(temp->next != head)
    	    temp = temp->next;
    	head = nn;
    	temp->next = head;

    }
    return head;
}

node *insertatend(node *head, int val){
    if(head == NULL){

    	return new node(val);
    }
    else{

    	node *temp = head;
    	node *nn = new node(val);
    	nn->next = head;
    	while(temp->next != head)
    	    temp = temp->next;
    	temp->next = nn;

    }
    return head;

}

node *insertatpos(node *head,int pos,int val){
    node *temp,*nn;
    nn = new node(val);
    temp = head;
    if(pos == 1){
    	/*nn->next = head;
    	while(temp->next != head)
    	    temp = temp->next;
    	temp->next = nn;
    	return nn;*/
    	return insertathead(head,val);
    }

    for(int i=1;i<=pos-2 && temp->next!=head;i++)
    	temp = temp->next;
    if(temp->next==head){
    	cout<<"Position "<<pos<<" does not exist in List"<<endl;
    	return head;
    }
    nn->next = temp->next;
    temp->next = nn;
    return head;
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

    cout<<"Insertion of singly circular linked list at head : "<<endl;
    head = insertathead(head,60);
    display(head);
    cout<<endl<<endl;

    cout<<"Insertion of singly circular linked list at end : "<<endl;
    head = insertatend(head,70);
    display(head);
    cout<<endl<<endl;

    cout<<"Insertion of singly circular linked list at pos : "<<endl;
    head = insertatpos(head,1,80);
    display(head);
    cout<<endl<<endl;
}