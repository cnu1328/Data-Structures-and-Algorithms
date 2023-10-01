#include<iostream>
#include<stack>

using namespace std;

void insertatbottom(stack<int> &st, int ele){
    if(st.empty()){
    	st.push(ele);
    	return;
    }
    int topele = st.top();
    st.pop();
    insertatbottom(st,ele);
    
    st.push(topele);
}

void reverse(stack<int> &st){
    if(st.empty()){
    	return;
    }
    int ele = st.top();
    st.pop();
    reverse(st);
    insertatbottom(st,ele);
}



int main(){
    stack<int> st;
    int t,x;
    cout<<"Enter number of values : ";
    cin>>t;
    while(t--){
        cin>>x;
        st.push(x);
   }
   reverse(st);
   while(!st.empty()){
   	cout<<st.top()<<" ";
   	st.pop();
   }
   cout<<endl;
}
