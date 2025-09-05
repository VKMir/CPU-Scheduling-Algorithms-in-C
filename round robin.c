#include<stdio.h>
struct process{
        int id;
        int arr;
        int burst;
        int comp;
        int wt;
        int tat;
        int rt;
        int flag;
};
int main(){
int n,i,j,q,time=0,count=0,t,tp,sum_wt=0,sum_tat=0;
float avg_tat,avg_wt;
printf("\nNo. of processes:");
scanf("%d",&n);
struct process queue[n];
int r_queue[n],front=-1,rear=-1;
int temp[n],cpu_t[n];
printf("\nTime quantum:");
scanf("%d",&q);
for(i=0;i<n;i++){
        printf("\nID of process %d:",i+1);
        scanf("%d",&queue[i].id);
        printf("\nArrrival time of process %d:",i+1);
                scanf("%d",&queue[i].arr);
        printf("\nBurst time  of process %d:",i+1);
                scanf("%d",&queue[i].burst);
}
for(i=0;i<n;i++){
	queue[i].flag=0;
	cpu_t[i]=-1;
}

for(i=0;i<n;i++){
        temp[i]=queue[i].burst;
}
for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
                if(queue[i].arr>queue[j].arr){
                        t=queue[i].id;
                        queue[i].id=queue[j].id;
                        queue[j].id=t;
                        t=queue[i].arr;
                        queue[i].arr=queue[j].arr;
                        queue[j].arr=t;
                        t=queue[i].burst;
                         queue[i].burst=queue[j].burst;
                         queue[j].burst=t;
                }
        }
}
//i=0;
if(time<queue[0].arr)
        time=queue[0].arr;
for(i=0;i<n;i++){
	if(queue[i].arr<=time&&queue[i].flag==0){
		rear=(rear+1)%n;
		if(front==-1)
		   front=0;
		r_queue[rear]=i;
		queue[i].flag=1;
		
		
	}
}
while(count<n){

tp=r_queue[front];
if(cpu_t[tp]==-1)
    cpu_t[tp]=time;
    printf("Time:%d",time);
queue[tp].flag=0;
if(front==rear){
	front=-1;
	rear=-1;
}else{
	front=(front+1)%n;
}
if(queue[tp].burst>=q){
time+=q;
printf("\n%d %d",queue[tp].id,time);
queue[tp].burst-=q;
for(j=0;j<n;j++){
	if(time>=queue[j].arr&&j!=tp&&queue[j].flag==0){
		rear=(rear+1)%n;
		if(front==-1)
		    front=0;
		r_queue[rear]=j;
		queue[j].flag=1;
	}
}

if(queue[tp].burst==0){
                queue[tp].comp=time;
                        queue[tp].tat=queue[tp].comp-queue[tp].arr;
                                sum_tat+=queue[tp].tat;
                                queue[tp].wt=queue[tp].tat-temp[tp];
                                sum_wt+=queue[tp].wt;
                                queue[tp].rt=cpu_t[tp]-queue[tp].arr;
                                queue[tp].flag=1;
                                        ++count;
}else{
	rear=(rear+1)%n;
r_queue[rear]=tp;
queue[tp].flag=1;
}
}
else if(queue[tp].burst>0&&queue[tp].burst<q){
        time+=queue[tp].burst;
        printf("\n%d %d",queue[tp].id,time);
        queue[tp].burst=0;
        for(j=0;j<n;j++){
	if(time>=queue[j].arr&&j!=tp&&queue[j].flag==0){
		rear=(rear+1)%n;
		if(front==-1)
		    front=0;
		r_queue[rear]=j;
		queue[j].flag=1;
	}
}
        queue[tp].comp=time;
                queue[tp].tat=queue[tp].comp-queue[tp].arr;
                sum_tat+=queue[tp].tat;
                  queue[tp].wt=queue[tp].tat-temp[tp];
                  sum_wt+=queue[tp].wt;
                  queue[tp].rt=cpu_t[tp]-queue[tp].arr;
                                ++count;
}
/*else{
	++rear;
r_queue[rear]=tp;
queue[tp].flag=1;
}*/
}
/*while(count<n){
if(time<queue[i].arr){
        time=queue[i].arr;
        ++rear;
        front=0;
        r_queue[rear]=i;
}
if(queue[i].burst>=q){
time+=q;
printf("\n%d %d",queue[i].id,time);
queue[i].burst-=q;
for(j=0;j<n;j++){
	if(time>=queue[j].burst&&j!=i&&queue[j].flag==0){
		++rear;
		if(front==-1)
		    front=0;
		r_queue[rear]=j;
		queue[j].flag=1;
	}
}

if(queue[i].burst==0){
                queue[i].comp=time;
                        queue[i].tat=queue[i].comp-queue[i].arr;
                                queue[i].wt=queue[i].tat-temp[i];
                                queue[i].flag=1;
                                        ++count;
}
}else if(queue[i].burst>0&&queue[i].burst<q){
        time+=queue[i].burst;
        printf("\n%d %d",queue[i].id,time);
        queue[i].burst=0;
        queue[i].comp=time;
                queue[i].tat=queue[i].comp-queue[i].arr;
                  queue[i].wt=queue[i].tat-temp[i];
                                ++count;
}else{
	++rear;
r_queue[rear]=i;
queue[i].flag=1;
}
i=(i+1)%n;
}*/
avg_tat=(float)sum_tat/n;
avg_wt=(float)sum_wt/n;
printf("\nProcess ID\t\t\tArrival time\t\t\tBurst time\t\t\tCompletion time\t\t\tTurnaround time\t\t\tWaiting time\t\t\tResponse time");
for(i=0;i<n;i++){
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",queue[i].id,queue[i].arr,temp[i],queue[i].comp,queue[i].tat,queue[i].wt,queue[i].rt);
}
printf("\nAvg turnaround time: %f",avg_tat);
printf("\nAvg waiting time: %f",avg_wt);
}

