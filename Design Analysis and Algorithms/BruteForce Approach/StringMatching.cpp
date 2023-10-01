#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>

using namespace std;

int main(){

    cout<<rand()<<endl;
    clock_t t;
    t = clock();
    string m,n;
    cout<<"Enter a string : ";
    cin>>m;
    cout<<endl<<"Enter a substring : ";
    cin>>n;

    bool flag = false;
    int pos=0;
    for(int i=0;i<m.length()-n.length();i++){
        int k=0;
        bool flag1=true;
        for(int j=i;j<i+n.length();j++){
            if(m[j]==n[k++])
                continue;
            else{
                flag1= false;
                break;
            }
        }
        if(flag1==true){
            flag = true;
            pos = i;
            break;

        }
    }

    if(flag==true){
        cout<<"Your substring is found at pos "<<pos<<endl;
    }
    else
        cout<<"Your Substring is not found"<<endl;

    t = clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    cout<<"Time taken by code : "<<time_taken<<endl;


}
