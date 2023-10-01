#include<bits/stdc++.h>

using namespace std;

int a[100][100];

bool sos(int weights[], int sum, int n) {
    if(sum == 0)
        return true;
    if(n == 0)
        return false;

    if(weights[n-1] <= sum) {

        return sos(weights, sum-weights[n-1], n-1) || sos(weights, sum, n-1);
    }

    else{
        return sos(weights, sum, n-1);
    }

}

bool sos_mem(int weights[], int sum, int n) {

    if(a[n][sum] != -1) {
        return a[n][sum];
    }

    if(sum == 0) {
        return true;
    }

    if(n == 0)
        return false;
    if(weights[n-1] <= sum) {
        return a[n][sum] = sos_mem(weights, sum-weights[n-1], n-1) || sos_mem(weights, sum, n-1);
    }

    else {
        return a[n][sum] = sos_mem(weights, sum, n-1);
    }
}


int main() {
   int n;
   cout<<"Enter a number : ";
   cin>>n;
   int weights[n];
   //weight array {5,3,2,6} and sum = 9
   //{4, 16, 5, 23, 12}, sum = 9 true
    //{2, 3, 5, 6, 8, 10}, sum = 10 true

   for(int i=0; i<n; i++) {
       cin>>weights[i];
   }

   cout<<"Enter total Sum : "<<endl;
   int sum;
   cin>>sum;

   cout<<"If Sum of Subset exists or not by (PR) : "<<sos(weights,sum,n)<<endl;





   memset(a,-1,sizeof(a));

   cout<<"If Sum of Subset exists or not by (DP) : "<<sos_mem(weights,sum,n)<<endl;

   cout<<"If Sum of Subsets exists or not by Tabulation : ";


   int b[n+1][sum+1];

   memset(b,0,sizeof(b));

   for(int i=0; i<n+1; i++) {

        for(int j=0; j<sum+1; j++) {
            if(j == 0)
                b[i][j] = true;
            if(i == 0)
                b[i][j] = false;
            if( weights[i-1] <= j) {
                b[i][j] = (b[i-1][j - weights[i-1]] || b[i-1][j]);
            }
            else
                b[i][j] = b[i-1][j];
        }
   }



   cout<<b[n][sum]<<endl;

   for(int i=0; i<=n; i++) {

       for(int j=0; j<=sum; j++) {
            cout<<b[i][j]<<" ";
       }

       cout<<endl;

   }


}
