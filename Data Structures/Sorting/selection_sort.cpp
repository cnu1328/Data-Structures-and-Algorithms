#include<iostream>

using namespace std;

int main(){
    int t=5;
    //cin>>t;
    int a[t]={5,9,3,2,1};
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

    //selection sort

    for(int i=0;i<t;i++){
    	int minI = i;
    	for(int j=i;j<t;j++){
    	    if(a[j]<a[minI])
    	    	minI=j;
    	}


    	    int t=a[i];
            a[i]=a[minI];
 	     a[minI]=t;


    }

    cout<<"Sorted Array is : "<<endl;
    i=0;
    while(i<t){
    	cout<<a[i]<<", ";
    	i++;
    }



}
