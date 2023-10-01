#include<bits/stdc++.h>

using namespace std;


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


void buildHeap(int a[], int n) {

    int sindx = (n/2)-1;

    for(int i= sindx; i>=0; i--) {
        heapify(a,n,i);
    }
}

int deletion(int a[], int &n) {
    int laste = a[n-1];
    int first = a[0];

    a[0] = laste;

    n--;

    heapify(a,n,0);

    return first;
}


void insertify(int a[], int n, int i) {

    int parent = (i-1)/2;

    if(a[parent] > 0) {

        if(a[i] < a[parent]) {
            swap(a[i], a[parent]);
            insertify(a, n, parent);
        }
    }
}

void insertion(int a[], int &n, int i) {

    n = n+1;

    a[n-1] = i;

    insertify(a, n, n-1);
}

int main() {

    int a[] = {6, 35, 35, 37, 40, 41, 82, 84, 101, 106, 118, 141, 145, 153, 169, 190, 253, 264, 281, 288, 292, 299, 308, 316, 322, 323, 333, 334, 350, 358, 370, 376, 382, 391, 393, 421, 436, 439, 446, 447, 464, 467, 478, 491, 500, 529, 537, 538, 538, 541, 547, 548, 604, 623, 626, 629, 644, 648, 662, 664, 667, 673, 703, 705, 711, 716, 718, 723, 724, 726, 729, 741, 756, 757, 771, 778, 805, 811, 827, 827, 840, 842, 859, 868, 869, 890, 894, 895, 902, 912, 929, 931, 942, 942, 944, 954, 961, 962, 966, 995};

    int n = sizeof(a) / sizeof(a[0]);

    buildHeap(a,n);

    cout<<"MIN_Heap"<<endl;
    for(int i=0; i<n; i++) {
        cout<<a[i]<<", ";
    }

//    int sum = 0;
//
//    for(int i=0; i<3; i++) {
//        int element = deletion(a,n);
//        sum += element;
//    }
//
//    cout<<endl<<sum<<endl;
//
//
//    cout<<endl<<"After Deletion : "<<endl;
//    for(int i=0; i<n; i++) {
//        cout<<a[i]<<", ";
//    }
//
//    int key = 1;
//
//    insertion(a,n,key);
//
//    cout<<endl<<"after insertion of element : "<<endl;
//
//    for(int i=0; i<n; i++) {
//        cout<<a[i]<<", ";
//    }
//
//    cout<<endl;


}
