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

node *insertattail(node *head, int val){
    node *nn = new node(val);
    if(head == NULL)
    	return nn;
    node *temp = head;
    while(temp->next!=NULL)
	temp = temp->next;
    temp->next = nn;
    nn->prev = temp;
    return head;


}


node *insertatpos(node *head, int val, int pos){

    node *nn = new node(val);
    if(head == NULL)
    	return nn;
    if(pos == 1){
    	nn->next = head;
    	head->prev = nn;
    	return nn;
    }
    node *temp = head;
    for(int i=0;i<pos-2 && temp!=NULL; i++){
       temp= temp->next;

    }
    if(temp == NULL){
    	cout<<"Position value should be less than the number of data in liked list"<<endl;

    	return head;
    }
    nn->next = temp->next;
    node *temp1 = temp->next->next;
    temp1->prev = nn;
    temp->next = nn;
    nn->prev = temp;


    return head;
};

node *insertdata(node *head,int ndata, int nndata){

    if(head == NULL){
       cout<<"NO linked list is present"<<endl;
       return head;

    }


    node *temp = head;
    while(temp!=NULL){
    	if(temp->data == ndata){
    	    temp->data = nndata;

    	    break;
    	}
    	temp = temp->next;
    }
    return head;

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

    cout<<"Node inserted at head of doubly linked list : "<<endl;
    head = insertathead(head, 40);
    display(head);
    cout<<endl<<endl;

    cout<<"Node inserted at tail of doubly linked list : "<<endl;
    head = insertattail(head, 60);
    display(head);
    cout<<endl<<endl;

    cout<<"Node inserted at position of doubly linked list : "<<endl;
    head = insertatpos(head, 70, 1);
    display(head);
    cout<<endl<<endl;

   

    cout<<"Node data value is replaced of doubly linked list is : "<<endl;
    head = insertdata(head, 20, 90);
    display(head);
    cout<<endl<<endl;


}