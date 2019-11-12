#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

int front=-1,rear=-1;
int array[5];
sem_t mutex,emptycount,fullcount;
int p,c;
int remove();
int produce_item();
void insert_item();
void *produce()
{
    int item;
    while(1)
    {
        sleep(2);
        item=produce_item();
        sem_wait(&emptycount);
        sem_wait(&mutex);
        printf("PRODUCER produced an item:%d\n",item);
        insert_item(item);
        sem_post(&mutex);
        sem_post(&fullcount);
    }
}

void* consumer()
{
    int item;
    while(1)
    {
        sleep(2);
        sem_wait(&fullcount);
        sem_wait(&mutex);
        item=remove_item();
        printf("CONSUMER consumed an item:%d\n",item);
        sem_post(&mutex);
        sem_post(&emptycount);
    }
}

int produce_item()
{
    static int a=1;
    return a++;
}

void insert_item(int item)
{
    rear=rear+1;
    rear=rear%5;
    array[rear]=item;
}

int remove_item()
{
    front=front+1;
    front=front%5;
    int item=array[front];
    return item;
}

int main()
{
    int i;
    pthread_attr_t *attr=NULL;
    pthread_t pid,cid;
    sem_init(&mutex,0,1);
    sem_init(&emptycount,0,5);
    sem_init(&fullcount,0,0);
    pthread_create(&pid,attr,produce,0);
    pthread_create(&cid,attr,consumer,0);
    pthread_join(pid,NULL);
    pthread_join(cid,NULL);
    return 0;}


