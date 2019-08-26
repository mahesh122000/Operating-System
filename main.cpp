#include<iostream>
#include<string.h>
using namespace std;

struct process
{
    string name;
    int arti;
    int seti;
    int id;
    int setimo;
    int stti;
    int fiti;
    int tat;
    int wati;
    int reti;
    int comf;
    int readyqf;
    
    
};

int main()
{
    int n;
    cout<<"Enter the no. of processes"<<endl;
    cin>>n;
    int q;
    cout<<"Enter the quantum for processes"<<endl;
    cin>>q;
    struct process p[n];
    struct process temp;
    int i,j,k;
    int sum=0;
    int f=1;
    for(i=0;i<n;i++)
    {
        cout<<"Enter the name of process"<<endl;
        cin>>p[i].name;
        cout<<"Enter the arrival time of process"<<endl;
        cin>>p[i].arti;
        cout<<"Enter the service time of process"<<endl;
        cin>>p[i].seti;
        p[i].comf=0;
        p[i].readyqf=0;
        p[i].setimo=p[i].seti;
        sum=sum+p[i].seti;
        p[i].id=f;
        f++;
    }
    //Sorting based on the arrival time
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            
            if(p[j].arti>p[j+1].arti)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
            else if(p[j].arti==p[j+1].arti && p[j].seti>p[j+1].seti)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
            
        }
    }
    
    int z=p[0].arti;
    int rq[n];
    for(i=0;i<n;i++)
        rq[i]=-1;
    rq[0]=p[0].id;
    
    int x,m;
    
    while(z!=sum)
    {
        x=rq[0];
        for(i=0;i<n;i++)
        {
            if(p[i].id==x)
            {
                m=i;
                break;
            }
        }
        if(p[m].readyqf==0)
        {
            p[m].stti=z;
            p[m].readyqf=1;
        }
        if(p[m].setimo<=q)
        {
            p[m].comf=1;
            p[m].fiti=z+p[m].setimo;
            z=p[m].fiti;
            p[m].setimo=0;
        }
        else
        {
            p[m].setimo-=q;
            z+=q;
        }
        
        int temp=rq[0];
        int count=0;
        
        for(i=1;i<n;i++)
        {
            if(rq[i]==-1)
                break;
            else
            {
                rq[i-1]=rq[i];
                count++;
            }
        }
        int flag2=0;
        for(i=0;i<n;i++)
        {
            if(p[i].arti<=z && p[i].readyqf==0)
            {
                flag2=0;
                for(j=0;j<count;j++)
                {
                    if(p[i].id==rq[j])
                    {
                        flag2=1;
                        break;
                    }
                }
                
                if(flag2==0)
                {
                    rq[count]=p[i].id;
                    count++;
                }
                
            }
        }
        for(i=0;i<n;i++)
        {
            if(p[i].id==temp)
            {
                break;
            }
        }
        if(p[i].comf!=1)
        {
            rq[count]=p[i].id;
            count++;
        }
        for(i=count;i<n;i++)
            rq[i]=-1;
        
        
    }
    
    
    for(i=0;i<n;i++)
    {
        p[i].reti=p[i].stti-p[i].arti;
        p[i].tat=p[i].fiti-p[i].arti;
        p[i].wati=p[i].fiti-p[i].seti-p[i].arti;
    }
    cout<<"Name:"<<'\t'<<"Arrival"<<'\t'<<"Service"<<'\t'<<"Start"<<'\t'<<"Finish"<<'\t'<<"TAT"<<'\t'<<"WAIT"<<'\t'<<"RESPO"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<p[i].name<<'\t'<<p[i].arti<<'\t'<<p[i].seti<<'\t'<<p[i].stti<<'\t'<<p[i].fiti<<'\t'<<p[i].tat<<'\t'<<p[i].wati<<'\t'<<p[i].reti<<endl;
    }
    
    return 0;
}










