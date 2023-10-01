#include<stdio.h>
#include<stdlib.h>
struct Node{
 int data;
 struct Node *prev, *next;
};

struct Node *tail = NULL;

struct Node *createNode(int val){
struct Node *nn;
nn = (struct Node *) malloc(sizeof(struct Node));
nn->data = val;
nn->next = nn->prev = NULL;
return nn;
}
void display(struct Node *head){
 while(head!=NULL){
 printf("%d\t", head->data);
 head=head->next;
 }
 printf("\n\n");
}
//insert at tail
struct Node *insert_tail(struct Node *head, int val){
	struct Node *nn = createNode(val);
	if(head == NULL){
		tail = nn;
		return nn;
	}
	tail->next = nn;
	nn->prev = tail;
	tail = nn;
	return head;


}
//insert at head
struct Node *insert_head(struct Node *head, int val)
{
	struct Node *nn = createNode(val);
	if(head == NULL){
		tail = nn;
		return nn;
	}
	nn->next = head;
	head->prev = nn;
	return nn;

}
//insert at specific position
struct Node *insert_pos(struct Node *head, int pos, int x)
{
	struct Node *nn = createNode(x);
	if(head == NULL){
		tail = nn;
		return nn;
	}
	if(pos == 1){
		head = insert_head(head,x);
		return head;
	}
	struct Node *temp = head;
	for(int i=0;i<pos-2 && temp!=NULL;i++){
		temp = temp->next;
	}

	if(temp == NULL){
		printf("Position Not Found to insert");
		return head;
	}
	if(temp == tail){
		head = insert_tail(head,x);
		return head;
	}
	nn->next = temp->next;
	temp->next->prev = nn;
	temp->next = nn;
	nn->prev = temp;
	return head;

}
// delete node at head
struct Node *delete_head(struct Node *head)
{

    if(head == NULL){
    	printf("No Linked list is present!");
    	return NULL;
    }
    struct Node *temp = head;
    head = temp->next;
    head->prev = NULL;
    free(temp);
    return head;
}
// delete node at tail
struct Node *delete_tail(struct Node *head)
{

    if(head == NULL){
    	printf("NO Linked list is present!");
    	return NULL;
    }
    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct Node *temp = tail->prev,*temp1=tail;
    /*while(temp->next!=NULL){
    	temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);*/

    tail->prev->next = NULL;
    tail = temp;
    free(temp1);
    return head;

}
// search Element
int search(struct Node * head, int val){
    if(head == NULL)
        return 0;
    struct Node *temp = head;
    int flag =0;
    while(temp!=NULL){
        if(temp->data == val){
            flag =1;
            break;
        }
        else{
            temp = temp->next;
        }
    }
    if(flag == 1)
        printf("\nFound\n");
    else
        printf("\nNOt Found\n");

    return 0;

}
//count no of nodes
int count(struct Node *head){
    if(head == NULL)
        return -1;
    struct Node *temp = head;
    int c=0;
    while(temp!=NULL){
        c++;
        temp = temp->next;
    }
    printf("Size of the linked list is %d",c);

}
// Insert After
struct Node *insert_after(struct Node *head, int data, int val){
	struct Node *nn = createNode(val);
	if(head == NULL){
		tail = nn;
		return nn;
	}
	if(head->next == NULL){
		if(head->data == data){
			head = insert_tail(head,val);
			return head;
		}
		printf("No Data value in linked list");
		return head;
	}
	struct Node *temp = head;
	while(temp!=NULL){
		if(temp->data != data)
			temp = temp->next;
        else
            break;
	}
	if(temp == NULL){
		printf("NO Data value in Linked list");
		return head;
	}
	nn->next = temp->next;
	temp->next->prev = nn;
	temp->next = nn;
	nn->prev = temp;
	return head;


}
// Insert Before

struct Node *insert_before(struct Node *head, int data, int val){
	struct Node *nn = createNode(val);
	if(head == NULL){
		tail = nn;
		return nn;
	}
	if(head->next == NULL){
		if(head->data == data){
			head = insert_head(head,val);
			return head;
		}
		printf("No Data value in linked list");
		return head;
	}
	struct Node *temp = head;
	while(temp->next!=NULL){
		if(temp->next->data != data)
			temp = temp->next;
        else
            break;

	}
	if(temp->data == data){
		tail->next = nn;
		nn->prev = tail;
	}
	if(temp->next == NULL)
	{
		printf("NO Data value in Linked List");
		return head;
	}
	nn->next = temp->next;
	temp->next->prev = nn;
	temp->next = nn;
	nn->prev = temp;
	return head;

}

// delete element
struct Node *delete_element(struct Node *head, int ele){
    if(head==NULL){
        printf("NO linked list");
        return NULL;
    }

    if(head->next == NULL){
        if(head->data == ele){
            printf("Element is deleted");
            return NULL;
        }

        printf("Element Not found");
        return head;
    }
    struct Node *temp = head;
    while(temp!=NULL){
        if(temp->data == ele)
            break;
        else
            temp = temp->next;
    }
    if(temp == NULL){
        printf("Element not found");
        return head;
    }
    struct Node *temp1 = temp->prev,*temp2 = temp->next;
    temp1->next = temp->next;
    temp2->prev = temp->prev;
    free(temp);
    return head;

}

//insert element after given direct address to node.

void insert_after_addr(struct Node* curr_node, int val) {
    if(curr_node == NULL)
        return;
    struct Node *nn = createNode(val);
    nn->next = curr_node->next;
    curr_node->next->prev = nn;
    curr_node->next = nn;
    return;


}
struct Node *revList( struct Node *head)
{ /// BEGIN SOLUTION
    if(head == NULL)
        return NULL;
    struct Node *prev= NULL,*next = NULL,*curr = head;
    while(curr){
        next = curr->next;
        curr->prev = next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;

}
int main(){
 struct Node *head = NULL;
 head = insert_tail(head, 1);
 head = insert_tail(head, 2);
 head = insert_tail(head, 3);
 head = insert_head(head, 4);
 display(head);
 printf("\nInsert After : \n");
 head = insert_after(head,4, 7);
 display(head);
 printf("\nIsert Before : \n");
 head = insert_before(head, 2, 9);
 display(head);

 head = insert_pos(head, 4, 6);
 printf("\n");
 display(head);

 printf("\nDelete at head : \n");
 head = delete_head(head);
 display(head);

 printf("\nDelete at tail : \n");
 head = delete_tail(head);

 display(head);

 //head = delete_element(head, 7);
 display(head);

 search(head,7);
 count(head);


 insert_after_addr(head->next, 22);
 printf("\n");
 display(head);
 printf("\n");
 head = revList(head);
 display(head);
 return 0;
}
