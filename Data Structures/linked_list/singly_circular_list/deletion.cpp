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




node *delathead(node *head){
    if(head == NULL){
    	cout<<"NO LINKEDLIST IS Present"<<endl;
    	return NULL;
    }

    node *temp = head,*temp1=head;

    while(temp->next!=head)
    	temp=temp->next;
    head = head->next;
    temp->next = head;
    delete(temp1);
    return head;
}

node *delatend(node *head){
    if(head == NULL){
    	cout<<"NO LINKEDLIST IS Present"<<endl;
    	return NULL;
    }

    node *temp = head;
    while(temp->next->next !=head)
    	temp = temp->next;
    node *temp1 = temp->next;
    temp->next = head;
    delete(temp1);
    return head;
}

node *delatpos(node *head, int pos){
    if(head == NULL){
    	cout<<"NO LINKEDLIST IS Present"<<endl;
    	return NULL;
    }
    if(pos == 1){
    	node *temp = head,*temp1= head;

    	while(temp->next!=head)
            temp = temp->next;
        head = head->next;
        temp->next = head;
        delete(temp1);
        return head;

    }

    node *temp = head;
    for(int i=0;i<pos-2 & temp->next !=head;i++)
    	temp = temp->next;
    if(temp->next==head){
    	cout<<"Position "<<pos<<" does not exist in List"<<endl;
    	return head;
    }
    node *temp1 = temp->next;
    temp->next = temp->next->next;
    delete(temp1);
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

    

    cout<<"Deletion of singly circular linked list at head : "<<endl;
    head = delathead(head);
    display(head);
    cout<<endl<<endl;

    cout<<"Deletion of singly circular linked list at tail : "<<endl;
    head = delatend(head);
    display(head);
    cout<<endl<<endl;

    cout<<"Deletion of singly circular linked list at pos : "<<endl;
    head = delatpos(head, 6);
    display(head);
    cout<<endl<<endl;

}