#include<bits/stdc++.h>

using namespace std;

int a[100][878]; //Declare array globally to use in Dynamic programming


int ks(int weights[],int values[],int weight,int n){
    if(weight==0 || n==0){
        return 0;
    }
    if(weights[n-1]<=weight){
        return max(values[n-1]+ks(weights,values,weight-weights[n-1],n-1),ks(weights,values,weight,n-1));
    }
    else{
        return ks(weights,values,weight,n-1);
    }
}

int ks_dp(int weights[],int values[],int weight,int n){
    if(weight==0 || n==0)
        return a[n][weight]=0;
    if(a[n][weight] != -1){
        return a[n][weight];
    }
    if(weights[n-1]<=weight){
        return a[n][weight] = max(values[n-1]+ks_dp(weights,values,weight-weights[n-1],n-1),ks_dp(weights,values,weight,n-1));
    }
    else
        return a[n][weight] = ks_dp(weights,values,weight,n-1);
}


int main(){
    //int n=10;
    int n = 5;
    //cout<<"Enter Number of Weights and values :";
    //cin>>n;
    /*
    int weights[n] = {95,4,60,32,23,72,80,62,65,46};
    int values[n] = {55,10,47,5,4,50,8,61,85,87};
    */

    /*

    int weights[n] = {92,4,43,83,84,68,92,82,6,44,32,18,56,83,25,96,70,48,14,58};
    int  values[n] = {44,46,90,72,91,40,75,35,8,54,78,40,77,15,61,17,75,29,75,63};

    */

    int weights[n] = {5, 4, 2, 3, 6};
    int values[n] = {26, 16, 21, 15, 48};



    /*
    //This comment section used to ask the values from the user

    for(int i=0;i<n;i++){
        cout<<"Enter weight : ";
        cin>>weights[i];
        cout<<"Enter value for weight : ";
        cin>>values[i];
    }
    */

    cout<<"Your weight array : ";
    for(int i=0;i<n;i++){
        cout<<weights[i]<<", ";
    }
    cout<<endl<<"Your value array for respective weights : ";
    for(int i=0;i<n;i++){
        cout<<values[i]<<", ";
    }
    cout<<endl;
    //KnapSack using recrusion

    //int weight =269;  //295(Answer for weight 269)
    //int weight = 878; // 1024(Answer for weight 878) //directly defining values to weight;
    int weight = 9;

    //cout<<endl<<"Enter KanSack weight : ";
    //cin>>weight;
    cout<<endl<<"Your collection value is(PR) : "<<ks(weights,values,weight,n)<<endl;

    //KnapSack using Dynamic programming


    memset(a,-1,sizeof(a));

    cout<<endl<<"Your collection value is(DP) : "<<ks_dp(weights,values,weight,n)<<endl;




    //KnapSack Tabulation

    int b[n+1][weight+1];

    cout<<endl<<"Your collection value is (Tabulation) : ";

    for(int i=0;i<=n;i++){
        for(int w=0;w<=weight;w++){
            if(i==0 || w==0)
                b[i][w]=0;
            else if(weights[i-1]<=w){
                b[i][w] = max(values[i-1]+b[i-1][w-weights[i-1]],b[i-1][w]);
            }
            else{
                b[i][w] = b[i-1][w];
            }
        }
    }

    cout<<b[n][weight]<<endl;



}
