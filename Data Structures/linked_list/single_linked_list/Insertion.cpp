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


Node *insert_head(Node *head, int val)
{

    Node *nn = new Node(val);
    if(head == NULL)
    	return nn;
    nn->next = head;
    head = nn;
    return head;
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


Node *insert_pos(Node *head, int pos, int x)
{
    Node *nn = new Node(x);
    if(head == NULL){
        cout<<"You don't have linked list to insert a data on certain position value"<<endl;
        cout<<"If you want to create new one please enter y or else n"<<endl;
        char c;
        cin>>c;
        if(c=='y' || c=='Y')
            return nn;
        else if(c=='n' || c=='N')
            return NULL;
        else{
            cout<<"Invalid Character"<<endl;
        }
    }
    if(pos == 1)
    {
        nn->next = head;
        return nn;
    }
    Node *temp = head;
    for(int i = 1; i <= pos-2 && temp != NULL; i++)
        temp= temp->next;
    if(temp == NULL){
    	cout <<"position "<< pos << " does not exist in List";
    	return head;
    }
    nn->next = temp->next;
    temp->next = nn;
    return head;
}

Node *insertaf(Node *head,int data, int val){
    Node *temp = head,*nn = new Node(val);
    if(head == NULL){
    	return NULL;
    }
    if(head->data  == data){
    	nn->next = head;
    	return nn;
    }

    while(temp->data!=data and temp->next!=NULL){
    	temp = temp->next;
    	cout<<"TRUE"<<endl;
    }

    if(temp->data != data){
    	cout<<"Data value Not found to insert"<<endl;
    	return head;
    }
    nn->next = temp->next;
    temp->next = nn;
    return head;
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

     cout<<"insert at head"<<endl;
     head = insert_head(head,5);
     cout << endl;

     display(head);

     cout<<endl<<"insert at tail"<<endl;
     head = insert_tail(head,10);
     cout << endl;

     display(head);

     head = insert_pos(head,2,1);
     display(head);
     cout << endl;


     head = insertaf(head,1,7);
     display(head);
     cout<<endl<<endl;


}

















