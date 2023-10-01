#include<bits/stdc++.h>

using namespace std;

int b[10][10];

int mcm(int a[],int i,int j){
    if(i==j)
        return 0;
    int mini = INT_MAX,val;
    for(int k=i;k<j;k++){
        val = mcm(a,i,k)+mcm(a,k+1,j)+(a[i-1]*a[k]*a[j]);
        if(val<mini)
            mini = val;
    }
    return mini;
}

int mcm_dp(int a[],int i,int j){
    if(i==j)
        return b[i][j]=0;
    if(b[i][j]!=-1)
        return b[i][j];
    int mini = INT_MAX,val;
    for(int k=i;k<j;k++){
        val = mcm_dp(a,i,k)+mcm_dp(a,k+1,j)+a[i-1]*a[j]*a[k];
        mini = min(mini,val);
    }

    return b[i][j] = mini;
}

int main(){
    /*int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    */
    int a[] = {4,10,3,12,20,7};
    int n = sizeof(a)/sizeof(a[0]);

    cout<<"matrix chain multiplication with PR : "<<mcm(a,1,n-1)<<endl;

    memset(b,-1,sizeof(b));
    cout<<"matrix chain multiplication with DP : "<<mcm_dp(a,1,n-1)<<endl;

    cout<<"matrix chain multiplication with Tabulation : ";

    int arr[n][n];
    memset(arr,0,sizeof(arr));



    for(int k = 0; k < n; k++) {
        for(int i = 1; i < n-k; i++) {

            int j = i+k;
            int val, mini = INT_MAX;

            if(i == j){
                continue;
            }

            for(int k = i; k < j; k++) {

                val = arr[i][k] + arr[k+1][j] + a[i-1]*a[k]*a[j];

                mini = min(mini,val);
            }

            arr[i][j] = mini;
        }

    }

    cout<<arr[1][n-1]<<endl;



    /*for(int i=1; i<n-1; i++) {

                for(int j=i+1; j<n; j++) {

                    for(int k=i; k<j; k++) {

                        val = arr[i][k] + arr[k+1][j] + (a[i-1]*a[k]*a[j]);

                        mini = min(mini,val);
                    }


                }
            }

    */

    for(int i=0; i<n; i++) {
        for(int j =0;j<n;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }





    //pattern

    /*
    n = 7;
    int arr[n][n];

    memset(arr,0,sizeof(arr));
    int val = 0;

    for(int k=0; k<n; k++) {

        for(int i=0; i<n-k; i++) {
            int j = i+k;

            arr[i][j] = ++val;


        }
    }
    for(int i=0; i<5; i++) {
        for(int j =0;j<5;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    /*
    int c[n][n];
    memset(c,0,sizeof(c));
    int d=1,val=1;

    while(d<=2*n-1){
        int r,f;
        if(d%2!=0){
            r = 0;
            f = d/2;
        }

        while(f<n && r<n){
            c[r][n] = val;
            val++;
            f++;
            r++;
        }

        d++;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<c[i][j];
        }
        cout<<endl;

    }
    */


}
