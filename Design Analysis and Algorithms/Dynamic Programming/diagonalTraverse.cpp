#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[3][3];
    memset(a,0,sizeof(a));
    int d=1, k =1;
    int x = 1;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            a[i][j] = k++;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }


    for(int j=0; j<3; j++) {
        int i=0;

        if(i == j) {
            cout<<a[i][j]<<endl;
            continue;
        }

        int indexi = i, indexj = j;

        while(indexi-1 != j+1 && indexj-1 != i+1) {
            cout<<a[indexi][indexj]<<" ";
            indexi++;
            indexj--;

        }

        cout<<endl;




    }



//
//    for(int k=0; k<5; k++) {
//        for(int i=0; i<5-k; i++){
//            int j = i+k;
//            a[i][j] = x++;
//        }
//    }

//    while(d<2*5){
//        int r,c;
//        if(d%2!=0){
//            r=0;
//            c=d/2;
//        }
//        while(r<5 && c<5){
//            a[r][c] = k;
//            k++;
//            r++;
//            c++;
//        }
//        d++;
//    }
//
//    for(int i=0;i<5;i++){
//        for(int j=0;j<5;j++){
//            cout<<a[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
