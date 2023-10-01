#include <stdio.h>
#include <stdlib.h>
int bubble(int *p,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(p[i]>p[j])
            {
                int t;
                t=p[i];
                p[i]=p[j];
                p[j]=t;
            }
        }
    }
    printf("\nBubble sorted array : ");
    for(i=0;i<n;i++)
        printf("%d, ",p[i]);
}
int selection(int *p,int n)
{
    int min,loc,i,j;
    for(i=0;i<n;i++)
    {
        min=p[i];
        loc=i;
        for(j=i;j<n;j++)
        {
            if(p[j]<min)
            {
                min = p[j];
                loc=j;
            }
        }
        int t;
        t=p[i];
        p[i]=p[loc];
        p[loc]=t;
    }
    printf("\nSelection sort array : ");
    for(i=0;i<n;i++)
        printf("%d, ",p[i]);

}
int insertion(int *p,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[j-1]>p[j])
            {
                int t;
                t=p[j-1];
                p[j-1]=p[j];
                p[j]=t;

            }
        }
    }
    printf("\nInsertion sort array : ");
    for(i=0;i<n;i++)
        printf("%d, ",p[i]);
}
void quick(int *p,int st,int end)
{
    int i,j,pivot,t;
    if(st<end)
    {
       pivot = p[st];
       i=st;
       j=end;

       while(i<j)
       {
           while(p[i]<=pivot && i<end)
               i++;
           while(p[j]>pivot)
               j--;
           if(i<j)
           {
               t=p[i];
               p[i]=p[j];
               p[j]=t;
           }
       }
       t=p[st];
       p[st]=p[j];
       p[j]=t;
       quick(p,st,j-1);
       quick(p,j+1,end);
    }
}
void merge(int *p,int st,int mid,int end)
{
    int b[20],i,j,k;
    i=k=st;
    j=mid+1;
    while(i<=mid && j<=end)
    {
        if(p[i]<=p[j])
            b[k++]=p[i++];
        else
            b[k++]=p[j++];
    }
    if(i>mid)
    {
        while(j<=end)
            b[k++]=p[j++];
    }
    else
    {
        while(i<=end)
            b[k++]=p[j++];
    }
    for(i=st;i<end;i++)
        p[i]=b[i];

}
void split(int *p,int st,int end)
{
    int mid;
    if(st<end)
    {
        mid=(st+end)/2;
        split(p,st,mid);
        split(p,mid+1,end);
        merge(p,st,mid,end);
    }
}
void main()
{
    int n,*a,i;
    printf("Enter a number to enter number of elements : ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nEntered array values : ");
    for(i=0;i<n;i++)
        printf("%d, ",a[i]);
    bubble(a,n);
    selection(a,n);
    insertion(a,n);
    quick(a,0,n-1);
    printf("\nQucik sort array values : ");
    for(i=0;i<n;i++)
        printf("%d, ",a[i]);
    split(a,0,n-1);
    printf("\nMerge sort array values : ");
    for(i=0;i<n;i++)
        printf("%d, ",a[i]);
}
