#include <iostream>
#include <unordered_set>

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
int search(Node * head, int val){
    int pos=1;
    Node *temp=head;
    while(temp!=NULL){
        if(temp->data==val)
            return pos;
        else{
            pos++;
            temp=temp->next;
        }
    }
    return -1;
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

int detectloop(Node *head){
    if(head == NULL)
	cout<<"No linked list is present"<<endl;
    else{
    	unordered_set<Node*>s;
    	while(head!=NULL){
    	    if(s.find(head) !=s.end())
    	    	return 1;
    	    s.insert(head);

    	    head = head->next;
    	}

    	return 0;
    }
}


Node *rev(Node *head){
    if(head == NULL)
    	return NULL;
    if(head->next == NULL)
    	return head;
    Node *curr = head;
    Node *prev = NULL,*next1 = NULL;
    while(curr !=NULL){
    	next1 = curr->next;
    	curr->next = prev;
    	prev = curr;
    	curr = next1;
    }
    return prev;
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
     cout<<"insert at head"<<endl;
     head = insert_head(head,5);
     cout << endl;
     display(head);
     cout<<endl<<"insert at tail"<<endl;
     head = insert_tail(head,10);
     cout << endl;
     display(head);
     head = delete_head(head);
     cout << endl;
     display(head);
     head = delete_tail(head);
     cout << endl;
     display(head);

     head = insert_pos(head,2,1);
     display(head);
     cout << endl;

     cout << endl;
     cout<<"found at position "<<search(head, 30);
     cout << endl << endl;

     head = insertaf(head,1,7);
     display(head);
     cout<<endl<<endl;

     head = delatpos(head,4);
     display(head);

     cout<<"Middle Node"<<endl;
     middle(head);
     display(head);
     cout<<endl<<endl;

     nthend(head,3);
     cout<<endl<<endl;

     count(head,1);
     cout<<endl;

     cout<<"REVERSED LIST"<<endl;
     head = rev(head);
     display(head);
     cout<<endl;

     int f = detectloop(head);
    if(f==1)
    	cout<<"True"<<endl;
    else
    	cout<<"False"<<endl;


     int result = palin(head);
     if(result == true)
     	cout<<"Palindrome"<<endl;
     else
     	cout<<"NOt a palindrome"<<endl;
    return 0;

    cout<<endl<<"Deleted at data value linked list "<<endl;
    head = delatdata(head,3);
    display(head);
    cout<<endl;


}

