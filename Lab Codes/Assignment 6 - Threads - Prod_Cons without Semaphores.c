#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int buffer, flag=0;

void* producer(void* arg)
{
	for(int i=0; i<100; i++)
	{
		if(flag==0)
		{
			buffer = i;
			flag=1;
			sleep(1);
		}
		else
		{
			flag=1;
			sleep(1);
		}
	}
	return NULL;
}

void* consumer(void* arg)
{
	for(int i=0; i<100; i++)
	{
		if(flag==1)
		{
			printf("%d\n", buffer);
			flag=0;
			sleep(1);
		}
		else
		{
			flag=0;
			sleep(1);
		}
	}
	return NULL;
}


int main()
{
	pthread_t thread1, thread2;
	pthread_create (&thread1, NULL, producer, NULL);
	pthread_create (&thread2, NULL, consumer, NULL);
	
	pthread_join (thread1, NULL);
	pthread_join (thread2, NULL);

	printf("Both threads have ended");

	return 0;
}
