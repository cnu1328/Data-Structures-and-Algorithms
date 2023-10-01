#include<iostream>
#include<math.h>
#include<set>

using namespace std;

int main(){

    int n;
    cout<<"Enter Number of points : ";
    cin>>n;
    int x[n],y[n];
    for(int i=0;i<n;i++){
        cout<<"Enter co-ordinate of point(x,y) "<<i+1<<" : ";
        cin>>x[i]>>y[i];
    }

    cout<<endl<<"All x co-ordinates : ";
    for(int i=0;i<n;i++){
        cout<<x[i]<<", ";
    }

    cout<<endl<<"All y co-ordinates : ";
    for(int i=0;i<n;i++){
        cout<<y[i]<<", ";
    }

    cout<<endl<<"Convex Hall points are : "<<endl;

    set<pair<int,int>> st;

    for(int i=0;i<n-1;i++){

        for(int j=i+1;j<n;j++){
            int a,b,c;
            a = y[i]-y[j];
            b = x[j]-x[i];
            c = x[i]*y[j]-x[j]*y[i];
            int np=0,nn=0;
            for(int k=0;k<n;k++){
                int l;
                if(k==i || k==j)
                    continue;
                l = a*x[k]+b*y[k]+c;
                if(l>0)
                    np++;
                else if(l<0)
                    nn++;
            }
            if(np==0 || nn==0){
                st.insert({x[i],y[i]});
                st.insert({x[j],y[j]});

            }
        }
    }

    for(auto i : st){
        cout<<"("<<i.first<<","<<i.second<<"), ";
    }

    return 0;
}
