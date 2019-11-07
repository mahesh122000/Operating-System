#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

#define N 5
#define LEFT (i+N-1)%N
#define RIGHT (i+1)%N
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int i=1;
int state[N];
sem_t mutex;
sem_t s[N];

void test(int);
void put_forks(int);
void take_forks(int);


void *philosopher (void *i)
{
    int p=*(int *)i;
    while(1){
        
        printf("philosopher %d is thinking\n",*p);
        sleep(5);
        take_forks(*p);
        printf("philosopher %d is eating\n",*p);
        sleep(5);
        put_forks(*p);
    }
}

void take_forks(int i)
{
    sem_wait(&mutex);
    state[i]=HUNGRY;
    printf("philosopher %d is hungry\n",i);
    test(i);
    sem_post(&mutex);
    sem_wait(&s[i]);
    
}
void put_forks(int i)
{
    sem_wait(&mutex);
    state[i]=THINKING;
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
    
    
}

void test(int i)
{
    if(state[i]==HUNGRY && state[LEFT]!=EATING &&state[RIGHT]!=EATING)
    {state[i]=EATING;
        sem_post(&s[i]);
    }
    
}




int main()
{
    pthread_attr_t* attr=NULL;
    pthread_t pid1,pid2,pid3,pid4,pid5;
    sem_init(&mutex,0,1);
    int p[5]={0,1,2,3,4};
    pthread_create(&pid1,attr,philosopher,(void*)&p[0]);
    pthread_create(&pid2,attr,philosopher,(void*)&p[1]);
    pthread_create(&pid3,attr,philosopher,(void*)&p[2]);
    pthread_create(&pid4,attr,philosopher,(void*)&p[3]);
    pthread_create(&pid5,attr,philosopher,(void*)&p[4]);
    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);
    pthread_join(pid3,NULL);
    pthread_join(pid4,NULL);
    pthread_join(pid5,NULL);
    return 0;
    
}
