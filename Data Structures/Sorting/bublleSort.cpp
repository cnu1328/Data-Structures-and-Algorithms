#include<iostream>

using namespace std;

int main(){

    int n;
    cout<<"Enter Number of array values : "<<endl;
    cin>>n;
    int a[n];
    int i=0;
    cout<<"Enter Array values : ";
    while(i<n){
        cin>>a[i];
        i++;
    }
    cout<<endl<<"Entered Array values : "<<endl;
    for(i=0;i<n;i++){
        cout<<a[i]<<", ";

    }

    cout<<endl<<"Bubble Sort"<<endl;
    for(i=0;i<n;i++){
        bool swap = false;
        for(int j=0;j<n-i-1;j++){

            if(a[j]>a[j+1]){
                int t = a[j];
                a[j]=a[j+1];
                a[j+1]= t;
                swap=true;
            }


        }
        if(swap==false)
                break;
    }


    cout<<"Sorted Array : "<<endl;

    for(i=0;i<n;i++){
        cout<<a[i]<<", ";

    }

}
