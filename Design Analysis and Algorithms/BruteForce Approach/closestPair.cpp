#include<iostream>
#include<math.h>

using namespace std;

struct point{
    int x,y;
};

int distant(point p[],int i,int j){
    int dist;
    dist = sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
    return dist;
}

int main(){
    int n;
    int a,b,c,d;
    cout<<"Enter a number : ";
    cin>>n;
    point p[n];
    cout<<"Enter a point co-ordinates  of: ";
    for(int i=0;i<n;i++){
        cout<<"x and y co-ordinates : ";
        cin>>p[i].x>>p[i].y;
    }
    int m = INT_MAX;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int dist = distant(p,i,j);
            if(dist<m){
                m = dist;

                a = p[i].x;
                b = p[i].y;
                c = p[j].x;
                d = p[j].y;
            }

        }
    }
    cout<<"Minimum distance of two pairs are : ("<<a<<", "<<b<<"), "<<"("<<c<<", "<<d<<") is"<<m;



}




/*

//Closest pair for two co-ordinates

int distance(int i,int j,int x[],int y[]){
    int dist;
    dist = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    return dist;
}

int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    int x[n],y[n];
    cout<<"Enter array values of x first and y second : "<<endl;
    for(int i=0;i<n;i++){
        cin>>x[i];
        cin>>y[i];
    }

    int min = INT_MAX;
    int dist =0,a,b,c,d;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            dist = distance(i,j,x,y);
            if(dist<min){
                min=dist;
                a= x[i];
                b= x[j];
                c = y[i];
                d = y[j];

            }
        }
    }
    cout<<"shortest pair is : "<<endl<<a<<" "<<c<<endl<<b<<" "<<d<<endl;

    cout<<"Minimum distance : "<<min<<endl;
}


*/

//closest pair for three co-ordinates

/*

int distance(int i,int j,int x[],int y[],int z[]){
    int dist;
    dist = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]));
    return dist;
}

int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    int x[n],y[n],z[n];
    cout<<"Enter Co-ordinate values (x,y,z) : "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i+1<<" co-ordinate points : ";
        cin>>x[i]>>y[i]>>z[i];
    }

    int min = INT_MAX;
    int dist =0,a,b,c,d,e,f;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            dist = distance(i,j,x,y,z);
            if(dist<min){
                min=dist;
                a= x[i];
                b= x[j];
                c = y[i];
                d = y[j];
                e = z[i];
                f = z[j];

            }
        }
    }
    cout<<"shortest pair is : "<<endl<<a<<" "<<c<<" "<<e<<endl<<b<<" "<<d<<" "<<f<<endl;

    cout<<"Minimum distance : "<<min<<endl;
}
*/
