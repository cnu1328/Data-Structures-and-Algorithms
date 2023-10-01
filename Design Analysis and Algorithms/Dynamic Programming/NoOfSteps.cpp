#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int ccp(int weights[], int sum, int n, int i) {
    if(sum == 0)
        return 1;
    if(n == 0)
        return 0;
    if(i > n)
        return 0;
    if(weights[n-1] <= sum) {
        return ccp(weights, sum - weights[n-1], n, i) + ccp(weights, sum, n-1, i);
    }

    else {
        return ccp(weights, sum, n-1, i);
    }

    if(weights[n-1] <= sum) {
        return  ccp(weights, sum - weights[i-1], n, i) + ccp(weights, sum, n, i+1);
    }

    else {
        return ccp(weights, sum, n, i+1);
    }
}

int main() {
    int n;
    cout<<"Enter a number : "<<endl;

    cin>>n;

    cout<<"Enter array values : ";

    int weights[n];

    for(int i=0; i<n; i++) {
        cin>>weights[i];
    }

    cout<<"Enter sum : "<<endl;
    int sum;
    cin>>sum;

    cout<<ccp(weights, sum, n, 0)<<endl;
    cout<<"Enter Coin Change Exist (PR) : "<<ans<<endl;
}
