#include <stdio.h>
#include <stdlib.h>

int binary(int a[],int f,int l,int s){
    int mid;
    if(f<l){
        mid = (l+f)/2;
        if(a[mid]==s)
            return 1;
        else if(a[mid]<s)
            return binary(a,mid+1,l,s);
        else
            return binary(a,f,mid-1,s);
    }
}

void main()
{
    int n,i,j,*a;
    printf("Enter a number to enter number of elements : ");
    scanf("%d",&n);
    a= (int*)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Entered array elements : ");
    for(i=0;i<n;i++)
        printf("%d, ",*(a+i));
    //selection sort
    int min,loc;
    for(i=0;i<n;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                loc=j;
            }
        }
        int t;
        t=a[i];
        a[i]=a[loc];
        a[loc]=t;
    }
    printf("\nSorted array list : ");
    for(i=0;i<n;i++)
        printf("%d, ",a[i]);
    int l,f,mid,s;
    printf("\nEnter a number to search : ");
    scanf("%d",&s);
    /*f=0;l=n-1;
    mid=(f+l)/2;
    while(f<=l)
    {
        if(a[mid]<s)
            f=mid+1;
        else if(a[mid]==s)
        {
            printf("\nThe number %d found at position %d",s,mid+1);
            break;
        }
        else
            l=mid-1;
        mid=(f+l)/2;
    }
    if(f>l)
        printf("Not found");*/

    int r = binary(a,0,n-1,s);

    if(r==1)
        printf("Found");
    else
        printf("Not Found");


}
