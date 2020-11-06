//
//  main.cpp
//  disk_scheduling
//
//  Created by Mahesh Pondugula on 20/10/19.
//  Copyright © 2019 Mahesh Pondugula. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,h,l,r;
    cout<<"enter the range.."<<endl;
    cin>>l>>r;
    cout<<"enter the starting position.."<<endl;
    cin>>h;
    cout<<"enter no of disk positions.."<<endl;
    cin>>n;
    int a[n][2];
    for(int i=0;i<n;i++)
    {cout<<"enter "<<i+1<<" position value.."<<endl;
        cin>>a[i][0];a[i][1]=0;
    }
    int ans=0;
    int c;
    cout<<"enter 1.SSTF 2.SCAN 3.C-SCAN...."<<endl;
    cin>>c;
    if(c==1)
    {int count=n;
        while(count--)
        {int min=999;
            int index=-1;
            for(int i=0;i<n;i++)
            {if(a[i][1]!=1 && abs(a[i][0]-h)<min)
            {min=abs(a[i][0]-h);
                index=i;
            }}
            ans+=abs(a[index][0]-h);
            h=a[index][0];
            a[index][1]=1;
        }
    }
    else if(c==2)
    {for(int i=0;i<n-1;i++)
        {for(int j=0;j<n-i-1;j++)
        {if(a[j][0]>a[j+1][0])
        {int temp=a[j][0];
            a[j][0]=a[j+1][0];
            a[j+1][0]=temp;
        }}}
        int index=-1;
        for(int i=0;i<n;i++)
        {if(a[i][0]>=h)
        {index=i;break;}}
        for(int i=index;i<n;i++)
        {ans+=abs(a[i][0]-h);
            h=a[i][0];}
        ans+=r-h;
        h=r;
        for(int i=index-1;i>=0;i--)
        {ans+=abs(a[i][0]-h);
            h=a[i][0];
            }}
    else if(c==3)
    {for(int i=0;i<n-1;i++)
    {for(int j=0;j<n-i-1;j++)
    {if(a[j][0]>a[j+1][0])
    {int temp=a[j][0];
        a[j][0]=a[j+1][0];
        a[j+1][0]=temp;
    }}}
        int index=-1;
        for(int i=0;i<n;i++)
        {if(a[i][0]>=h)
        {index=i;break;}}
        for(int i=index;i<n;i++)
        {ans+=abs(a[i][0]-h);
            h=a[i][0];}
        ans+=r-h;
        h=l;
        for(int i=0;i<index;i++)
        {ans+=abs(a[i][0]-h);
            h=a[i][0];
        }}
    cout<<"total distance travelled is.."<<ans<<endl;
    return 0;
}
