#include<bits/stdc++.h>

using namespace std;

int a[100][100];
int b[100][100];

int ks(int weights[],int values[],int weight,int n){
    if(weight==0 || n==0)
            return 0;
    if(weights[n-1]<=weight)
        return max(values[n-1]+ks(weights,values,weight-weights[n-1],n-1),ks(weights,values,weight,n-1));
    else
        return ks(weights,values,weight,n-1);
}

int ks_dp(int weights[],int values[],int weight,int n){
    if(weight==0 || n==0)
        return a[n][weight]=0;
    if(a[n][weight]!=-1){
        return a[n][weight];
    }
    if(weights[n-1]<=weight){
        return a[n][weight] = max(values[n-1]+ks_dp(weights,values,weight-weights[n-1],n-1),ks_dp(weights,values,weight,n-1));
    }
    else
        return a[n][weight] = ks_dp(weights,values,weight,n-1);
}



int main(){

    ofstream file;

    file.open("KnapSack_rand.txt");

    srand(time(NULL));

    if(file){
        file<<25<<endl;
        for(int i=0;i<100;i++){
            file<<1+rand()%30<<" "<<5+rand()%96<<endl;
        }
    }

    file.close();


    ifstream read;
    int weights[100],values[100],n=0,weight;
    read.open("KnapSack_rand.txt");
    read>>weight;
    while(!read.eof()){
        read>>weights[n]>>values[n];
        n++;
    }



    read.close();

    for(int i=0;i<n-1;i++){
        cout<<weights[i]<<" "<<values[i]<<endl;
    }

    clock_t t;
    t = clock();

    cout<<"Your Collection Value (PR) : "<<ks(weights,values,weight,n-2)<<endl;

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout<<"Time taken For Pure Recursion : "<<time_taken<<endl;
    clock_t t2;

    t2 = clock();

    memset(a,-1,sizeof(a));

    cout<<endl<<"Your collection value (DP) : "<<ks_dp(weights,values,weight,n-2)<<endl;

    t2 = clock() - t2;
    time_taken = ((double)t2)/CLOCKS_PER_SEC;
    cout<<"Time taken For DP : "<<time_taken<<endl;

    clock_t t1;
    t1 = clock();

    cout<<endl<<"Your collection value is (Tabulation) : ";

    for(int i=1;i<=n-2;i++){
        for(int w=1;w<=weight;w++){
            if(weights[i-1]<=w){
                b[i][w] = max(values[i-1]+b[i-1][w-weights[i-1]],b[i-1][w]);
            }
            else{
                b[i][w] = b[i-1][w];
            }
        }
    }

    cout<<b[n-2][weight]<<endl;

    t1 = clock() - t1;
    time_taken = ((double)t1)/CLOCKS_PER_SEC;
    cout<<"Time taken For Tabulation : "<<time_taken<<endl;

}
