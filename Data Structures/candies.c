#include<stdio.h>

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int a[2*n];
        for(int i=0;i<2*n;i++)
            scanf("%d",&a[i]);
        int b[n],c[n];
        
        
        
        for(int i=0;i<n;i++){
            printf("%d",c[i]);
            
        }
        printf("\n");
        
        for(int i=0;i<n;i++){
            printf("%d",b[i]);
            
        }
        
        int f =0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n-1;j++){
                
                if(b[i]==b[j+1]){
                    f=1;
                    break;
                }
            }
            
        }
        if(f==1)
            printf("NO\n");
        else
            printf("YES\n");
        
    }
    
}
