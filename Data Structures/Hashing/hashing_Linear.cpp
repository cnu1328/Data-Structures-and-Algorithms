#include<iostream>

using namespace std;

#define size 7

int a[size];

void init(){
    for(int i=0;i<size;i++)
        a[i]=-1;

}


void insert(int val){
    int key = val%size;
    if(a[key]==-1){
        a[key]=val;
        cout<<val<<" is inserted at arr["<<key<<"]"<<endl;
    }
    else{

        int i;
        for(i=0;i<size;i++){
            int newkey = (key+i)%size;
            if(a[newkey]==-1){
                a[newkey]=val;
                break;
            }

        }
        if(i==size)
        cout<<"Element not inserted"<<endl;
    }

}

void print(){
    for(int i=0;i<size;i++){
        cout<<"arr["<<i<<"]"<<" = "<<a[i]<<endl;

    }
}

int main(){
    init();
    insert(10); //key = 10 % 7 ==> 3
    insert(4);  //key = 4 % 7  ==> 4
    insert(2);  //key = 2 % 7  ==> 2
    insert(3);  //key = 3 % 7  ==> 3 (collision)
    insert(17);  //key = 17 % 7  ==> 3 (collision)
    insert(24);  //key = 24 % 7  ==> 3 (collision)
    insert(31);  //key = 31 % 7  ==> 3 (collision)
    insert(38);

    cout<<"HASH TABLE"<<endl;
    print();
    cout<<endl;
    return 0;

}































/*




#include<iostream>

using namespace std;

#define size 7

int arr[size];

void init(){
    for(int i=0;i<size;i++)
        arr[i]=-1;
}

void insert(int val){
    int key = val%size;
    cout<<"Key Value : "<<key<<endl;

    if(arr[key]==-1){
        arr[key] = val;
        cout<<val<<" is inserted at arr["<<key<<"]"<<endl;
    }

    else{
        int i;
       for(i=0;i<size;i++){
            int newkey = (key+i)%size;
            if(arr[newkey]==-1){
                arr[newkey] = val;
                break;
            }


        }
        if(i==size)
        cout<<"Element not inserted"<<endl;
    }



}

void print(){
    for(int i=0;i<size;i++)
        cout<<"arr["<<i<<"]"<<" = "<<arr[i]<<endl;
}


int main(){
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
*/
