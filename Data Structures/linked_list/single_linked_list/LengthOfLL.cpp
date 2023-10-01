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


void count(Node *head,int val){
    if(head == NULL)
    	return;
    if(head->next == NULL){
    	if(head->data == val){
    		cout<<1<<endl;
    		return;
    	}
    	cout<<0<<endl;
    }
    int c=0;
    Node *temp = head;
    while(temp!=NULL){
    	if(temp->data == val)
    		c++;
    	temp = temp->next;
    }
    cout<<c<<endl;
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


     count(head,1);
     cout<<endl;
}