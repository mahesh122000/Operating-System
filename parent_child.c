#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, const char * argv[]) {
    int p[2];
    int q[2];
    int a[10];
    int b[10];
    int c[10];
    pid_t pid;
    if(pipe(p)==-1)
    {printf("error...\n");}
    if(pipe(q)==-1)
    {printf("error...\n");}
    pid=fork();
    if(pid>1)
    {printf("entered in parent...\n");
        int i=0;
        for(i=0;i<10;i++)
        {printf("enter array elements...\n");
            scanf("%d",&a[i]);}
        write(p[1],a,sizeof(a));
        read(q[0],c,sizeof(c));
        for(i=0;i<10;i++)
       {printf("%d",c[i]);
           printf("\t");}
        }
    else if(pid==0)
    {printf("entered in chid...\n");
        read(p[0],b,sizeof(b));
        int i=0,j=0;
        for(i=0;i<10;i++)
        {for( j=0;j<10-i-1;j++)
            {if(b[j]>b[j+1])
            {int t=b[j];
                b[j]=b[j+1];
                b[j+1]=t;}
            }
                }
        
        for(i=0;i<10;i++)
        {printf("%d",b[i]);
            printf("\t");}

        
        write(q[1],b,sizeof(b));
        }
    else
    {printf("child is not created///\n");
    }
    
    return 0;
}
