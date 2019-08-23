#include<stdio.h>
struct scheduling
{
    int tn,ta,ts,st,tf,rt,wt,tr;
    float ratio;};
int main()
{
    int n;
    printf("enter the no of process....\n");
    scanf("%d",&n);
    struct scheduling fcfs[n];
    printf("enter access time and service time...\n");
    int i=0,j=0;
    for(i=0;i<n;i++)
    {scanf("%d %d",&fcfs[i].ta,&fcfs[i].ts);
        fcfs[i].tn=i+1;
    }
    for(i=0;i<n-1;i++)
    {for(j=0;j<n-i-1;j++)
    {if(fcfs[j].ta>fcfs[j+1].ta)
    {struct scheduling temp;
        temp=fcfs[j];
        fcfs[j]=fcfs[j+1];
        fcfs[j+1]=temp;}}}
    int time=fcfs[0].ta;
    for(i=0;i<n;i++)
    {fcfs[i].st=time;
        time=time+fcfs[i].ts;
        fcfs[i].tf=time;
        fcfs[i].wt=fcfs[i].rt=fcfs[i].st-fcfs[i].ta;
        fcfs[i].tr=fcfs[i].tf-fcfs[i].ta;
        fcfs[i].ratio=(fcfs[i].tr)/fcfs[i].ts;}
    for(i=0;i<n;i++)
    {printf("%d %d %d %d %d %d %d %d %0.2f \n",fcfs[i].tn,fcfs[i].ta,fcfs[i].ts,fcfs[i].st,fcfs[i].tf,fcfs[i].rt,fcfs[i].wt,fcfs[i].tr,fcfs[i].ratio);
    }
    return 0;
}


