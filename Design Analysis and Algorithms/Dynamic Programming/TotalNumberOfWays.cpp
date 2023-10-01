#include<bits/stdc++.h>

using namespace std;

int arr[10][10];

int tnw(int weights[], int sum, int n) {
    if(sum == 0) {
        return 1;
    }

    if(n == 0) {
        return 0;
    }

    if(weights[n-1] <= sum) {
        return (tnw(weights, sum-weights[n-1], n-1) + tnw(weights, sum, n-1));
    }

    else {
        return tnw(weights, sum, n-1);
    }
}


int tnw_dp(int weights[], int sum, int n) {



    if(sum == 0) {
        return arr[n][sum] = 1;
    }

    if(n == 0) {
        return arr[n][sum] = 0;
    }

    if(arr[sum][n] != -1 )
        return arr[sum][n];

    if(weights[n-1] <= sum) {
        return arr[n][sum] = (tnw_dp(weights, sum-weights[n-1], n-1) + tnw_dp(weights, sum, n-1));
    }

    else {
        return arr[n][sum] = tnw_dp(weights, sum, n-1);
    }
}

int main() {
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;

    int weights[n];
    cout<<"Enter weights : ";
    for(int i=0; i<n; i++) {
        cin>>weights[i];
    }

    cout<<"Enter target Sum : "<<endl;
    int sum;

    cin>>sum;

    cout<<"Total number of ways to get your target is (PR) : "<<tnw(weights,sum,n)<<endl;

    memset(arr,-1,sizeof(arr));
    cout<<"Total number of ways to get your target is (DP) : "<<tnw_dp(weights,sum,n)<<endl;

    int a[n+1][sum+1];

    memset(a,0,sizeof(a));

    cout<<"Total number of ways to get your target by tabulation : ";

    for(int i=0; i<=n; i++) {

        for(int j=0; j<=sum; j++) {
            if(j==0){
                a[i][j] = 1;
                continue;
            }

            if(i==0){
               a[i][j] = 0;
               continue;
            }

            if(weights[i-1] <= sum ) {

                a[i][j] = a[i-1][j-weights[i-1]] + a[i-1][j];
            }
            else
                a[i][j] = a[i-1][j];
        }
    }



    cout<<a[n][sum]<<endl;

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            cout<<a[i][j]<<", ";
        }
        cout<<endl;
    }


}
