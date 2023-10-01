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
    if(head==NULL)
        return nn;
    temp = head;
    while(temp->next != NULL)
    	temp = temp->next;
    temp->next = nn;
    return head;
}

Node* mergeTwoLists(Node* list1, Node* list2) {
        if(list1==NULL && list2==NULL)
            return NULL;
        if(list1==NULL && list2!=NULL)
            return list2;
        if(list1!=NULL && list2==NULL)
            return list1;
        Node *list3=NULL,*temp1,*temp2,*temp3;
        temp1 = list1;
        temp2 = list2;
        while(temp1!=NULL & temp2!=NULL){
            if(temp2->data > temp1->data){
                if(list3==NULL){
                    temp3 = list3=temp1;
                    temp1= temp1->next;
                }
                else{
                    temp3->next = temp1;
                    temp3 = temp1;
                    temp1 = temp1->next;
                }
            }
            else{
                if(list3 == NULL){
                    temp3 = list3 = temp2;
                    temp2=temp2->next;
                }
                else{
                    temp3->next = temp2;
                    temp3=temp2;
                    temp2 = temp2->next;
                }
            }
        }
        if(temp1!=NULL)
            temp3->next = temp1;
        if(temp2!=NULL)
            temp3->next = temp2;
        return list3;
}

int main(){
    Node *list1 = NULL,*list2= NULL;
    int t=3,a;
    while(t--){
        cin>>a;
        list1 = insertatend(list1,a);
    }
    t=3;
    while(t--){
        cin>>a;
        list2 = insertatend(list2,a);
    }


    display(list1);
    cout<<endl;
    display(list2);
    Node *list3 = NULL;
    list3 = mergeTwoLists(list1,list2);
    cout<<endl;
    display(list3);

}
