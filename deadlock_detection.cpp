

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cout<<"enter the no of process.."<<endl;
    cin>>n;
    int r;
    cout<<"enter no of resources..."<<endl;
    cin>>r;
    int rq[n][r];
    cout<<"enter request matrix..."<<endl;
    for(int i=0;i<n;i++)
    {cout<<"enter request resources for process "<<i+1<<endl;
        for(int j=0;j<r;j++)
            cin>>rq[i][j];}
    int a[n][r+1];
    cout<<"enter alloted matrix.."<<endl;
    for(int i=0;i<n;i++)
    {cout<<"enter alloted resources for process "<<i+1<<endl;
        for(int j=0;j<r;j++)
            cin>>a[i][j];}
    int rs[r];
    cout<<"enter resource matrix.."<<endl;
    for(int i=0;i<r;i++)
    {
        cin>>rs[i];
        
    }
    int sum=0;
    int av[r];
    for(int i=0;i<r;i++)
    {sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=a[j][i];
        }
        av[i]=rs[i]-sum;
    }
    
    
    int count1=0;
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<r;j++)
        {
            if(a[i][j]==0)
                count++;
        }
        if(count==r)
        {
            a[i][r]=0;
            count1++;
        }
        else
            a[i][r]=1;
    }
    int w[r];
    for(int i=0;i<r;i++)
    {w[i]=av[i];}
    bool flag=true;
    int flag2=0;
    int t=n-count1;
    while((t--)>0)
    {
        flag2=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            if(a[i][r]!=0)
            {
                for(int j=0;j<r;j++)
                {
                    if(rq[i][j]<=w[j])
                        count++;
                }
                if(count==r)
                {
                    
                    for(int j=0;j<r;j++)
                    {
                        w[j]+=a[i][j];
                    }
                    a[i][r]=0;count1++;
                    flag2=1;
                }
                
            }
        }
        if(count1==n)
        {flag=true;
            cout<<"count=";
            break;}
        
        if(flag2==0)
        {
            flag=false;
            
            break;
        }
    }
    for(int i=0;i<n;i++)
    {if(a[i][r]!=0)
    {cout<<"process id "<<i+1<<"may result to deadlock "<<endl;}}
    if(flag)
    {cout<<"deadlock free..."<<endl;}
    
    return 0;
}
