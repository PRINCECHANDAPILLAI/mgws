#include<stdio.h>

void main(){

    int n;
    int m;
    

    printf("Enter the no.of process :");
    scanf("%d",&n);
    printf("Enter the no.of instance :");
    scanf("%d",&m);

    int alloc[n][m]; 
    int max[n][m];
    int avail[n][m];
    int need[n][m];
    int process[n];
    int safe[n];
    int i;
    int j;
    printf("Enter the Allocation matrix");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
        process[i]=0;
    }
    printf("Enter the Max matrix");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter %d instance for Avail: ",m);
    for(i=0;i<m;i++){
        scanf("%d",&avail[0][i]);
     }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    int comp=0;
    int iavail=0;
    int f;
    int s=-1;
    while(comp<n){
        f=0;
        for(i=0;i<n;i++){
            if(process[i]==1)
                continue;
            
            for(j=0;j<m;j++){
                if(need[i][j]>avail[iavail][j]){
                    break;
                }
                if(j==m-1){
                    process[i]=1;
                    iavail++;
                    for(j=0;j<m;j++){
                        avail[iavail][j]=avail[iavail-1][j]+alloc[i][j];
                    }
                    comp++;
                    f=1;
                    safe[++s]=i+1;
                    break;
                    
                }

            }
            
            
           
        }
        if(f==0){
            break;
        }

    }
    printf("\n Need Matrix \n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d  ",need[i][j]);
        }
        printf("\n");
    }

   if(s==n-1){
        printf("\n Available Matrix \n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
            printf("%d  ",avail[i][j]);
            }
         printf("\n");
        }
        printf("\nsafe sequence : ");
        for(i=0;i<=s;i++){
            printf("P%d ",safe[i]);
        }


   }
   else{
       printf("\nNot in safe state!!");
   }

    


}