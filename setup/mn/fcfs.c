#include<stdio.h>
void main()
{
    int  n,i,at[10],bt[10],p[10],wt[10],ct[10],tat[10],temp;
    float avg_wt,avg_tat;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    printf("Enter the Arrival time for each process\n");
    for( i=0;i<n;i++)
      {
          printf("PROCESS %d\t",i+1);
          scanf("%d",&at[i]);
          p[i]=i+1;

      }
     printf("Enter the Burst time for each process\n"); 
    for(i=0;i<n;i++)
      {
          printf("PROCESS %d\t",i+1);
          scanf("%d",&bt[i]);
      }
    for(i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(at[j]<at[i])
            {
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                 temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    }
      wt[0]=0;
      ct[0]=at[0];
      avg_wt=0;
      avg_tat=0;
       for(i=1;i<n;i++)
       {
           ct[i]=ct[i-1]+bt[i-1];
           wt[i]=(ct[i]-at[i]);
           avg_wt+=wt[i];
              if(wt[i]<0)
              {
                  wt[i]=0;
              }
       }
       for ( i = 0; i < n ; i++){

        tat[i] = bt[i] + wt[i];
        avg_tat+=tat[i];

       }
    printf("FCFS SCHEDULING\n");
    printf("PROCESS ID   ARRIVAL TIME \t  BURST TIME\t  WAITING TIME\t TURN AROUND TIME\n");
      for(i=0;i<n;i++)
    {
        printf("%d\t\t     %d\t\t      %d\t\t    %d\t\t  %d\n",p[i],at[i],bt[i],wt[i],tat[i]);
    }
    avg_wt= (float) avg_wt/n;
    avg_tat= (float) avg_tat/n;
    printf("The average waiting time is %f\n",avg_wt);
    printf("The average Turn around_time is %f",avg_tat);
}