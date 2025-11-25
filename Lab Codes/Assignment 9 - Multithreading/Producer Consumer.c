#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int buffer[100];
int in = 0, out = 0;


int mutex = 1;
int full  = 0;
int empty = 100;


void wait(int *S) {
    while (*S <= 0);   // Busy wait
    (*S)--;
}


void signal(int *S) {
    (*S)++;
}

void* producer(void* arg)
{
    for(int i = 1; i <= 100; i++) //emmf (wwss)
    {
        wait(&empty);
        wait(&mutex); 

        buffer[in] = i;
        in++;

        signal(&mutex);
        signal(&full);
    }

    return NULL;
}

void* consumer(void* arg) //fmme (wwss)
{
    for(int i = 1; i <= 100; i++)
    {
        wait(&full);
        wait(&mutex);

        printf("%d\n", buffer[out]);
        out++;

        signal(&mutex);
        signal(&empty);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads end.\n");

    return 0;
}
