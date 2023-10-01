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

node *deleteathead(node *head){
    if(head == NULL){
    	cout<<"NO Linked list is present!"<<endl;
    	return NULL;
    }
    node *temp = head;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    delete(temp);
    return head;
}

node *delatend(node *head){
    if(head == NULL){
    	cout<<"NO Linked list is present!"<<endl;
    	return NULL;
    }
    node *temp = tail;
    head->prev = tail->prev;
    tail = tail->prev;
    tail->next = head;
    delete(temp);
    return head;
    
    
}

node *delatpos(node *head, int pos){
    if(head == NULL){
    	cout<<"NO Linked list is present!"<<endl;
    	return NULL;
    }
    node *temp = head;
    if(pos == 1){
    	head = head->next;
    	head->prev = tail;
    	tail->next = head;
    	delete(temp);
    	return head;
    }
    
    for(int i=0; i<pos-2 and temp->next !=tail->next; i++){
    	temp= temp->next;
    }
    if(temp->next == head){
       cout<<"Position "<<pos<<" should be less than number of nodes in linked list"<<endl;  
	return head;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete(temp);
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
    
    cout<<"deletion of Linked list at head : "<<endl;
    head = deleteathead(head);
    display(head);
    cout<<endl<<"Deletion of Linked list at head in reverse : "<<endl;
    displayt(tail);
    cout<<endl<<endl;
    
    cout<<"deletion of Linked list at end : "<<endl;
    head = delatend(head);
    display(head);
    cout<<endl<<"Deletion of Linked list at end in reverse : "<<endl;
    displayt(tail);
    cout<<endl<<endl;
    
    cout<<"deletion of Linked list at pos : "<<endl;
    head = delatpos(head,5);
    display(head);
    cout<<endl<<"Deletion of Linked list at pos in reverse : "<<endl;
    displayt(tail);
    cout<<endl<<endl;
 
}
