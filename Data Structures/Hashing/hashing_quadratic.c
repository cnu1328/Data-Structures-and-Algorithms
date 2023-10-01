#include<stdio.h>

#define size 7

int arr[size];


void init()
{
    int i;
    for(i = 0; i < size; i++)
        arr[i] = -1;
}

void insert(int value)
{
    int key = value % size;
    printf("\t  %d", key);

    if(arr[key] == -1)
    {
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value,key);
    }
    else
    {
        int i;
        for(i=1;i<size;i++){
             int newkey=(key+i*i)%size;
             if(arr[newkey] == -1){
                arr[newkey]=value;
                break;
             }
        }
        if(i == size)
         printf("\nelement cannot be inserted\n");
    }
}

void print()
{
    int i;
    for(i = 0; i < size; i++)
        printf("arr[%d] = %d\n",i,arr[i]);
}

int main()
{
    init();
    insert(10); //key = 10 % 7 ==> 3
    insert(4);  //key = 4 % 7  ==> 4
    insert(2);  //key = 2 % 7  ==> 2
    insert(3);  //key = 3 % 7  ==> 3 (collision)
    insert(17);  //key = 17 % 7  ==> 3 (collision)
    insert(24);  //key = 24 % 7  ==> 3 (collision)
    insert(31);  //key = 31 % 7  ==> 3 (collision)
    insert(38);  //key = 38 % 7  ==> 3 (collision)

    printf("Hash table\n");
    print();
    printf("\n");

    return 0;
}
