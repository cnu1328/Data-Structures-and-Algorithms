#include<bits/stdc++.h>

using namespace std;

int knapgreed(int weights[],int values[], int weight, int n, int val) {
    if(weight == 0) return val;

    if(n==0) return -1;

    if(weights[n-1] <= weight) {
        return knapgreed(weights,values, weight - weights[n-1], n-1, val + values[n-1]);
    }

    else {
        return knapgreed(weights,values, 0, n-1, val + (values[n-1]/weights[n-1])*weight);
    }
}

int main() {
    int n = 4;
    //cout<<"Enter a number : ";
    //cin>>n;

    int weights[n] = {2,3,4,5};
    int values[n] = {10,12,31,15};

    /*
    cout<<"Enter weights : ";
    for(int i=0; i<n; i++) {
        cin>>weights[i];
    }

    cout<<endl<<"Enter weights : ";
    for(int i=0; i<n; i++) {
        cin>>values[i];
    }

    int weight;

    cout<<"Enter total weight : ";
    cin>>weight;

    */

    int weight = 11;

    cout<<"Before sorting : "<<endl;
    for(int i=0; i<n; i++) {
        cout<<weights[i]<<" ";
    }

    cout<<endl;
    for(int i=0; i<n; i++) {
        cout<<values[i]<<" ";
    }

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if((values[j]/weights[j]) > (values[j+1]/weights[j+1])) {
                swap(values[j],values[j+1]);
                swap(weights[j],weights[j+1]);
            }
        }
    }



    cout<<endl<<"weights & values are sorted according to their fraction : "<<endl;
    for(int i=0; i<n; i++) {
        cout<<weights[i]<<" ";
    }

    cout<<endl;
    for(int i=0; i<n; i++) {
        cout<<values[i]<<" ";
    }

    int val = 0;
    for(int i=n-1; i>=0; i--) {
        if(weights[i]<= weight) {
            val += values[i];

            weight -= weights[i];
        }

        else {
            val += (values[i]/weights[i])*weight;
            break;
        }
    }

    cout<<endl<<"maximum value of our total weight is : "<<val<<endl;
    cout<<endl<<"maximum value of our total weight is : "<<knapgreed(weights,values, weight, n, 0)<<endl;

}
