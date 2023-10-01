#include<bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cout<<"Enter a string : "<<endl;
    getline(cin,s);

    int hash[26] = {0};

    for(int i=0;i<s.length();i++){
        hash[s[i]-'a']++;//For lower case
        //hash[s[i]-'A']++; //For Upper Case;
        //hash[s[i]]++; //For all characters;
    }

    int q;
    cin>>q;

    while(q--){
        char c;
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }
}
