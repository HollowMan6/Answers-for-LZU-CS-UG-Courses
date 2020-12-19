#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 8000000L   //���鳤��
#define NUM_THREAD 8 //�̸߳���
#define SIZE_PER (SIZE/NUM_THREAD)//ÿ���߳�Ҫ��������鳤��
pthread_barrier_t barrier;//��������
int *a;
/*ÿ���̵߳��̴߳�����*/
void * thr_fun(void *arg)
{	long n = (long)arg;		
long i;
	for(i=n;i<n+SIZE_PER;i++) 
	{		a[i] = i;			
	}	
	printf("thread %ld done job.\n",(long)pthread_self());	
	pthread_barrier_wait(&barrier);	
	return ((void *)1);
} 
int main()
{	pthread_t tid;	
struct timeval start,end;	
long long startusec,endusec;	
double elapsed;	
int i;	
a = (int *)malloc(SIZE*sizeof(int));  //��̬��������	
pthread_barrier_init(&barrier,NULL,NUM_THREAD+1);//��ʼ���߳����ϼ���Ϊ���̸߳����������߳�	
gettimeofday(&start,NULL);//�����ʼʱ��	
for(i=0;i<NUM_THREAD;i++)	
{		pthread_create(&tid,NULL,thr_fun,(void *)(i*SIZE_PER));//�������߳�	
}
pthread_barrier_wait(&barrier);//�ȴ��������̴߳������	
gettimeofday(&end,NULL);//��ý���ʱ��	
for(i=0;i<SIZE;i++)//��ӡ��������	//
printf("%d ",a[i]);		
startusec = start.tv_sec * 1000000 +  start.tv_usec;
	endusec = end.tv_sec * 1000000 + end.tv_usec;	
	elapsed = (double)(endusec-startusec)/1000000.0;//���㴦�������ѵ�ʱ��	
	printf("sort took %.4f seconds\n",elapsed); 
	return 0;

}
