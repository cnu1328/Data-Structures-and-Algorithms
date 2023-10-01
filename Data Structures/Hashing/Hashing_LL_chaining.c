#include<stdio.h>
#include<stdlib.h>
#define size 11
struct node
{
    int data;
    struct node *next;
};
struct node *hashTable[size];

void initialize_hashtable(){
    for(int i=0; i<size;i++){
        hashTable[i]= NULL;
    }
}
struct node *createNode(){
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    if( nn == NULL )
        printf("Out of space!");
    else{
        printf("Enter element to be added in Hashtable\n");
        scanf("%d", &nn->data);
        nn->next = NULL;
    }
    return nn;
}


void insert() {
    struct node *nn, *temp;	/* declare two pointers new_node and temp */
    nn = createNode();
    int hash = nn->data % size;
    if (hashTable[hash] == NULL) {		/* when tashtable[hash] list is empty */
        hashTable[hash] = nn;  		/* add new node to  hashtable at  tashtable[hash] */
    }
    else {			/* when tashtable[hash] list is not empty  i.e collosion */
        temp=hashTable[hash];
        while (temp->next != NULL) {/* Traverse the list until temp is the last node */
            temp = temp->next;	/* The last node always points to NULL */
        }
        temp->next = nn;	/* Point the last node to the newly created node */
    }
}

void search(int key){
    int hash = key % size;
    struct node *temp = hashTable[hash] ;
    while(temp!=NULL && temp->data != key)
        temp=temp->next;
    if(temp == NULL)
         printf("key not found\n");
    else if(temp->data == key)
        printf("\n Key found \n");

    /*
    if(temp->data == key)
        printf("\n Key found \n");
    else
    	printf("key not found\n");
    */
}

void delete(int key){
    int hash = key % size;
    struct node *temp = hashTable[hash], *temp_prev;
    int flag = 0;
    while(temp!=NULL && temp->data != key){
        temp_prev = temp;
         temp=temp->next;
         flag = 1;
    }
    if(temp->data == key){
    if(flag == 0)
        hashTable[hash] = temp->next;
    else
        temp_prev = temp->next;
    free(temp);
    }
    else
        printf("key not found\n");
}

void display(){
    printf("\n\n HashTable :\n");
    for(int i=0; i< size; i++){
        struct node *temp = hashTable[i] ;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("null \n");
    }
}
int main()
{
   for( int i=0;i< size ; i++){
   insert();
   }
   display();
   search(33);
   int n;
   scanf("%d",&n);
   delete(n);
      display();
      search(2);
   return 0;
}
