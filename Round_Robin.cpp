//
//  main.cpp
//  os_rr
//
//  Created by Mahesh Pondugula on 22/10/19.
//  Copyright © 2019 Mahesh Pondugula. All rights reserved.
//

#include <iostream>
using namespace std;
struct scheduling
{int n,ta,ts,tsmo,st,tf,flag,cf,ex,qf;};
int a[100];
int rear=-1,front=-1;
void insert(int n)
{rear++;
    a[rear]=n;
}
int remove_n()
{front++;
    int n=a[front];
    return n;
}

int main(int argc, const char * argv[]) {
    int n;
    cout<<"enter no of process.."<<endl;
    cin>>n;
    struct scheduling s[n];
    for(int i=0;i<n;i++)
    {s[i].n=i+1;
        cout<<"enter access time and burst time.."<<endl;
        cin>>s[i].ta>>s[i].ts;
        s[i].tsmo=s[i].ts;
        s[i].flag=s[i].cf=s[i].ex=s[i].qf=0;
    }
    int count=0;
    struct scheduling temp;
    for(int i=0;i<n-1;i++)
    {for(int j=0;j<n-i-1;j++)
    {if(s[j].ta>s[j+1].ta)
    {temp=s[j];
        s[j]=s[j+1];
        s[j+1]=temp;}}}
    int time1=s[0].ta;
    int i=0,q=0;
    cout<<"enter quantum.."<<endl;
    cin>>q;
    while(count<n)
    {
        if(s[i].flag==0)
        {s[i].flag=1;
            s[i].st=time1;
        }
        if(s[i].cf!=1 && s[i].tsmo>q)
        {time1=time1+q;
            s[i].tsmo-=q;s[i].ex=1;}
        else if(s[i].cf!=1 && s[i].tsmo<=q)
        {time1+=s[i].tsmo;
            s[i].cf=1;count++;
            s[i].tf=time1;}
        int cc=0;
        for(int j=0;j<n;j++)
        {if(s[j].ta<=time1 && s[j].cf!=1 && s[j].ex!=1 && s[j].qf==0)
        {insert(s[j].n);s[j].qf=1;cc++;
        }
        }
        if(count==n)
        {break;}
        s[i].ex=0;
        if(s[i].cf!=1)
        {insert(s[i].n);s[i].qf=1;}
        int te=remove_n();
        i=te-1;
        s[i].qf=0;
    }
    for(i=0;i<n;i++)
    {cout<<s[i].n<<" "<<s[i].ta<<" "<<s[i].ts<<" "<<s[i].st<<" "<<s[i].tf<<endl;}
    return 0;
}
