#include<bits/stdc++.h>

using namespace std;

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && a[left] < a[largest])
        largest = left;

    if(right < n && a[right] < a[largest])
        largest = right;

    if(i != largest) {
        swap(a[i], a[largest]);

        heapify(a, n, largest);
    }
}

void buildMinHeap(int a[], int n) {
    int sindx = (n/2)-1;

    for(int i=sindx; i>=0; i--) {
        heapify(a,n,i);
    }
}

int deletion(int a[], int &n) {

    int first = a[0];

    a[0] = a[n-1];

    n--;

    heapify(a,n,0);

    return first;

}

//void insertify(int a[], int n, int i) {
//    int parent = (i/2)-1;
//
//    if(a[parent] > 0) {
//        if(a[i] < parent) {
//            swap(a[i], a[parent]);
//            insertify(a, n, parent);
//        }
//    }
//}

int insertion(int a[], int &n, int key) {
    n = n+1;

    a[n-1] = key;

//    int sindx = (n/2)-1;
//
//    for(int i=sindx; i>=0; i--) {
//        heapify(a,n,i);
//    }
//    insertify(a, n, n-1);
}

int main() {

//    int a[] = {35, 40, 30, 20, 50, 60};
    int a[] = {3, 6, 4, 1, 5, 2};
    int n = sizeof(a)/sizeof(a[0]);
    buildMinHeap(a,n);
    cout<<"-------------- MIN HEAP ------------------------"<<endl;
    for(int i=0; i<n; i++) {
        cout<<a[i]<<", ";
    }
    cout<<endl<<"Optimal merge pattern answer is : ";
    int sum = 0;
    while(n>1) {
        int mergesum = 0;

        mergesum += deletion(a,n);
        mergesum += deletion(a,n);

        sum += mergesum;

        insertion(a, n, mergesum);
    }

    cout<<sum<<endl;


}
