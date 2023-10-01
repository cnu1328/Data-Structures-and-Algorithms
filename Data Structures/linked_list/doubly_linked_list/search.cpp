#include<iostream>

using namespace std;

struct node{

    node *prev;
    int data;
    node *next;
    node(int val){
    	data = val;
    	prev = next = NULL;
    }
};

void display(node *head){
    node *temp = head;
    while(temp!=NULL){
    	cout<<temp->data<<",";
    	temp = temp->next;
    }
    cout<<endl;
}

node *insertathead(node *head, int val){
    node *nn = new node(val);
    if(head == NULL)
    	return nn;
    nn->next = head;
    head->prev = nn;
    return nn;

}

void search(node *head, int val){
    if(head == NULL)
    	cout<<"NO Linked List is Present!"<<endl;
    node *temp = head;
    int f=0;
    while(temp!=NULL){
    	if(temp->data == val){
    	    f=1;
    	    break;
    	}
    	temp = temp->next;
    }
    if(f==1)
    	cout<<"Your search is FOUND"<<endl;
    else
    	cout<<"Your search is NOT FOUND!"<<endl;
}

int research(node *head, int val){
    if(head == NULL)
    	return false;
    if(head->data == val)
    	return true;
    return research(head->next,val);
}

int main(){
    node *head = NULL;
    /*head = new node(10);
    node *temp1 = new node(20);
    head->next = temp1;
    temp1->prev = head;
    node *temp2 = new node(30);
    temp1->next = temp2;
    temp2->prev = temp1;
    node *temp3 = new node(50);
    temp2->next = temp3;
    temp3->prev = temp2;*/
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        head = insertathead(head,a);
    }
    cout<<"Your Doubly Linked list is : "<<endl;
    display(head);
    cout<<endl<<endl;

    cout<<"Searching for an element : "<<endl;
    search(head,10);
    cout<<endl<<endl;

    cout<<"Searching for an element in recurssive approach : "<<endl;
    int b = research(head,70);
    if(b ==1)
    	cout<<"Your Search is Found!"<<endl;
    else
    	cout<<"Your Search is Not Found!"<<endl;
    cout<<endl<<endl;

    cout<<"Searching for an element : "<<endl;
    search(head,10);
    cout<<endl<<endl;

}
