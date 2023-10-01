#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }


    /*
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }*/

    int q;
    cout<<"Enter q : ";
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        cout<<mp[t]<<endl;
    }
}
