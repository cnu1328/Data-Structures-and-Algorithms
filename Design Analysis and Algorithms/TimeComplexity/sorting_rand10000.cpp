#include<bits/stdc++.h>
#include <time.h>


using namespace std;

void mergeSort(int *p,int st,int mid, int end){
    vector<int> v;
    int i=st,j=mid+1;
    while(i<=mid && j<=end){
        if(p[i]<=p[j]){
            v.push_back(p[i++]);
        }
        else{
            v.push_back(p[j++]);
        }
    }
    while(i<=mid){
        v.push_back(p[i++]);
    }
    while(j<=end){
        v.push_back(p[j++]);
    }

    for(int i=st;i<=end;i++){
        p[i] = v[i-st];
    }
}

void merge(int *p,int st,int end){
    int mid;
    if(st<end){
        mid = st+(end-st)/2;

        merge(p,st,mid);
        merge(p,mid+1,end);
        mergeSort(p,st,mid,end);
    }
}


void heapifyM(int a[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && a[largest] > a[left]) {
        largest = left;
    }

    if(right < n && a[largest] > a[right]) {
        largest = right;
    }

    if(i != largest) {
        swap(a[i], a[largest]);
        heapifyM(a,n,largest);
    }
}


void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && a[largest] < a[left]) {
        largest = left;
    }

    if(right < n && a[largest] < a[right]) {
        largest = right;
    }

    if(i != largest) {
        swap(a[i], a[largest]);
        heapify(a,n,largest);
    }
}



void heapSort(int a[], int n) {

    for(int i= n/2-1; i>=0; i--) {
        heapify(a,n,i);
    }

    for(int i=n-1; i>0; i--) {
        swap(a[0], a[i]);

        heapify(a,i,0);
    }

}

void heapSortM(int a[], int n) {

    for(int i= n/2-1; i>=0; i--) {
        heapifyM(a,n,i);
    }

    for(int i=n-1; i>0; i--) {
        swap(a[0], a[i]);

        heapifyM(a,i,0);
    }

}

void bubbleSort(int a[], int n) {

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j+1]<a[j]){
                int t = a[j+1];
                a[j+1] = a[j];
                a[j] = t;
            }
        }
    }
}

void insertionSort(int a[], int n) {

    for(int i=0; i<n-1; i++){
        int key = a[i+1];
        int j;
        for(j=i; j>=0 && key<a[j];j--){
            a[j+1]= a[j];
        }

        a[j+1] = key;

    }
}

void selectionSort(int a[], int n) {
    for(int i=0;i<n;i++){
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
}


void print(int a[], int n) {
    for(int i=0;i<100;i++){
        cout<<a[i]<<", ";
    }
}
int main(){

    ofstream file;

    file.open("rand10000.txt");

    if(file){
        for(int i=0;i<10000;i++)
//            file<<rand()%10000<<" ";
//            file<<i<<" ";
              file<<10000-i<<" ";
    }
    file.close();

    ifstream read;

    int a[10000];
    int n=0;
    read.open("rand10000.txt");

    while(!read.eof()){
        read>>a[n];
        n++;
    }

    read.close();

    print(a,n);

    clock_t start, end;
    start = clock();

//    bubbleSort(a, n);

//    insertionSort(a,n);

//    selectionSort(a,n);

//    merge(a,0,n-2);

//    quick(a,0,n-1);

//    buildMaxHeap(a,n-1);
//    print(a,n);
//    buildMinHeap(a,n-1);
//    print(a,n);
//    heapSort(a,n);

    end = clock();

    double time_take = (double)(end - start)/double(CLOCKS_PER_SEC);

    cout<<endl<<endl<<"Time taken to sort array by Max-Heap  Sort :  "<<fixed<<time_take<<setprecision(5)<<" sec " << endl<<endl;

    cout<<endl<<"Sorted Array : ";

    for(int i=0;i<100;i++){
        cout<<a[i]<<", ";
    }
}

