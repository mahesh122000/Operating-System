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
    struct scheduling spn[n];
    printf("enter access time and service time...\n");
    int i=0;
    for(i=0;i<n;i++)
    {scanf("%d %d",&spn[i].ta,&spn[i].ts);
        spn[i].tn=i+1;
    }
    int tt=0;
    int j=0;
    struct scheduling temp;
    for(i=0;i<n-1;i++)
    {for(j=0;j<n-i-1;j++)
    {        tt=tt+spn[j].ts;
        if(spn[j].ta>spn[j+1].ta)
        {temp=spn[j];
            spn[j]=spn[j+1];
            spn[j+1]=temp;}
        else if(spn[j].ta==spn[j+1].ta && spn[j].ts>spn[j+1].ts)
        {temp=spn[j];
            spn[j]=spn[j+1];
            spn[j+1]=temp;}}}
    int time=0;
    
    for(i=0;i<n;i++)
    {if(time>=spn[i].ta)
    {spn[i].st=time;
        time+=spn[i].ts;
        spn[i].tf=time;
        spn[i].rt=spn[i].st-spn[i].ta;
        spn[i].wt=spn[i].rt;
        spn[i].tr=spn[i].tf-spn[i].ta;
        spn[i].ratio=(spn[i].tr)/spn[i].ts;
        int countt=0;
        for(j=i+1;j<n;j++)
        {if(time>=spn[j].ta)
            countt++;}
        int min=99999;
        int x=0;
        for(j=i+1;j<=i+countt;j++)
        {if(spn[j].ts<min)
        {min=spn[j].ts;
            x=j;
        }}if(x!=0)
        {temp=spn[x];
            spn[x]=spn[i+1];
            spn[i+1]=temp;}}}
    for(i=0;i<n;i++)
    {printf("%d %d %d %d %d %d %d %d %0.2f \n",spn[i].tn,spn[i].ta,spn[i].ts,spn[i].st,spn[i].tf,spn[i].rt,spn[i].wt,spn[i].tr,spn[i].ratio);
    }
    return 0;
}

