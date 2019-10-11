

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cout<<"enter the no of process.."<<endl;
    cin>>n;
    int r;
    cout<<"enter no of resources..."<<endl;
    cin>>r;
    int c[n][r];
    cout<<"enter claim matrix..."<<endl;
    for(int i=0;i<n;i++)
    {cout<<"enter claim resources for process "<<i+1<<endl;
        for(int j=0;j<r;j++)
            cin>>c[i][j];}
    int a[n][r];
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
    cout<<"Entered";
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
    
    int c_a[n][r+1];
    for(int i=0;i<n;i++)
    {for(int j=0;j<r;j++)
    {c_a[i][j]=c[i][j]-a[i][j];}
    }
    
    int count1=0;
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<r;j++)
        {
            if(c_a[i][j]==0)
                count++;
        }
        if(count==r)
        {
            c[i][r]=0;
            count1++;
        }
        else
            c[i][r]=1;
    }
    
    bool flag=true;
    int flag2=0;
    int t=n-count1;
    while((t--)>0)
    {
        flag2=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            if(c_a[i][r]!=0)
            {
                for(int j=0;j<r;j++)
                {
                    if(c_a[i][j]<=av[j])
                        count++;
                }
                if(count==r)
                {
                    
                    for(int j=0;j<r;j++)
                    {
                        av[j]+=a[i][j];
                    }
                    c_a[i][r]=0;count1++;
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
            cout<<"Not Equal";
            
            break;
        }
    }
    if(flag)
    {cout<<"deadlock is not obtained..."<<endl;}
    else
        cout<<"deadlock is obtained...."<<endl;
    
    return 0;
}
