#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

struct node *head = NULL;

node *createnode(){
    node *temp,*nn;
    nn = (struct node *)malloc(sizeof(struct node));
}

int main()
{
    int i,a,n;
    node *start=NULL,*ptr,*temp;
    cout<<"Enter number of data values : ";
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cout<<"Enter data value : ";
        cin>>a;
        ptr = new node;
        ptr->data=a;
        ptr->next=NULL;
        if(start==NULL)
            start=ptr;
        else
        {
            temp=start;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=ptr;
        }
    }
    temp=start;
    while(temp)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}
