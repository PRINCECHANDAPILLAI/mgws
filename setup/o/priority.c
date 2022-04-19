#include<stdio.h>

struct Process{
    int bt;
    int tat;
    int wt;
    int prty;
    
}p[15];

void main(){
    int n;
    int qt;
    printf("Enter the no.of process :");
    scanf("%d",&n);
    int i=0;
    while(i<n){
        printf(" P%d BT :",i+1);
        scanf("%d",&p[i].bt);
        printf(" P%d Priority :",i+1);
        scanf("%d",&p[i].prty);
        i++;
    }

  
    int high=1;
    int ct=0;
    float avgWT=0;
    float avgTAT=0;
    printf("\nProcess   TAT   WT\n");
    while(high<=n){
        
        i=0;
        while(i<n){
            if(p[i].prty==high){
                ct+=p[i].bt;
                p[i].tat=ct;
                p[i].wt=p[i].tat-p[i].bt;
                avgTAT+=p[i].tat;
                avgWT+=p[i].wt;
                printf("  P%d      %d    %d\n",i+1,p[i].tat,p[i].wt);
                high++;
                break;
            }
            i++;
        }
    }
    printf("\nAverage TAT: %.2f   WT: %.2f",avgTAT/n,avgWT/n);
}