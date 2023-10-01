#include<iostream>

using namespace std;


struct node{
    node *prev;
    int data;
    node *next;
    node(int  val){
    	data = val;
    	prev = next = NULL;
    }
};

struct node *tail = NULL;

void display(node *head){
    if(head == NULL){
    	cout<<"NO LINKED LIST IS PRESENT"<<endl;
    }
    else{
    node *temp = head;
    int i=0;
    do{
    	cout<<temp->data<<",";
    	temp= temp->next;
    	i++;
    }while(i<=10);
    cout<<endl;
   }
}

void displayt(node *tail){
    if(tail == NULL){
    	cout<<"NO LINKED LIST IS PRESENT"<<endl;
    }
    else{
    node *temp = tail;
    int i=0;
    do{
    	cout<<temp->data<<",";
    	temp= temp->prev;
    	i++;
    }while(i<=20);
    cout<<endl;
    }
}

node *insertathead(node *head, int val){
    if(head == NULL){
    	cout<<"NO Linked list is present!"<<endl;
    	return NULL;
    }
    node *temp = head,*nn;
    nn = new node(val);
    nn->next = head;
    head->prev = nn;
    nn->prev = tail;
    head = nn;
    tail->next = head;
    return head;
}

node *insertatend(node *head, int val){
    if(head == NULL){
    	cout<<"NO Linked list is present!"<<endl;
    	return NULL;
    }
    node *nn = new node(val);
    tail->next = nn;
    tail->next->prev = tail;
    tail = nn;
    tail->next = head;
    head->prev = nn;
    return head;
    
    
}

node *insertatpos(node *head, int val , int pos){
    if(head == NULL){
    	cout<<"NO Linked list is present!"<<endl;
    	return NULL;
    }
    node *nn = new node(val);
    if(pos == 1){
    	nn->next = head;
    	nn->prev = tail;
    	tail->next = nn;
    	head->prev = nn;
    	return nn;
    }
    node *temp = head;
    for(int i=0;i<pos-2 and temp->next!=tail->next;i++)
    	temp = temp->next;
    if(temp->next==head){
	cout<<"Position "<<pos<<" should be less than number of nodes in linked list"<<endl;  
	return head;
    }
    nn->next = temp->next;
    nn->next->prev = nn;
    temp->next = nn;
    nn->prev = temp;
    return head;
}



int main(){
    node *head = NULL;
    head = new node(10);
    node *temp1 = new node(20);
    head->next = temp1;
    temp1->prev = head;
    
    node *temp2 = new node(30);
    temp1->next = temp2;
    temp2->prev = temp1;
    
    node *temp3 = new node(40);
    temp2->next = temp3;
    temp3->prev = temp2;
    head->prev = temp3;
    temp3->next = head;
    tail = temp3;
    
    cout<<"YOUR LIKED LIST is : "<<endl;
    display(head);
    cout<<endl<<endl;
    
    cout<<"YOUR LIKED LIST in reverse is : "<<endl;
    displayt(tail);
    cout<<endl<<endl;
    
    cout<<"Insertion of Linked list at head : "<<endl;
    head = insertathead(head, 50);
    display(head);
    cout<<endl<<"Insertion of Linked list at head in reverse : "<<endl;
    displayt(tail);
    cout<<endl<<endl;
     
     
    cout<<"Insertion of Linked list at tail : "<<endl;
    head = insertatend(head, 60);
    display(head);
    cout<<endl<<"Insertion of Linked list at tail in reverse : "<<endl;
    displayt(tail);
    cout<<endl<<endl;
    
    cout<<"Insertion of Linked list at position : "<<endl;
    head = insertatpos(head, 80, 5);
    display(head);
    cout<<endl<<"Insertion of Linked list at pos in reverse : "<<endl;
    displayt(tail);
    cout<<endl<<endl;

}