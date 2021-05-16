//#include "thread.h"
#include "stdafx.h"
#include <stdio.h> 
#include <windows.h> 
#include <iostream.h>
#include <winbase.h> 
#define THREAD_INSTANCE_NUMBER	3

//ȫ�ֱ���
int iCounter=0;
CRITICAL_SECTION criCounter;

DWORD SubThread(void * pD)
{
	int iTemp=(int)pD;
		cout << "SubThread"  << iTemp << endl;
	for(int i=0;i<6;i++)
	{
		EnterCriticalSection(&criCounter);
		int iCopy=iCounter;
		Sleep(300);
		iCounter=iCopy+1;
		printf("thread %d : %d\n",iTemp,iCounter);
	    LeaveCriticalSection(&criCounter);
	}
	return 0;
}

void main(void)
{
    cout << "CreateThread" << endl;

	// Create a thread;
	DWORD IDThread[THREAD_INSTANCE_NUMBER]; 
   	HANDLE hThread[THREAD_INSTANCE_NUMBER];
	int i;
		//�����ٽ���
		InitializeCriticalSection(&criCounter);
		//�����߳�
	for (i=0;i<THREAD_INSTANCE_NUMBER;i++)
	{
		hThread[i] = CreateThread(NULL, // no security attributes 
	         0,                           // use default stack size 
	         (LPTHREAD_START_ROUTINE) SubThread, // thread function 
	         (void *)i,                    // no thread function argument 
	         0,                       // use default creation flags 
	         &(IDThread[i]));              // returns thread identifier 
		
		// Check the return value for success. 
		if (hThread[i] == NULL)
			cout << "CreateThread error" << i << endl;
			else
			cout << "CreateThread: " << i << endl;
	
}
		//�ȴ��߳̽���
		WaitForMultipleObjects(THREAD_INSTANCE_NUMBER,hThread,TRUE,INFINITE);
		//ɾ���ٽ���
		DeleteCriticalSection(&criCounter);
		printf("\nover\n");

return ;
}

