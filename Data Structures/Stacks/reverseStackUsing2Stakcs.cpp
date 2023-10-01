#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int> st;
    int t,x;
    cout<<"Enter number of values : ";
    cin>>t;
    while(t--){
        cin>>x;
        st.push(x);
   }
   stack<int> st1;
   while(!st.empty()){
        st1.push(st.top());
        st.pop();
   }

   stack<int> left;
   left = st1;
   st1 = st;
   st = left;

   while(!st.empty()){
   	cout<<st.top()<<" ";
   	st.pop();
   }
   cout<<endl;
}
