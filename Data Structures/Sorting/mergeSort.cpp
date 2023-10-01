
#include<iostream>

using namespace std;

void merge(int *p,int st,int mid,int end){
//    int l[end],r[end],i,j,k;
//
//    for(i=0;i<=mid;i++){
//        l[i]=p[i];
//    }
//    for(i=mid+1;i<=end;i++){
//        r[i]=p[i];
//    }
    int i,j,k;
    i = st;
    j = mid+1;
    k=st;
//
//    while(i<=mid && j<=end){
//        if(l[i]<=r[j])
//            p[k++]=l[i++];
//        else
//            p[k++]=r[j++];
//    }
//    while(i<=mid){
//        p[k++]=l[i++];
//    }
//    while(j<=end){
//        p[k++]=r[j++];
//    }


    int b[20];

    while(i<=mid && j<=end){
        if(p[i]<=p[j]){
            b[k++]=p[i++];
        }
        else
            b[k++]=p[j++];
    }

    while(i<=mid)
        b[k++]=p[i++];
    while(j<=end)
        b[k++]=p[j++];

    for(i=st;i<=end;i++){
        p[i]=b[i];
    }


}

void split(int *p,int st,int end){
    if(st<end){
        int mid = (st+end)/2;
        split(p,st,mid);
        split(p,mid+1,end);
        merge(p,st,mid,end);
    }
}




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

    //merge Sort

    split(a,0,n-1);
    cout<<endl<<"Merge Sorted Array is : ";
    for(i=0;i<n;i++){
        cout<<a[i]<<", ";
    }
}


