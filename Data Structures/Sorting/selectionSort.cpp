#include<iostream>
#include<vector>

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

    cout<<endl<<"Selection Sort"<<endl<<endl;

    for(i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        int t = a[i];
        a[i]=a[min];
        a[min]=t;
    }

    cout<<"Sorted Array is : "<<endl;
    for(i=0;i<n;i++){
        cout<<a[i]<<", ";

    }

}
