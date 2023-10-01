
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

    //insertion Sort

    for(i=0;i<n-1;i++){
        int key = a[i+1];
        int j;
        for(j=i;j>=0 && key<a[j];j--){
            a[j+1]= a[j];
        }
        a[j+1]=key;
    }
    cout<<endl<<"Sorted Array : "<<endl;
    for(i=0;i<n;i++){
        cout<<a[i]<<", ";
}
}
