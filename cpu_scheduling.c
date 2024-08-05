#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int main()
{
int choice;
while(true){
printf("\nEnter your choice: 1.FCFS 2.SJF 3.Priority 4.Round Robin 5.Exit\n");
scanf("%d",&choice);
switch(choice){
case 1:
{
int limit,i,tot_tat=0,tot_wt=0;
float avg_wt,avg_tat;
printf("Enter the no. of process\n");
scanf("%d",&limit);

int p[limit],wt[limit],tat[limit],bt[limit];
printf("\nEnter the process and burst time respectively\n");
for(i=0;i<limit;i++)
{
scanf("%d",&p[i]);
scanf("%d",&bt[i]);
}

for(i=0;i<limit;i++)
{
if(i==0)
{
wt[i]=0;
tat[i]=bt[i];
tot_tat=tat[i];
}

else
{
wt[i]=wt[i-1]+bt[i-1];
tot_wt+=wt[i];
 
tat[i]=tat[i-1]+bt[i];
tot_tat+=tat[i];
}
}
printf("\nProcess  BT   WT    TAT\n");
for(i=0;i<limit;i++)
printf(" %d       %d     %d     %d\n",p[i],bt[i],wt[i],tat[i]);


printf("\nGantt chart\n");
     for (int i=0;i<limit;i++){
        printf("|  P%d  ",p[i]);
     }
     printf("|\n");
     for (int i=0;i<limit;i++){
        printf("%d      ",wt[i]);
     }
     printf("%d\n\n",tat[limit-1]);
     
     
printf("Total turn around time is %d\n",tot_tat);
printf("Total waiting time is %d\n",tot_wt);

avg_wt=tot_wt/(float)limit;
avg_tat=tot_tat/(float)limit;

printf("Average waiting time is %f\n",avg_wt);
printf("Average turn around time is %f\n",avg_tat);
break;
}

case 2:
{
int limit,i,tot_tat=0,tot_wt=0,j,temp;
float avg_wt,avg_tat;
printf("Enter the no. of process\n");
scanf("%d",&limit);

int p[limit],wt[limit],tat[limit],bt[limit];
printf("\nEnter the process and burst time respectively\n");
for(i=0;i<limit;i++)
{
scanf("%d",&p[i]);
scanf("%d",&bt[i]);
}

for(i=0;i<limit;i++)
{
for(j=i+1;j<limit;j++)
{
if(bt[i]>bt[j])
{
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;

temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}

for(i=0;i<limit;i++)
{
if(i==0)
{
wt[i]=0;
tat[i]=bt[i];
tot_tat=tat[i];
}

else
{
wt[i]=wt[i-1]+bt[i-1];
tot_wt+=wt[i];
 
tat[i]=tat[i-1]+bt[i];
tot_tat+=tat[i];
}
}
printf("\nProcess  BT   WT    TAT\n");
for(i=0;i<limit;i++)
printf(" %d       %d     %d     %d\n",p[i],bt[i],wt[i],tat[i]);


printf("\nGantt chart\n");
     for (int i=0;i<limit;i++){
        printf("|  P%d  ",p[i]);
     }
     printf("|\n");
     for (int i=0;i<limit;i++){
        printf("%d      ",wt[i]);
     }
     printf("%d\n\n",tat[limit-1]);
     
     
printf("Total turn around time is %d\n",tot_tat);
printf("Total waiting time is %d\n",tot_wt);

avg_wt=tot_wt/(float)limit;
avg_tat=tot_tat/(float)limit;

printf("Average waiting time is %f\n",avg_wt);
printf("Average turn around time is %f\n",avg_tat);
break;
}

case 3:
{
int limit,i,tot_tat=0,tot_wt=0,j,temp;
float avg_wt,avg_tat;
printf("Enter the no. of process\n");
scanf("%d",&limit);

int pri[limit],p[limit],wt[limit],tat[limit],bt[limit];
printf("\nEnter the process burst time and priority respectively\n");
for(i=0;i<limit;i++)
{
scanf("%d",&p[i]);
scanf("%d",&bt[i]);
scanf("%d",&pri[i]);
}


for(i=0;i<limit;i++)
{
for(j=i+1;j<limit;j++)
{
if(pri[i]>pri[j])
{
temp=pri[i];
pri[i]=pri[j];
pri[j]=temp;

temp=p[i];
p[i]=p[j];
p[j]=temp;

temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
}
}
}

for(i=0;i<limit;i++)
{
if(i==0)
{
wt[i]=0;
tat[i]=bt[i];
tot_tat=tat[i];
}

else
{
wt[i]=wt[i-1]+bt[i-1];
tot_wt+=wt[i];
 
tat[i]=tat[i-1]+bt[i];
tot_tat+=tat[i];
}
}
printf("\nProcess  BT   WT    TAT    PRIORITY\n");
for(i=0;i<limit;i++)
printf(" %d       %d     %d     %d     %d\n",p[i],bt[i],wt[i],tat[i],pri[i]);


printf("\nGantt chart\n");
     for (int i=0;i<limit;i++){
        printf("|  P%d  ",p[i]);
     }
     printf("|\n");
     for (int i=0;i<limit;i++){
        printf("%d      ",wt[i]);
     }
     printf("%d\n\n",tat[limit-1]);
     
     
printf("Total turn around time is %d\n",tot_tat);
printf("Total waiting time is %d\n",tot_wt);

avg_wt=tot_wt/(float)limit;
avg_tat=tot_tat/(float)limit;

printf("Average waiting time is %f\n",avg_wt);
printf("Average turn around time is %f\n",avg_tat);
break;
}

case 4:
{
int limit,tot_wt=0,tot_tat=0,tq,total=0,completed=0;
float avg_wt,avg_tat;
printf("Enter the number of processes\n");
scanf("%d",&limit);
printf("Enter the time quantum\n");
scanf("%d",&tq);

int p[limit],wt[limit],tat[limit],bt[limit],remaining_bt[limit];
printf("Enter the processes and their corresponding burst time\n");
for(int i=0;i<limit;i++)
{
scanf("%d",&p[i]);
scanf("%d",&bt[i]);
remaining_bt[i]=bt[i];
}
int ar[50],k=1;
ar[0]=0;

printf("Gantt Chart\n ");
while(completed<limit)
{
for(int i=0;i<limit;i++)
{
if(remaining_bt[i]>0)
{
if(remaining_bt[i]>tq)
{
printf(" P%d |",p[i]);
remaining_bt[i]=remaining_bt[i]-tq;
total=total+tq;
}
else
{
printf(" P%d |",p[i]);
total=total+remaining_bt[i];
wt[i]=total-bt[i];
tat[i]=total;
remaining_bt[i]=0;
completed++;
}
ar[k]=total;
k++;
}
}
}
printf("\n");
for(int j=0;j<k;j++)
{
printf("%d    ",ar[j]);
}
printf("\n\n");

for(int i=0;i<limit;i++)
{
tot_wt+=wt[i];
tot_tat+=tat[i];
}

avg_wt=tot_wt/(float)limit;
avg_tat=tot_tat/(float)limit;

printf("\nProcess  BT   WT    TAT\n");
for(int i=0;i<limit;i++)
printf(" %d       %d     %d     %d\n",p[i],bt[i],wt[i],tat[i]);

printf("Total turn around time is %d\n",tot_tat);
printf("Total waiting time is %d\n",tot_wt);

printf("Average waiting time is %f\n",avg_wt);
printf("Average turn around time is %f\n",avg_tat);
break;
}

default:
{
exit(0);
}
}
}
}

