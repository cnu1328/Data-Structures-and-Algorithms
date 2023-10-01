#include<iostream>

using namespace std;

int main(){
    int t=5;
    //cin>>t;
    int a[t]={5,4,3,2,1};
    int b[t] = {2,3,1,1,6};
    int i=0;
    /*while(i<t){
    	cin>>a[i];
    	i++;
    }*/
    i = 0;
    cout<<"Entered Array : "<<endl;
    while(i<t){
    	cout<<a[i]<<", ";
    	i++;
    }

    //insertion sort
    for(i=0;i<t-1;i++){
    	int k = a[i+1];
    	int j=i;
    	while(j>=0 && k<a[j]){
    		a[j+1]=a[j];
    		j--;
    	}
    	a[j+1]=k;
    }


    cout<<"Sorted Array is : "<<endl;
    i=0;
    while(i<t){
    	cout<<a[i]<<", ";
    	i++;
    }



}
