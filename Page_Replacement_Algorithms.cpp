#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter no of frames..."<<endl;
    cin>>n;
    int m;
    cout<<"enter the sequence size..."<<endl;
    cin>>m;
    int b[m];
    cout<<"enter the sequence of pages to be inserted..."<<endl;
    for(int i=0;i<m;i++)
    {cout<<"enter "<<i+1<<" page to be inserted.."<<endl;
        cin>>b[i];}
    int c;
    cout<<"enter 1. LRU 2. LFU 3. Optimal...."<<endl;
    cin>>c;
    if(c==1)
    {int a[n][3];
        for(int i=0;i<n;i++)
        {for(int j=0;j<3;j++)
            a[i][j]=0;}
        for(int i=0;i<m;i++)
        {
            bool flag1=false,flag2=false;
            for(int j=0;j<n;j++)
            {if(a[j][2]==1 && a[j][0]==b[i])
            {a[j][1]=i;flag1=true; break;}}
            if(flag1==true)
            {}
            else
            {for(int j=0;j<n;j++)
            {if(a[j][2]==0)
            {a[j][0]=b[i];
                a[j][1]=i;
                a[j][2]=1;flag2=true;break;}}
                if(flag2)
                {}
                else
                {int min=99;
                    int index=-1;
                    for(int j=0;j<n;j++)
                    {if(a[j][1]<min)
                    {min=a[j][1];
                        index=j;}}
                    a[index][0]=b[i];
                    a[index][1]=i;
                    a[index][2]=1;}}
            for(int j=0;j<n;j++)
                cout<<a[j][0]<<" ";
            cout<<endl;}}
    
    
    else if(c==2)
    {int a[n][4];
        for(int i=0;i<n;i++)
        {for(int j=0;j<4;j++)
            a[i][j]=0;}
        for(int i=0;i<m;i++)
        {
            bool flag1=false,flag2=false;
            for(int j=0;j<n;j++)
            {if(a[j][2]==1 && a[j][0]==b[i])
            {a[j][1]=i;a[j][3]++;flag1=true; break;}}
            if(flag1==true)
            {}
            else
            {for(int j=0;j<n;j++)
            {if(a[j][2]==0)
            {a[j][0]=b[i];
                a[j][1]=i;a[j][3]++;
                a[j][2]=1;flag2=true;break;}}
                if(flag2)
                {}
                else
                {int minf=99,mint=99;
                    int index=-1;
                    for(int j=0;j<n;j++)
                    {if(a[j][3]<minf)
                    {minf=a[j][3];
                        index=j;
                        mint=a[j][1];}
                    else if(minf==a[j][3])
                    {
                        if(mint>a[j][1])
                        {mint=a[j][1];
                            index=j;}}}
                    a[index][0]=b[i];
                    a[index][1]=i;
                    a[index][3]=1;
                    a[index][2]=1;}}
            for(int j=0;j<n;j++)
                cout<<a[j][0]<<" ";
            cout<<endl;}}
    else if(c==3)
    {int a[n][3];
        for(int i=0;i<n;i++)
        {for(int j=0;j<3;j++)
            a[i][j]=0;}
        for(int i=0;i<m;i++)
        {bool flag1=false,flag2=false;
            for(int j=0;j<n;j++)
            {if(a[j][2]!=0 && a[j][0]==b[i])
            {flag1=true;break;}}
            if(flag1)
            {}
            else
            {for(int j=0;j<n;j++)
            {if(a[j][2]==0)
            {a[j][0]=b[i];
                a[j][2]=1;
                flag2=true;
                break;}}
                if(flag2)
                {}
                else
                {for(int j=0;j<n;j++)
                {a[j][1]=0;
                    for(int k=i+1;k<m;k++)
                    {if(a[j][0]==b[k])
                    {a[j][1]=k;
                        break;}}
                        }
                    int index=-1;
                    int max=0;
                    for(int j=0;j<n;j++)
                    {if(a[j][1]==0)
                    {index=j;break;}}
                    if(index==-1)
                    {for(int j=0;j<n;j++)
                    {if(a[j][1]>max)
                    {max=a[j][1];index=j;}}}
                    a[index][0]=b[i];}}
            for(int j=0;j<n;j++)
                cout<<a[j][0]<<" ";
            cout<<endl;}}
    
    
    return 0;}

