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

Node *delete_tail(Node *head)
{
    if(head==NULL)return NULL;
    /*if(head->next==NULL){
        delete head;
        return NULL;
    }*/
    Node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    delete (temp);
    //temp->next=NULL;
    return head;
}

int main()
{
     Node *head = new Node(1);
   
     head = delete_tail(head);
     cout << endl;
     display(head);
     
}
