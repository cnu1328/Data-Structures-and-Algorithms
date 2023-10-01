#include<bits/stdc++.h>

using namespace std;

int a[100][100];

int mcc(int weights[], int sum, int n) {
    if(sum == 0) {
        return 0;
    }

    if( n == 0) {
        return 10000;
    }

    int res  = -1; //NO elements present;

    if(weights[n-1] <= sum) {
//        int takecoin = 1 + mcc(weights, sum - weights[n-1], n);
//        int notTakeCoin = mcc(weights, sum, n-1);

        res = min(1 + mcc(weights, sum - weights[n-1], n), mcc(weights, sum, n-1));

    }

    else {
        res = mcc(weights, sum, n-1);
    }

    return res;
}

int mcc_dp(int weights[], int sum, int n) {

    if(sum == 0)
        return 0;

    if(n == 0)
        return 10000;

    if(a[n][sum] != -1)
        return a[n][sum];

    int result = -1;

    if(weights[n-1] <= sum) {
//        int takecoin = 1 + mcc_dp(weights, sum - weights[n-1], n);
//        int nottakecoin = mcc_dp(weights, sum, n-1);

        result = min(1 + mcc(weights, sum - weights[n-1], n), mcc(weights, sum, n-1));

    }

    else {
        result = mcc_dp(weights, sum, n-1);

    }

    return a[n][sum] = result;
}

int main() {
    int n;

    cout<<"Enter a number : ";
    cin>>n;

    cout<<"Enter array values : ";

    int weights[n];
    for(int i=0; i<n; i++) {
        cin>>weights[i];
    }

    int sum;
    cout<<"Enter sum of a number : ";
    cin>>sum;

    cout<<"Minimum coin change problem (PR) : "<<mcc(weights, sum, n)<<endl;

    memset(a,-1,sizeof(a));

    cout<<"Minimum coin Change Problem with DP : "<<mcc_dp(weights, sum, n)<<endl;

    cout<<"Minimum Coin Change with Tabulation : ";

    int b[n+1][sum+1];

    for(int i=0; i<= n; i++) {
        for(int j=0; j<=sum; j++) {
            if(j == 0) {
                b[i][j] = 0;
                continue;
            }

            if(i == 0) {
                b[i][j] = 100000;
                continue;
            }


            if(weights[i-1] <= j) {
                int take = (1 + b[i][j - weights[i-1]]);
                int nottake = b[i-1][j];

                b[i][j] = min(take, nottake);
            }

            else {
                b[i][j] = b[i-1][j];
            }
        }
    }

    cout<<b[n][sum]<<endl;

    for(int i=0; i<=n; i++) {
        for(int j = 0; j<=sum; j++) {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

}
