#include<bits/stdc++.h>

using namespace std;

int a[100][100];

bool esp(int weights[], int sum, int n) {
   if(sum == 0)
        return true;
   if(n == 0)
        return false;

   if(weights[n-1] <= sum ) {
        return (esp(weights, sum - weights[n-1], n-1) || esp(weights, sum, n-1));
   }

   else
        return esp(weights, sum, n-1);
}

bool esp_dp(int weights[], int sum, int n) {
    if(sum == 0 ) {
        return a[n][sum] = true;
    }

    if(n == 0) {
        return a[n][sum] = false;
    }

    if(a[n][sum] != -1) {
        return a[n][sum];
    }

    if(weights[n-1] <= sum) {
        return a[n][sum] = (esp_dp(weights, sum - weights[n-1], n-1) || esp_dp(weights, sum,n-1));
    }

    else {
        return a[n][sum] = esp_dp(weights, sum, n-1);
    }
}

int main() {
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;

    cout<<"Enter array values : "<<endl;

    int weights[n];
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin>>weights[i];
        sum += weights[i];
    }

    if(sum%2 !=0){
        cout<<"false"<<endl;
        return 0;

    }

    cout<<"Equal Sum partition by (PR) : "<<esp(weights,sum/2,n)<<endl;

    memset(a,-1, sizeof(a));

    cout<<"Equal Sum partition by (DP) : "<<esp_dp(weights,sum/2,n)<<endl;

    cout<<"Equal Sum partition by Tabulation : ";

    int arr[n+1][sum/2+1];

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=sum/2; j++) {

            if(j == 0){
                arr[i][j] = true;
                continue;
            }

            if(i == 0 ){
                arr[i][j] = false;
                continue;
            }

            if(weights[i-1] <= j) {
                arr[i][j] = (arr[i-1][j - weights[i-1]] || arr[i-1][j]);
            }

            else {
                arr[i][j] = arr[i-1][j];
            }
        }
    }

    cout<<arr[n][sum/2];

}
