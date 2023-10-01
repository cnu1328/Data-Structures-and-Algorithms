#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
    	data = x;
    	next = NULL;
    }
};

void display(Node *head){
    Node *temp = head;
    while(temp != NULL){
    	cout << temp->data << " ";
    	temp = temp->next;
    }
}

Node *insertatend(Node *head, int val){
    Node *nn = new Node(val),*temp;
    temp = head;
    while(temp->next != NULL)
    	temp = temp->next;
    temp->next = nn;
    return head;
}

Node* oddEvenList(Node* head) {
        if(head == NULL)
            return NULL;
        Node *temp = head,*head1=NULL,*head2=NULL;
        int c=1;
        while(temp!=NULL){
            if(c%2==0){
                if(head2==NULL){
                    head2 = temp;
                }
                Node *temp1 = head2;
                while(temp1->next){
                    temp1=temp1->next;
                }
                temp1->next = temp;
            }
            else{
                if(head1==NULL){
                    head1 = temp;
                }
                Node *temp1 = head1;
                while(temp1->next!=NULL){
                    temp1=temp1->next;
                }
                temp1->next = temp;
            }
            c++;
            temp=temp->next;
        }

        Node *temp1 = head1;
        while(temp1->next!=NULL)
            temp1=temp1->next;
        temp1->next = head2;
        return head1;
    }

int main(){
    Node *head;
    head = new Node(5);
    head->next = new Node(3);
    head->next->next = new Node(13);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(8);
    cout << "Linked list : \n";
    display(head);
    head = oddEvenList(head);
    display(head);

}
