#include<stdio.h>
struct scheduling
{
    int tn,ta,ts,st,tf,rt,wt,tr,tsmo;
    int flag,cf;
    float ratio;};
int main()
{
    int n;
    int sum=0;
    printf("enter the no of process....\n");
    scanf("%d",&n);
    struct scheduling spn[n];
    int i=0;
    for(i=0;i<n;i++)
    {printf("enter access time and service time...\n");
        scanf("%d %d",&spn[i].ta,&spn[i].ts);
        spn[i].tn=i+1;
        spn[i].tsmo=spn[i].ts;
        spn[i].flag=0;
        spn[i].cf=0;
        sum+=spn[i].ts;
    }
    int q;
    printf("enter quantum..\n");
    scanf("%d",&q);
    int tt=0;
    int j=0;
    for(i=0;i<n-1;i++)
    {for(j=0;j<n-i-1;j++)
    {struct scheduling temp;
        tt=tt+spn[j].ts;
        if(spn[j].ta>spn[j+1].ta)
        {temp=spn[j];
            spn[j]=spn[j+1];
            spn[j+1]=temp;}
        else if(spn[j].ta==spn[j+1].ta && spn[j].ts>spn[j+1].ts)
        {temp=spn[j];
            spn[j]=spn[j+1];
            spn[j+1]=temp;}}}
    
    int time=spn[0].ta;
    i=0;
    while(i<n)
    {
        if(spn[i].flag==0)
        {spn[i].st=time;
            spn[i].flag=1;
           // printf("1 ");
        }
        else
        {}
        if(q<spn[i].tsmo && spn[i].cf!=1)
        {time+=q;
            spn[i].tsmo-=q;
          //  printf("2 ");
        }
        else if(spn[i].cf!=1)
        {time+=spn[i].tsmo;
            spn[i].tsmo=0;
            spn[i].tf=time;
            spn[i].cf=1;
            spn[i].rt=spn[i].st-spn[i].ta;
            spn[i].wt=spn[i].tf-spn[i].ta-spn[i].ts;
            spn[i].tr=spn[i].tf-spn[i].ta;
            i++;
            
        }
        int countt=0;
        for(j=i;j<n;j++)
        {if(time>=spn[j].ta)
            countt++;}
        int min=9999;
        int x=0;
        for(j=i;j<i+countt;j++)
        {if(spn[j].ts<min)
        {min=spn[j].ts;
            x=j;}}
        
        int counttt=0;
        
        for(j=i;j<n;j++)
        {
            if(spn[j].cf==1)
                counttt++;
        }
        i=i+counttt;
        if(x!=i && x!=0)
        {struct scheduling temp=spn[x];
        spn[x]=spn[i];
            spn[i]=temp;}
        
    }
    printf("\n");
    for(i=0;i<n;i++)
    {printf("%d %d %d %d %d %d %d %d \n",spn[i].tn,spn[i].ta,spn[i].ts,spn[i].st,spn[i].tf,spn[i].rt,spn[i].wt,spn[i].tr);
    }
    return 0;
}

