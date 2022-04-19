#include<stdio.h>

//Shortest Job First -Scheduling Algorithm

struct Process{

        int arrival_time;
        int burst_time;
        int tat;
        int wt;
        int isTerminated;
        

}process[15];

void main(){
    int no_process; //no_of_process
    float WT_avg=0;
    float TAT_avg=0;
    
    printf("Enter the number of processes(<15) :"); // reading the no_of_process
    scanf("%d",&no_process);

    
    int current=0;
    printf("Enter the processes in the increasing order of their arrival time \n");
    for(int i=0;i<no_process;i++){

        printf("Enter the Arrival Time of Process %d :",i+1);
        scanf("%d",&process[i].arrival_time);

        printf("Enter the Burst Time of Process %d :",i+1);
        scanf("%d",&process[i].burst_time);

        process[i].isTerminated=0;
        


    }
  
  int terminated=0;
  int i=0;                                       
  int j=1;
  
  int current_time=0;
  int isFirst=1;
  int isShortest=0;
  
  while(process[0].arrival_time==process[j].arrival_time && j<no_process){
    if(process[j].burst_time<process[isShortest].burst_time){
      isShortest=j;
    }
    j++;
  }

   current_time=process[isShortest].arrival_time+process[isShortest].burst_time;
   process[isShortest].tat=current_time-process[isShortest].arrival_time;
   process[isShortest].wt=process[isShortest].tat-process[isShortest].burst_time;

   process[isShortest].isTerminated=1;
   terminated++;
   WT_avg=process[isShortest].wt;
   TAT_avg=process[isShortest].tat;
   printf("Process %d executed TAT : %d  WT: %d\n",isShortest+1,process[isShortest].tat,process[isShortest].wt);
   

  i=0;
  j=0;

  
  while(terminated<no_process){
        i=0;
          while(i<no_process){
            if(process[i].isTerminated==0){
              isShortest=i;
            break;
          }
          i++;
        }
        i=0;
         while(process[isShortest].arrival_time<current_time && i<no_process){
            if(process[i].isTerminated==0){
              if(process[i].burst_time<process[isShortest].burst_time){
                isShortest=i;
              }
            }
            i++;
         }
        current_time+= process[isShortest].burst_time;
        process[isShortest].tat=current_time-process[isShortest].arrival_time;
        process[isShortest].wt=process[isShortest].tat-process[isShortest].burst_time;

        process[isShortest].isTerminated=1;
        terminated++;
        WT_avg+=process[isShortest].wt;
        TAT_avg+=process[isShortest].tat;
        printf("Process %d executed TAT : %d  WT: %d\n",isShortest+1,process[isShortest].tat,process[isShortest].wt);



  }


    TAT_avg=TAT_avg/no_process;
    WT_avg=WT_avg/no_process;

    printf("\n Average Turn Around Time : %.2f",TAT_avg);
    printf("\n Average Waiting Time : %.2f",WT_avg);

    
}