#include <iostream>

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

bool palin(Node *head){
    Node *temp = head;
    stack<int> s;
    while(temp!=NULL){
    	s.push(temp->data);
    	temp = temp->next;
    }

    temp = head;

    while(temp!=NULL){
    	int i = s.top();
    	s.pop();
    	if(temp->data != i)
    		return false;
    	temp = temp->next;
    }
    return true;


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

     int result = palin(head);
     if(result == true)
     	cout<<"Palindrome"<<endl;
     else
     	cout<<"NOt a palindrome"<<endl;
    return 0;
}

