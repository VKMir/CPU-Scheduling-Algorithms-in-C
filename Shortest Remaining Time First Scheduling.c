#include<stdio.h>
struct process{
	int id;
	int arrival;
	int burst;
	int comp;
	int tat;
	int wt;
	int rt;
	int flag;
};
int main(){
int n,i,j,q,time=0,temp,sum_wt=0,sum_tat=0,k,min,pid,count=0;
float avg_wt,avg_tat;
printf("\nNo. of processes:");
scanf("%d",&n);
printf("\nTime quantum:");
scanf("%d",&q);
struct process queue[n];
int t[n],cpu_t[n];
for(i=0;i<n;i++){
	queue[i].flag=0;
	cpu_t[i]=-1;
	
}
for(i=0;i<n;i++){
	printf("\nProcess id of process %d:",i+1);
	scanf("%d",&queue[i].id);
		printf("\nArrival time of process %d:",i+1);
	scanf("%d",&queue[i].arrival);
		printf("\nBurst time of process %d:",i+1);
	scanf("%d",&queue[i].burst);
}
for(i=0;i<n;i++){
	t[i]=queue[i].burst;
}
for(i=0;i<n;i++){
	for(j=i+1;j<n;j++){
		if(queue[i].arrival>queue[j].arrival){
			temp=queue[i].id;
			queue[i].id=queue[j].id;
			queue[j].id=temp;
			temp=queue[i].arrival;
			queue[i].arrival=queue[j].arrival;
			queue[j].arrival=temp;
			temp=queue[i].burst;
			queue[i].burst=queue[j].burst;
			queue[j].burst=temp;
			temp=t[i];
			t[i]=t[j];
			t[j]=temp;
		}
		else if(queue[i].arrival==queue[j].arrival){
			if(queue[i].burst>queue[j].burst){
				temp=queue[i].id;
			queue[i].id=queue[j].id;
			queue[j].id=temp;
			temp=queue[i].arrival;
			queue[i].arrival=queue[j].arrival;
			queue[j].arrival=temp;
			temp=queue[i].burst;
			queue[i].burst=queue[j].burst;
			queue[j].burst=temp;
			temp=t[i];
			t[i]=t[j];
			t[j]=temp;
			}
		}
	}
}
	printf("%d",time);
	if(time<queue[0].arrival){
		time=queue[0].arrival;
	}

while(count<n){
		for(j=0;j<n;j++){
	if(queue[j].flag==0&&queue[i].arrival<=time){
	min=queue[j].burst;
	pid=j;
	
	break;
}
}
k=0;
	while(k<n){
		if(queue[k].arrival<=time&&queue[k].burst<min&&queue[k].flag==0){
			min=queue[k].burst;
			pid=k;
			printf("%d",pid);
		}
		++k;
	}
	printf("pid:%d\n",pid);
	printf("queue id:%d\n",queue[pid].burst);
	printf("time before add:%d\n",time);
	printf("%d\n",time);
	if(cpu_t[pid]==-1)
	    cpu_t[pid]=time;
	if(queue[pid].burst>=q){
	time+=q;
	queue[pid].burst-=q;
	if(queue[pid].burst==0){
                queue[pid].comp=time;
                       
					   queue[pid].tat=queue[pid].comp-queue[pid].arrival;
                                sum_tat+=queue[pid].tat;
								
								queue[pid].wt=queue[pid].tat-t[pid];
                                sum_wt+=queue[pid].wt;
								queue[pid].rt=cpu_t[pid]-queue[pid].arrival;
                                queue[pid].flag=1;
                                        ++count;
}
	
}else if(queue[pid].burst>0&&queue[pid].burst<q){
        time+=queue[pid].burst;
        printf("\n%d %d",queue[pid].id,time);
        queue[pid].burst=0;
        queue[pid].comp=time;
                       
					   queue[pid].tat=queue[pid].comp-queue[pid].arrival;
                                sum_tat+=queue[pid].tat;
								
								queue[pid].wt=queue[pid].tat-t[pid];
                                sum_wt+=queue[pid].wt;
								queue[pid].rt=cpu_t[pid]-queue[pid].arrival;
                                queue[pid].flag=1;
                                        ++count;
                                    }
}
	avg_wt=(float)sum_wt/n;
avg_tat=(float)sum_tat/n;

printf("\nProcess id\t\tArrival time\t\tBurst time\t\tCompletion time\t\tTurnaround time\t\tWaiting time\t\tResponse time");
printf("\n");
for(i=0;i<n;i++){
printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",queue[i].id,queue[i].arrival,t[i],queue[i].comp,queue[i].tat,queue[i].wt,queue[i].rt);
printf("\n");
}
printf("\nAvg waiting time:%f",avg_wt);
printf("\nAvg turnaround time:%f",avg_tat);
}

