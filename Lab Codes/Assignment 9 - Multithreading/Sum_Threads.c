#include<stdio.h>
#include<pthread.h>
int arr[] = {1,2,3,4,5};
int total_sum = 0;int max_element = arr[0];
void* compute_sum(void* arg){
    int sum = 0;
    for(int i=0;i<5;i++){
        sum+=arr[i];
    }
    total_sum = sum;
    pthread_exit(NULL);
}
 
void* find_max(void*arg){
    int max = arr[0];
    for(int i=1;i<5;i++){
        if(arr[i]>max) max = arr[i];
    }
    max_element = max;
    pthread_exit(NULL);
}
int main(){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,compute_sum,NULL);
    pthread_create(&t2,NULL,find_max,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("The sum is: %d\n",total_sum);
    printf("The max element is: %d\n",max_element);
    return 0;
}
