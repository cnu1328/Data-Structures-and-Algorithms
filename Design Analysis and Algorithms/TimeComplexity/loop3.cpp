#include <bits/stdc++.h>



using namespace std;

int main(){



    int n[5] = {10,100,1000,10000,100000};
    for(int i=0;i<5;i++){
        int k=n[i];
        int res=0;
        clock_t t;
        t = clock();
        for(int j=0;j<k;j++){
            for(int m = 0;m<k;m++){
                for(int p=0;p<k;p++){
                    res+=j+m+p;
                }

            }

        }

        t = clock()-t;
        double time = ((double)t)/CLOCKS_PER_SEC;
        cout<<"Time taken by array "<<i+1<<" with "<<n[i]<<" element : "<<fixed<<setprecision(10)<<time;
        cout<<endl<<endl;
    }
}


