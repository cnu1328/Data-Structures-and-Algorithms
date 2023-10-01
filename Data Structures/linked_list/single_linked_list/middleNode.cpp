#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *tail = NULL;

void display(Node *head)
{

    if(head == NULL){
	cout<<endl<<"NO Linked list is present"<<endl;
    }
    else{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    }
}



Node *insert_tail(Node *head, int val)
{
    Node *temp = head,*nn = new Node(val);
    if(head== NULL)
    	return nn;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = nn;
    return head;
}



void middle(Node *head){
    if(head == NULL)
    	return;
    Node *temp = head;
    int c=0;
    while(temp!=NULL){
    	temp = temp->next;
    	c++;
    }
    temp = head;
    if(c%2==0)
    {
    	cout<<"There are two middle Nodes are there"<<endl;
    	for(int i=1;i<(c/2) && temp!=NULL;i++){
    	    temp=temp->next;
    	}
    	Node *nn = new Node(0);
    	nn->next = temp->next;
    	temp->next = nn;

    }
    else{
    	cout<<"ONLy single middle Nodes"<<endl;
    	for(int i=0;i<(c/2) && temp!=NULL;i++){
    	    temp=temp->next;
    	}
    	cout<<temp->data<<endl;
    }
}

void nthend(Node *head,int val){
    if(head == NULL)
    	return;
    Node *temp = head;
    int c=0;
    while(temp!=NULL){
    	temp = temp->next;
    	c++;
    }
    cout<<c<<endl;
    if(val>c){
    	cout<<"Not True"<<endl;
    	return;
    }
    temp = head;

    for(int i=0;i<(c-val) && temp!=NULL;i++){
    	temp=temp->next;
    }
    cout<<temp->data<<endl;
}



int main()
{
     /*Node *head = new Node(1);
     head->next = new Node(1);
     head->next->next = new Node(1);
     tail = head->next->next->next = new Node(1);
     */
     Node *head = NULL;
     int n,a;
     cin>>n;

     for(int i=0;i<n;i++){
     	cin>>a;
     	head = insert_tail(head,a);
     }
     display(head);
     cout<<endl;

     cout<<"Middle Node"<<endl;
     middle(head);
     display(head);
     cout<<endl<<endl;

     nthend(head,3);
     cout<<endl<<endl;


}


