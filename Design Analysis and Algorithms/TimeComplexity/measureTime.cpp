#include <bits/stdc++.h>



using namespace std;

int main(){



    int n[5] = {10,100,1000,10000,100000};
    double total=0;
    for(int i=0;i<4;i++){
        int k = n[i];
        int a[k];

        srand(time(0));
        clock_t t;
        t = clock();


        for(int j=0;j<k;j++){
            a[j] = rand()%100;
        }

        /*
        cout<<endl<<i+1<<" Array Elements : ";
        for(int j=0;j<k;j++){
            cout<<a[j]<<", ";
        }
        */


    /*
        cout<<endl<<endl<<"Quick sort of array "<<i+1<<" : ";
        quick(a,0,k-1);
    */



        cout<<endl<<endl<<endl<<"Bubble Sort of array "<<i+1<<" : ";
        for(int j=0;j<k;j++){
            bool swap = false;
            for(int l=0;l<k-j-1;l++){

                if(a[l]>a[l+1]){
                    int t = a[l];
                    a[l]=a[l+1];
                    a[l+1]= t;
                    swap=true;
                }


            }
            if(swap==false)
                    break;
        }



        t = clock()-t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
        total = total+time_taken;

        /*
        for(int j=0;j<k;j++){
            cout<<a[j]<<", ";
        }
        */



        cout<<endl<<"Time taken by sorting of "<<n[i]<<" array elements is "<<fixed<<setprecision(5)<<time_taken<<endl;

        cout<<endl<<endl<<endl;

    }

    cout<<"Total Time taken is : "<<total<<endl;

}
