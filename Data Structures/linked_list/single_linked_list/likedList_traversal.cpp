#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
    	data = x;
    	next = NULL;
};

void display(Node *head){
    Node *temp = head;
    while(temp != NULL){
    	cout << temp->data << " ";
    	temp = temp->next;
    }
}

Node *insertatfront(Node *head, int val){
    Node *nn = new Node(val);
    nn->next = head;
    head = nn;
    return head;
}

Node *insertatend(Node *head, int val){
    Node *nn = new Node(val),*temp;
    temp = head;
    while(temp->next != NULL)
    	temp = temp->next;
    temp->next = nn;
    return head;
}

Node *insertafterpos(Node *head,int pos,int val){
    Node *temp,*nn;
    nn = new Node(val);
    if(pos == 1){
    	nn->next = head;
    	return nn;
    }
    temp = head;
    for(int i=1;i<=pos-1 && temp!=NULL;i++)
    	temp = temp->next;
    if(temp==NULL){
    	cout<<"Position "<<pos<<"does not exist in List";
    	return head;
    }
    nn->next = temp->next;
    temp->next = nn;
    return head;
}

Node *insertdata(Node *head,int data,int ndata){
    Node *temp,*nn;
    //nn = new Node(ndata);
    temp = head;
    while(temp!=NULL){
    	
    	if(temp->data == data){
    	    temp->data = ndata;
    	    return head;
    	}
    	else
    	   temp = temp->next;
    }
    if(temp==NULL){
    	cout<<"Value Not found"<<endl;
    	return head;
    }
}



int search(Node *head, int val){
    Node *temp = head;
    int pos = 1,f=0;
    while(temp!=NULL){
    	if(val == temp->data){
    	    f=1;
    	    break;
    	}
    	else{
    	    temp = temp->next;
    	    pos++;
    	}
    		
    }
    if(f==1)
    	cout<<"Found at Position : "<<pos;
    else
    	cout<<"Not found";
    return 0;
}

int research(Node *head, int val){
    
    if(head == NULL)
    	return false;
    if(head->data == val)
    	return true;
    return research(head->next, val);
    	
}

Node *delatfront(Node *head){
    Node *temp = head;
    head=head->next;
    delete(temp);
    return head;
}

Node *delatend(Node *head){
    if(head==NULL)
    	return NULL;
    if(head->next == NULL){
    	delete(head);
    	return NULL;
    }
    Node *temp = head;
    while(temp->next->next != NULL){
    	temp = temp->next;
    }
    delete(temp->next);
    temp->next = NULL;
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

Node *reverse(Node *head){
   Node *next=NULL,*cur=head,*prev=NULL;
   while(cur!=NULL){
   	next = cur->next;
   	cur->next = prev;
   	prev = cur;
   	cur = next;
   	
   }
   return prev;
   
}


int main(){
    Node *head;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    cout << "Linked list : \n";
    display(head);
    
    cout<<endl<<endl;
    cout << "Insertion singly Linked list at front : \n";
    head = insertatfront(head, 4);
    display(head);
    cout<<endl<<endl;
    
    cout << "Insertion singly Linked list at end :\n";
    insertatend(head, 5);
    display(head);
    cout<<endl<<endl;
    
    
    cout << "Insertion singly Linked list after position :\n";
    head = insertafterpos(head,3,6);
    display(head);
    cout<<endl<<endl;
    
    cout << "Insertion singly Linked list at data value :\n";
    head = insertdata(head,10,5);
    display(head);
    cout<<endl<<endl;
    
    cout << "Searhing for data in linked list :\n";
    search(head,5);
    cout<<endl<<endl;
    
    cout<<"Searching for data through Recurssive apporach(1 for found and 0 for Not found) : "<<research(head,10)<<endl<<endl;
    
    
    cout << "Deletion of  singly Linked list at front \n";
    head = delatfront(head);
    display(head);
    cout<<endl<<endl;
    
    
    cout << "\nDeletion of  singly Linked list at end \n";
    head = delatend(head);
    display(head);
    cout<<endl<<endl;
    
    
    cout << "\nDeletion of  singly Linked list after position \n";
    head = delatpos(head,4);
    display(head);
    cout<<endl<<endl;
    
    cout << "Linked list : \n";
    display(head);
    cout<<endl<<endl;
    
    cout << "\nReverse of singly linked list \n";
    head = reverse(head);
    display(head);
    cout<<endl<<endl;
    
    
    cout<<endl<<endl;
    cout<<endl<<endl;
    cout<<endl<<endl;
    
    
    cout<<endl<<endl<<"delete LinkedList"<<endl<<endl<<"to get nth node in a linked list"<<endl<<"nth from end of a linked list"<<endl<<"print middle of given linked list"<<endl<<"and upto 25 "<<endl;
    
}
