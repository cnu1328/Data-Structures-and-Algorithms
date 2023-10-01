#include<iostream>
#include<time.h>
#include<stdlib.h>


using namespace std;


void quick(int *p,int st,int end){
    int pivot,i,j;
    if(st<end){
        pivot = p[st];
        i = st;
        j= end;

        while(i<j){
            while(p[i]<=pivot && i<end)
                i++;
            while(p[j]>pivot)
                j--;
            if(i<j){
                int t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
        int t = p[st];
        p[st] = p[j];
        p[j] = t;

        quick(p,st,j-1);
        quick(p,j+1,end);

        }
    }



int main(){



    int n[5] = {10,100,1000,10000,100000};
    double total=0;
    for(int i=0;i<5;i++){

        int k = n[i];
        int a[k];

        srand(time(0));


        for(int j=0;j<k;j++){
            a[j] = rand()%100;
        }

        /*
        cout<<endl<<i+1<<" Array Elements : ";
        for(int j=0;j<k;j++){
            cout<<a[j]<<", ";
        }
        */



        clock_t t;
        t = clock();
        cout<<endl<<endl<<"Quick sort of array "<<i+1<<" : ";
        quick(a,0,k-1);


        t = clock()-t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
        total = total+time_taken;

        /*
        for(int j=0;j<k;j++){
            cout<<a[j]<<", ";
        }
        */



        cout<<"Time taken by sorting of "<<n[i]<<" array elements is "<<time_taken<<endl;

        cout<<endl<<endl<<endl;

    }

    cout<<"Total Time taken is : "<<total<<endl;

}

