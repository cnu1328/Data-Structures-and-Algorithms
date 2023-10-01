#include<iostream>

using namespace std;


void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(int a[],int n){
    for(int j=1;j<n;j++){
        int child,parent;
        for(child=j;child>0;child=parent){
            parent = (child-1)/2;
            if(a[parent]<a[child])
                swap(&a[parent],&a[child]);
        }
    }
}



void heapsort(int a[],int n){
    heapify(a,n);
    for(int i=n-1;i>=0;i--){
        swap(&a[0],&a[i]);
        heapify(a,i);
    }

}


 int main(){
    int a[] = { 6, 5, 3, 1, 8, 7, 2, 4};
    int n = sizeof(a)/sizeof(a[0]);
    heapsort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<", ";
    }

}
