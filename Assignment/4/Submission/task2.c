#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

#define NUM_RUNS 10000000

void handler(void *ptr);

int counter;

int main()
{
    int i[2];
    pthread_t thread_a;
    pthread_t thread_b;

    i[0] = 0;
    i[1] = 1;

    pthread_create(&thread_a , NULL , (void *) &handler, (void *) &i[0]);
    pthread_create(&thread_b , NULL , (void *) &handler, (void *) &i[1]);

    pthread_join(thread_a , NULL);
    pthread_join(thread_b , NULL);

    printf("---------------------------------------------------------------\n");

    printf("Final counter value:     %d\n" , counter);
    printf("Error:                   %d\n" , (NUM_RUNS*2 - counter));

    exit(0);

}

void handler(void *ptr)
{
    int iter = 0;
    int thread_num;
    thread_num = *((int *) ptr);

    printf("String thread: %d \n ",  thread_num);

    while (iter < NUM_RUNS)
    {
        counter++;
        iter += 1;
    }
    
    printf("Thread %d, counter = %d \n" , thread_num , counter);
    pthread_exit(0);

}

















