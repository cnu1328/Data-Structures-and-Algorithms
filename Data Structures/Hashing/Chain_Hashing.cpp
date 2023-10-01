#include<iostream>
#define size 11

using namespace std;



struct node{
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};

node *hashTable[size];

void initialize_hashtable(){
    for(int i=0;i<size;i++)
        hashTable[i]=NULL;
}

void insert(int val){
    node *nn = new node(val),*temp;
    int hash = nn->data%size;
    if(hashTable[hash]==NULL)
        hashTable[hash]=nn;
    else{
        temp = hashTable[hash];
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = nn;
    }
}

void search(int key){
    int hash = key%size;
    node *temp = hashTable[hash];
    while(temp!=NULL && temp->data!=key)
        temp = temp->next;
    if(temp == NULL)
        cout<<"Key Not Found"<<endl;
    else
        cout<<"Key Found"<<endl;
}

void del(int key){
    int hash = key%size;
    node *temp = hashTable[hash],*temp_prev;
    int flag = 0;
    while(temp!=NULL && temp->data !=key){
        temp_prev = temp;
        temp = temp->next;
        flag =1;
    }

    if(temp->data == key){
        if(flag ==0)
            hashTable[hash] = temp->next;
        else{
            temp_prev->next = temp->next;
        }
        delete(temp);
    }
    else
        cout<<"Key not found"<<endl;
}

void display(){
    cout<<endl<<"  HASHTABLE "<<endl;
    for(int i=0;i<size;i++){
        node *temp = hashTable[i];
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
}

int main(){
    int a[] = {56,57,15,2,3,6,47,27,90,45677,211};
    for(int i=0;i<size;i++){
        insert(a[i]);
    }
    display();
    search(222);
    del(90);
    display();
    return 0;
}
