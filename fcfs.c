#include<stdio.h>
struct process{
	int id;
	int arrival;
	int burst;
	int comp;
	int tat;
	int wt;
	int rt;
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
int n,i,j,time=0,temp,sum_wt=0,sum_tat=0;
float avg_wt,avg_tat;
printf("\nNo. of processes:");
scanf("%d",&n);
struct process queue[n];
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
			if(queue[i].id>queue[j].id){
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
for(i=0;i<n;i++){
	if(time<queue[i].arrival){
		time+=(queue[i].arrival-time);
	}
	time+=queue[i].burst;
	queue[i].comp=time;
	queue[i].tat=queue[i].comp-queue[i].arrival;
	sum_tat+=queue[i].tat;
	queue[i].wt=queue[i].tat-queue[i].burst;
	sum_wt+=queue[i].wt;
		printf("%d",sum_wt);
	queue[i].rt=queue[i].wt;
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
