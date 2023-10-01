#include<bits/stdc++.h>

using namespace std;

int a[100][100];

int summation(int freq[], int i, int j) {

    int sum = 0;

    for(int k = i; k <= j; k++) {
        sum += freq[k];
    }

    return sum;
}

int obst(int key[], int freq[], int i, int j) {

    if(i > j) {
        return 0;
    }

    if(i == j) {
        return freq[i];
    }

    int mini = INT_MAX,val;

    int sum = summation(freq,i,j);

    for(int k = i; k<=j; k++) {
        val = obst(key, freq, i, k-1) + obst(key, freq, k+1, j);

        mini = min(val, mini);
    }

    return mini+sum;
}

int obst_dp(int key[], int freq[], int i, int j) {

    if(i > j) {
        return a[i][j] = 0;
    }

    if(i == j) {
        return a[i][j] = freq[i];
    }

    if(a[i][j] != -1) {
        return a[i][j];
    }

    int mini = INT_MAX, val;

    int sum = summation(freq,i,j);

    for(int k =i; k<=j; k++) {
        val = obst_dp(key, freq,i,k-1) + obst_dp(key, freq,k+1,j);

        mini = min(mini, val);
    }

    return a[i][j] = mini+sum;


}


int main() {

    int n;
    cout<<"Enter a number : "<<endl;

    cin>>n;

    int key[n], freq[n];

    for(int i=0; i<n; i++) {
        cout<<"Enter key value : ";
        cin>>key[i];

    }

    for(int i=0; i<n; i++) {

        cout<<"Enter freq value : ";
        cin>>freq[i];
    }

    cout<<"Optimal binary search by (PR) : "<<obst(key, freq, 0, n-1)<<endl;

    memset(a, -1, sizeof(a));

    cout<<"Optimal binary search by (DP) : "<<obst_dp(key, freq, 0, n-1)<<endl;


    cout<<"Optimal binary search by Tabulation : ";

    int b[n+1][n+1];

    memset(b,0,sizeof(b));

    for(int l = 0; l<n; l++) {
        for(int i=0; i<n-l; i++) {
            int j = i+l;

            if(i == j) {
                b[i][j] = freq[i];
                continue;
            }


            int sum = summation(freq, i, j), mini = INT_MAX, val;

            for(int k = i; k<=j; k++) {
                if(i > k-1) {
                    val = b[k+1][j];
                }

                else if(k+1 > j) {
                    val = b[i][k-1];
                }

                else {
                    val = b[i][k-1] + b[k+1][j];
                }

                mini = min(mini, val);


            }

            b[i][j] = mini + sum;
        }
    }


    cout<<b[0][n-1]<<endl;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }




}
