#include<stdio.h>
struct process{
        int arr;
        int burst;
        int id;
        int comp;
        int tat;
        int wt;
        int rt;
        int flag;
        int priority;
};
int main(){
        int n,i,j,k,time=0,temp,pid,min,max,sum_tat=0,sum_wt=0;
        char response;
        float avg_tat,avg_wt;
        printf("\nNo. of processes:");
        scanf("%d",&n);
        printf("\nHigher the value higher the priority?(y/n): ");
        scanf(" %c",&response);
        struct process queue[n];
        for(i=0;i<n;i++){
                queue[i].flag=0;
        }
        for(i=0;i<n;i++){
        printf("\nEnter id of process %d:",i+1);
        scanf("%d",&queue[i].id);
        printf("\nEnter arrival time of process %d:",i+1);
        scanf("%d",&queue[i].arr);
        printf("\nEnter burst time of process %d:",i+1);
        scanf("%d",&queue[i].burst);
        printf("\nEnter priority of process %d:",i+1);
        scanf("%d",&queue[i].priority);
        }
        if(response=='n'){

        for(i=0;i<n;i++){
         for(j=i+1;j<n;j++){
         if(queue[i].arr>queue[j].arr){
         temp=queue[i].arr;
         queue[i].arr=queue[j].arr;
         queue[j].arr=temp;
         temp=queue[i].id;
         queue[i].id=queue[j].id;
         queue[j].id=temp;
         temp=queue[i].burst;
         queue[i].burst=queue[j].burst;
         queue[j].burst=temp;
         temp=queue[i].priority;
         queue[i].priority=queue[j].priority;
         queue[j].priority=temp;
                  }
         if(queue[i].arr==queue[j].arr){
         if(queue[i].priority>queue[j].priority){
         temp=queue[i].arr;
         queue[i].arr=queue[j].arr;
         queue[j].arr=temp;
         temp=queue[i].id;
         queue[i].id=queue[j].id;
         queue[j].id=temp;
         temp=queue[i].burst;
         queue[i].burst=queue[j].burst;
         queue[j].burst=temp;
         temp=queue[i].priority;
         queue[i].priority=queue[j].priority;
         queue[j].priority=temp;                    
         }
      }
   }
}
for(i=0;i<n;i++){
if(queue[i].arr>time){
time=queue[i].arr;
}
for(j=0;j<n;j++){
if(queue[j].flag==0){
min=queue[j].priority;
pid=j;
break;
}
}
k=0;
while(k<n){
if(queue[k].arr<=time&&queue[k].priority<min&&queue[k].flag==0){
min=queue[k].priority;
pid=k;
}
++k;
}
queue[pid].flag=1;
time+=queue[pid].burst;
queue[pid].comp=time;
queue[pid].tat=queue[pid].comp-queue[pid].arr;
sum_tat+=queue[pid].tat;
queue[pid].wt=queue[pid].tat-queue[pid].burst;
sum_wt+=queue[pid].wt;
queue[pid].rt=queue[pid].wt;
}
}else if(response=='y'){
for(i=0;i<n;i++){
         for(j=i+1;j<n;j++){
         if(queue[i].arr>queue[j].arr){
         temp=queue[i].arr;
         queue[i].arr=queue[j].arr;
         queue[j].arr=temp;
         temp=queue[i].id;
         queue[i].id=queue[j].id;
         queue[j].id=temp;
         temp=queue[i].burst;
         queue[i].burst=queue[j].burst;
         queue[j].burst=temp;
         temp=queue[i].priority;
         queue[i].priority=queue[j].priority;
         queue[j].priority=temp;
                  }
         if(queue[i].arr==queue[j].arr){
         if(queue[i].priority<queue[j].priority){
         temp=queue[i].arr;
         queue[i].arr=queue[j].arr;
         queue[j].arr=temp;
         temp=queue[i].id;
         queue[i].id=queue[j].id;
         queue[j].id=temp;
         temp=queue[i].burst;
         queue[i].burst=queue[j].burst;
         queue[j].burst=temp;
         temp=queue[i].priority;
         queue[i].priority=queue[j].priority;
         queue[j].priority=temp;
                                           
         }
      }
   }
}
for(i=0;i<n;i++){
if(queue[i].arr>time){
time=queue[i].arr;
}
for(j=0;j<n;j++){
if(queue[j].flag==0){
max=queue[j].priority;
pid=j;
break;
}
}
k=0;
while(k<n){
if(queue[k].arr<=time&&queue[k].priority>max&&queue[k].flag==0){
max=queue[k].priority;
pid=k;
}
++k;
}
queue[pid].flag=1;
time+=queue[pid].burst;
queue[pid].comp=time;
queue[pid].tat=queue[pid].comp-queue[pid].arr;
sum_tat=queue[pid].tat;
queue[pid].wt=queue[pid].tat-queue[pid].burst;
sum_wt+=queue[pid].wt;
queue[pid].rt=queue[pid].wt;
}
}
avg_tat=(float)sum_tat/n;
avg_wt=(float)sum_wt/n;
printf("Process ID\t\tArrival time\t\tBurst time\t\tPriority\t\tCompletion time\t\tTurnaround time\t\tWaiting time\t\tResponse time");
for(i=0;i<n;i++){
printf("\n");
printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t%d",queue[i].id,queue[i].arr,queue[i].burst,queue[i].priority,queue[i].comp,queue[i].tat,queue[i].wt,queue[i].rt);
}
printf("\nAvg turnaround time: %f",avg_tat);
printf("\nAvg waiting time: %f",avg_wt);
}


