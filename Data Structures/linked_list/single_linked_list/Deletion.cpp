#include<stack>
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



Node *delete_head(Node *head)
{
    if(head == NULL)
    	return NULL;
    Node *temp = head;
    head = head->next;
    delete(temp);
    return head;
}

Node *delete_tail(Node *head)
{
    if(head==NULL)return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node *temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;
    delete (temp->next);
    temp->next=NULL;
    return head;
}



Node *delatdata(Node *head,int dat){
    if(head== NULL)
    	return NULL;
    if(head->next == NULL){
    	if(head->data == dat){
    	delete(head);
    	return NULL;
    	}
    	return head;
    }

    Node *temp = head;
    while(temp->next !=NULL){
    	if(temp->next->data == dat)
    		break;
    	temp=temp->next;
    }
    if(temp==NULL){
    	cout<<"NO given data is present in Linked list to delete"<<endl;
    	return head;
    }
    Node *temp1 = temp->next;
    temp->next = temp->next->next;
    return head;


}

Node *delatpos(Node *head, int pos){
    if(head==NULL)
    	return NULL;
    if(head->next==NULL)
    	return NULL;
    int c=0;
    Node *temp = head;
    while(temp!=NULL){
    	temp = temp->next;
    	c++;
    }
    temp = head;
    if(pos<=c){

    	for(int i=1;i<pos-1;i++){

    	    temp = temp->next;
    	}
    	Node *next = temp->next->next;
    	delete(temp->next);
    	temp->next = next;

    }
    else{
    	cout<<"Position value should be less than the number of data in linked list"<<endl;
    	cout<<"No deletion Occured"<<endl;
    }
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


     head = delete_head(head);
     cout << endl;
     display(head);


     head = delete_tail(head);
     cout << endl;
     display(head);
    

     cout<<endl<<"Deleted at data value linked list "<<endl;
     head = delatdata(head,3);
     display(head);
     cout<<endl;

}

