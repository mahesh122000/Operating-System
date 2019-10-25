#include<time.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

struct mainmem
{
int pn;
int sa;
};
int main()
{
int ps,fs;
int n;
printf("enter size of file..\n");
scanf("%d",&fs);
printf("enter size of page..\n");
scanf("%d",&ps);
n=fs/ps;
int i=0;
struct mainmem mm[n];
int arr[n],fr[n];
for(i=0;i<n;i++)
arr[i]=-1;
srand((unsigned)time(NULL));
for(i=0;i<n;i++)
{
int r=rand()%n;
if(arr[r]==1)
{i--;
continue;}
arr[r]=1;
fr[r]=i;
mm[i].pn=r;
mm[i].sa=i*ps;}
printf("the resultant table is as following...\n");
for(i=0;i<n;i++)
{printf("%d \t %d \n",i,mm[i].pn);}
int of,pgn;
printf("enter offset and page no for which physical address to be found...\n");
scanf("%d %d",&of,&pgn);
int phyadd=0;
phyadd=mm[fr[pgn]].sa+of;
printf("The physical address is....%d",phyadd);
return 0;}

