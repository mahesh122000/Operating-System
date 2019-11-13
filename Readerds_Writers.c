#include <pthread.h>
#include <sched.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXTHREAD 5  /* define # readers */

int id,SharedData;

void* reader();
void* writer();

sem_t rLock,wLock,x,y,z;                /* establish que */

int rc = 0,wc=0;             /* number of processes reading or wanting to */

int main()
{
    pthread_t rId[MAXTHREAD],wId[5];
    int i,k;
    
    int p[5]={1,2,3,4,5};
    sem_init(&rLock,0,1);
    sem_init(&wLock,0,1);
    sem_init(&x,0,1);
    sem_init(&y,0,1);
    sem_init(&z,0,1);
    
    
    for(i=0; i<MAXTHREAD; i++)
    {
        pthread_create(&rId[i],0,reader,&p[i]);
        
    }
    for(i=0;i<5;i++)
    pthread_create(&wId[i],0,writer,&p[i]);
    
    for(i=0;i<5;i++)
    pthread_join(wId[i],0);
    for(i=0; i<MAXTHREAD; i++)
    {
        pthread_join(rId[i],0);
    }
    
    sem_destroy (&rLock);
    sem_destroy (&wLock);
    
    
    
    return 0;
}

void* reader(void *arg)                  /* readers function to read */
{
    
    //sleep(1);
    int id = *(int*)arg;
    while(1)
    {
        
        sleep(1);
        sem_wait(&z);
        sem_wait(&rLock);
        sem_wait(&x);
        rc++;
        if(rc==1)
            sem_wait(&wLock);//1-1=0 writer process is blocked here because one reader is here
        sem_post(&x);
        sem_post(&rLock);
        sem_post(&z);//// Release readlock to let other readers to join
        
        printf("\nReader %d Read Value:%d...",id,SharedData);
        
        sem_wait(&x);//
        rc--;
        if(rc==0) // this is the last reader
            sem_post(&wLock);//to let writers to carry out writing
        sem_post(&x);
    }
    
    
    return 0;
}

int getNext()
{
    static int data=100;
    return data++;
}
void* writer(void *arg)          /* writer's function to write */
{
    while(1)
    {
        int idd=*(int *)arg;
        sem_wait(&y);
        wc++;
        if(wc==1)
        {sem_wait(&rLock);}
        sem_post(&y);//1-1=0
        sem_wait(&wLock);
        printf("\n Writer id %d is now writing...Number of readers: %d \n",idd,rc);
        SharedData = getNext();
        sem_post (&wLock);
        sem_wait(&y);
        wc--;
        if(wc==0)
            sem_post(&rLock);
        sem_post(&y);
        sleep(1);
    }
    
    return 0;
}
