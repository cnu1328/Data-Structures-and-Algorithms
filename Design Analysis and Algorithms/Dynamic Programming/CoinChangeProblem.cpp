#include<bits/stdc++.h>

using namespace std;

int arr[100][100];


bool ccp(int weights[], int sum, int n) {

    if(sum == 0) {
        return true;
    }

    if(n == 0) {
        return false;
    }

    if(weights[n-1] <= sum) {
        return (ccp(weights, sum - weights[n-1], n) || ccp(weights, sum, n-1));
    }

    else {
        return ccp(weights, sum, n-1);
    }

}


bool ccp_dp(int weights[], int sum, int n) {

    if(sum == 0) {
        return arr[n][sum] = true;
    }

    if(n == 0 ) {
        return arr[n][sum] = false;
    }

    if(arr[sum][n] != -1) {
        return arr[sum][n];
    }

    if(weights[n-1] <= sum) {
        return arr[sum][n] = (ccp_dp(weights, sum - weights[n-1], n) || ccp_dp(weights, sum, n-1));
    }

    else {
        return arr[sum][n] = ccp_dp(weights, sum, n-1);
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

    cout<<"Enter Coin Change Exist (PR) : "<<ccp(weights, sum, n)<<endl;

    memset(arr,-1,sizeof(arr));

    cout<<"Enter Coin Change Exist (DP) : "<<ccp_dp(weights, sum, n)<<endl;

    cout<<"Enter Coin Change Exist Tabulation : ";

    int b[n+1][sum+1];

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            if(j == 0) {
                b[i][j] = true;
                continue;
            }

            if(i == 0) {
                b[i][j] = false;
                continue;
            }


            if(weights[i-1] <= j ) {
                b[i][j] =  b[i][j - weights[n-1]] || b[i-1][j];
            }

            else {
                b[i][j] = b[i-1][j];
            }
        }
    }

    cout<<b[n][sum]<<endl;




}
