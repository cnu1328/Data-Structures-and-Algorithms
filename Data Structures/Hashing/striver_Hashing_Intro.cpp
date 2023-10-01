#include<iostream>

using namespace std;

//int hashh[100000000];

int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;

    int arr[n];
    cout<<"Enter array values : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int hashh[100000] = {0}; //taking 10 to the power 5 or 10^5;

    //computing

    for(int i=0;i<n;i++){
        hashh[arr[i]] = hashh[arr[i]]+1;
    }

    int q,num;
    cout<<"Enter a number : ";
    cin>>q;
    while(q--){
        cin>>num;
        cout<<hashh[num];
    }

}
