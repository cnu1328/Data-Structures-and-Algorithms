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


node *delathead(node *head){
    if(head == NULL){
    	cout<<"No Linked list is present!"<<endl;
    	return NULL;
    }
    node *temp = head;
    head = temp->next;
    head->prev = NULL;
    delete(temp);
    return head;

}

node *delattail(node *head){
    if(head == NULL){
    	cout<<"NO Linked list is present!"<<endl;
    	return NULL;
    }
    if(head->next == NULL)
    {
        delete(head);
        return NULL;
    }
    node *temp = head;
    while(temp->next!=NULL){
    	temp = temp->next;
    }
    temp->prev->next = NULL;
    delete(temp);

    return head;

}


node *delatpos(node *head, int pos){
    if(head == NULL){
    	cout<<"No linked list is present!"<<endl;
    	return NULL;
    }
    node *temp = head;
    if(pos == 1){
    	if(temp->next == NULL){
    	    delete(temp);
    	    return NULL;
    	}
    	else{
    	    head = temp->next;
    	    head->prev = NULL;
    	    delete(temp);
    	    return head;
    	}
    }
    for(int i=0;i<pos-1 and temp!=NULL;i++)
    	temp = temp->next;
    if(temp == NULL){
    	cout<<"To delete a node, The position should be less than the number of nodes in linked list"<<endl;
    	return head;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete(temp);
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

    cout<<"Deletion of Linked list at head : "<<endl;
    head = delathead(head);
    display(head);
    cout<<endl<<endl;

    cout<<"Deletion of Linked list at tail : "<<endl;
    head = delattail(head);
    display(head);
    cout<<endl<<endl;

    cout<<"Deletion of Linked list at a position : "<<endl;
    head = delatpos(head,3);
    display(head);
    cout<<endl<<endl;

}