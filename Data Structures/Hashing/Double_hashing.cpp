#include<iostream>

using namespace std;

#define size 7
#define prime 7

int arr[size];

void init(){
    for(int i=0;i<size;i++)
        arr[i]=-1;
}

int h1(int val){
    return (val%size);
}

int h2(int val){
    return (prime-(val%prime));
}

void insert(int val){
    int key = h1(val);

    if(arr[key]==-1){
        arr[key]=val;
        cout<<val<<" Inserted at arr["<<key<<"]"<<endl;
    }
    else{
        int key2 = h2(val),i;
        for(i=0;i<size;i++){
            int newkey = (key+(key2*i))%size;
            if(arr[newkey]==-1){
                arr[newkey]=val;
                break;
            }

        }
        if(i==size)
            cout<<"Element is not inserted"<<endl;
    }
}

void print(){
    for(int i=0;i<size;i++)
        cout<<"arr["<<i<<"]"<<" = "<<arr[i]<<endl;
}

int main(){
    init();
    /*int n,a;
    cin>>n;
    while(n--){
        cin>>a;
        insert(a);
    }*/

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
