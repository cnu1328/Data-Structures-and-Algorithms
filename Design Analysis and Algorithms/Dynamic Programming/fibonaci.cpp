#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int fibo(int n){
     if(n==0 || n==1){
        return n;
     }
     return fibo(n-1)+fibo(n-2);
}

int fibo_dp(int arr[],int n){
    if(n==0 || n==1) {
        return arr[n] = n;
    }
    if(arr[n]!=-1){
        return arr[n];
    }
    else{
        return arr[n] = fibo_dp(arr,n-1)+fibo_dp(arr,n-2);
    }

}

int main(){
    int n;
    cout<<"Enter a number to find nth Fibonacci element : ";
    cin>>n;



    //Pure Recursion
    clock_t t;
    t = clock();
    cout<<"nth Fibonacci element is :"<<fibo(n-1)<<endl;
    t = clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout<<"Time taken to get "<<n<<" Fibonacci element is "<<time_taken;



    //Dynamic programming = Recursion + Memory

    int arr[n];
    for(int i=0;i<n;i++){
        arr[i] = -1; //Declare all array elements as -1
    }


    /*
    for(int i=0;i<n;i++){
        cout<<arr[i]<<", ";//To check all array values are -1
    }
    */

    clock_t t1;
    t1 = clock();
    cout<<endl<<"nth Fibonacci element is :"<<fibo_dp(arr,n-1)<<endl;
    t1 = clock()-t1;
    double time_taken1 = ((double)t1)/CLOCKS_PER_SEC;
    cout<<"Time taken to get "<<n<<" Fibonacci element is "<<time_taken1;


    //The memorization process works like this

    int a[n];
    a[0] = 0;
    a[1] = 1;
    for(int i=2;i<n;i++){
        a[i] = a[i-1]+a[i-2];
    }

    cout<<endl<<"The Fibonacci element through tabulation : ";
    cout<<a[n-1];



}
