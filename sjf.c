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
/*struct process queue[n];
int* swap(int arr[],int i,int j){
int temp;
temp=arr[i].arrival;
arr[i].arrival=arr[j].arrival;
arr[i].arrival=temp;
temp=arr[i].id;
arr[i].id=arr[j].id;
arr[i].id=temp;
temp=arr[i].burst;
arr[i].burst=arr[j].burst;
arr[i].burst=temp;
return arr;
}*/
int main(){
int n,i,j,time=0,temp,sum_wt=0,sum_tat=0,k,min,pid;
float avg_wt,avg_tat;
printf("\nNo. of processes:");
scanf("%d",&n);

struct process queue[n];
for(i=0;i<n;i++){
	queue[i].flag=0;
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
			//swap(queue,i,j);
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
			//swap(queue,i,j);
			}
		}
	}
}
	printf("%d",time);
for(i=0;i<n;i++){
	if(time<queue[i].arrival){
		time=queue[i].arrival;
	}
	for(j=0;j<n;j++){
	if(queue[j].flag==0){
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
	//time+=queue[pid].burst;
	printf("%d\n",time);
	/*if(time<queue[i].arrival){
		time+=(queue[i].arrival-time);
	}*/
	queue[pid].flag=1;
	time+=queue[pid].burst;
	queue[pid].comp=time;
	queue[pid].tat=queue[pid].comp-queue[pid].arrival;
	sum_tat+=queue[pid].tat;
	queue[pid].wt=queue[pid].tat-queue[pid].burst;
	sum_wt+=queue[pid].wt;
		
	queue[pid].rt=queue[pid].wt;
	}
	avg_wt=(float)sum_wt/n;
	//printf("%d",sum_wt);
avg_tat=(float)sum_tat/n;

printf("\nProcess id\t\t\tArrival time\t\t\tBurst time\t\t\tCompletion time\t\t\tTurnaround time\t\t\tWaiting time\t\t\tResponse time");
printf("\n");
for(i=0;i<n;i++){
printf("%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d",queue[i].id,queue[i].arrival,queue[i].burst,queue[i].comp,queue[i].tat,queue[i].wt,queue[i].rt);
printf("\n");
}
printf("\nAvg waiting time:%f",avg_wt);
printf("\nAvg turnaround time:%f",avg_tat);
}
