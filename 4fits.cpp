#include<iostream>
using namespace std;
int main()
{int t,n;
    cout<<"enter total memory size..."<<endl;
    cin>>t;
    cout<<"enter no of fragmentations..."<<endl;
    cin>>n;
    int a[n][3];
    for(int i=0;i<n;i++)
    {cout<<"enter size of "<<i+1<<"fragment.."<<endl;
        cin>>a[i][0];
        a[i][1]=0;
        a[i][2]=0;}
    int k=0;
    int count=0;
    int c;
    do
    {
        count++;
        cout<<"enter 1. first fit 2. Best fit 3. Worst fit 4.Next fit 5.Compaction 6.to end...."<<endl;
        cin>>c;
        if(c==1)
        {
            cout<<"enter the page size to be inserted in first case..."<<endl;
            int s;
            cin>>s;
            for(int i=0;i<n;i++)
            {if(a[i][1]!=1 && a[i][0]>=s)
            {a[i][1]=1;a[i][2]=count;
                cout<<"the page no: "<<count<<" is inserted in fragment no: "<<i+1<<" original size is: "<<a[i][0]<<" size remaining after allocation is: ";
                a[i][0]-=s;
                cout<<a[i][0]<<endl;
                k=i;break;}}
        }
        else if(c==2)
        {
            cout<<"enter the page size to be inserted in best case..."<<endl;
            int s;
            cin>>s;
            int index=0;
            int min=999;
            for(int i=0;i<n;i++)
            {if(a[i][1]!=1 && a[i][0]>=s)
            {int temp=a[i][0]-s;
                if(temp<min)
                {min=temp;
                    index=i;}}}
            a[index][1]=1;a[index][2]=count;
            cout<<"the page no: "<<count<<" is inserted in fragment no: "<<index+1<<" original size is: "<<a[index][0]<<" size remaining after allocation is: ";
            a[index][0]-=s;
            cout<<a[index][0]<<endl;}
        else if (c==3)
        {
            cout<<"enter the page size to be inserted in worst case..."<<endl;
            int s;
            cin>>s;
            int index=0;
            int max=0;
            for(int i=0;i<n;i++)
            {if(a[i][1]!=1 && a[i][0]>=s)
            {int temp=a[i][0]-s;
                if(temp>max)
                {max=temp;
                    index=i;}}}
            a[index][1]=1;a[index][2]=count;
            cout<<"the page no: "<<count<<" is inserted in fragment no: "<<index+1<<" original size is: "<<a[index][0]<<" size remaining after allocation is: ";
            a[index][0]-=s;
            cout<<a[index][0]<<endl;}
        else if(c==4)
        {cout<<"enter the page size to be inserted in next fit case..."<<endl;
            int s;
            cin>>s;
            for(int i=k+1;i<n;i++)
            {if(a[i][1]!=1 && a[i][0]>=s)
            {a[i][1]=1;a[i][2]=count;
                cout<<"the page no: "<<count<<" is inserted in fragment no: "<<i+1<<" original size is: "<<a[i][0]<<" size remaining after allocation is: ";
                a[i][0]-=s;
                cout<<a[i][0]<<endl;
                break;}}
        }
        else if(c==5)
        {int used=0;
            int notused=0;
            int cc=0;
            for(int i=0;i<n;i++)
            {if(a[i][1]==0)
            {cc++;}
                notused+=a[i][0];}
            used=t-notused;
            cout<<"total of "<<cc<<" fragments are not alloted..."<<endl;
            cout<<"used space is.."<<used<<"not used space is..."<<notused<<endl;}
    }
    while(c!=6);
    return 0;}
