#include<bits/stdc++.h>

using namespace std;

struct point{
    int x,y;
};


void sortx(point p[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(p[j+1].x<p[j].x){
                 swap(p[j], p[j+1]);
//                struct point temp = p[j];
//                p[j]=p[j+1];
//                p[j+1] = temp;
            }
        }
    }
}

int distant(point p[],int i,int j){
    int dist;
    dist = sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
    return dist;

}

int distants(point strip[],int i,int j){
    int dist;
    dist = sqrt((strip[i].x-strip[j].x)*(strip[i].x-strip[j].x)+(strip[i].y-strip[j].y)*(strip[i].y-strip[j].y));
    return dist;

}

int brute(point p[],int st,int end){
    int m = INT_MAX,dist;
    for(int i=st;i<end-1;i++){
        for(int j=i+1;j<end;j++){
            dist = distant(p,i,j);
            if(dist<m)
                m = dist;
        }
    }

    return m;

}

int brutes(point strip[],int st,int end){
    int m = INT_MAX,dist;
    for(int i=st;i<end-1;i++){
        for(int j=i+1;j<end;j++){
            dist = distants(strip,i,j);
            if(dist<m)
                m = dist;
        }
    }

    return m;

}


int cp(point p[],int st,int end,int n){
    if(end-st<=2){
        int ans = brute(p,st,end); //O(n^2)
        return ans;

    }
    else{
        int mid,dl,dr,k,l=0;
        mid = st+(end-st)/2;
        dl = cp(p,st,mid-1,n); //O(n/2)
        dr = cp(p,mid+1,end,n); //O(n/2)

        k = min(dl, dr); //dl>dr?dr:dl;

        point strip[100];

        for(int i=0;i<n;i++){ //O(n)
            if(p[i].x>=p[mid].x-k && p[i].x<=p[mid].x+k){
                strip[l++] = p[i];
            }
        }
        int ds = brutes(strip,0,l); //O(n^2);


        return min(k, ds);

    }
}


int main(){
    cout<<"Enter a number : ";
    int n;
    cin>>n;
    point p[n];

    cout<<"Enter number of co-ordinates of ";
    for(int i=0;i<n;i++){
        cout<<"x and y co-ordinates : ";
        cin>>p[i].x>>p[i].y;
    }

    sortx(p,n);  //O(n^2);

    for(int i=0;i<n;i++){
        cout<<p[i].x<<", "<<p[i].y<<endl;
    }

    cout<<"minimum distance : "<<cp(p,0,n-1,n)<<endl;
}
