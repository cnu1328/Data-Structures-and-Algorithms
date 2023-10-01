#include<bits/stdc++.h>

using namespace std;

int a[100][100];

int bino(int n,int k){
    if(n==k || k==0)
            return 1;
    else
        return bino(n-1,k)+bino(n-1,k-1);
}

int bino_dp(int n,int k){
    if(n==k || k==0)
        return a[n][k]=1;
    else if(a[n][k]!=-1)
        return a[n][k];
    else
        return a[n][k]=bino_dp(n-1,k)+bino_dp(n-1,k-1);
}


int main(){
    int n,k;
    cout<<"Enter a number n and k of nCk to get binomial co-efficient : ";
    cin>>n>>k;

    cout<<"Binomial co-efficient with PR : "<<bino(n,k)<<endl;

    memset(a,-1,sizeof(a));
    cout<<"Binomial co-efficient with DP : "<<bino_dp(n,k)<<endl;

    cout<<"Binomial co-efficient with Tabulation : ";

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(i==j || j==0)
                a[i][j]=1;
            else
                a[i][j] = a[i-1][j]+a[i-1][j-1];
        }
    }

    cout<<a[n][k]<<endl;

}
