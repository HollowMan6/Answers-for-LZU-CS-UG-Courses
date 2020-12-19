#include "thread.h"
#include "stdafx.h"
#include <stdio.h> 
#include <windows.h> 
#include <iostream.h>
#include <winbase.h> 
#define THREAD_INSTANCE_NUMBER	3

//ȫ�ֱ���
int iCounter=0;

DWORD SubThreadA(void * pD)
{
	int iID=(int)pD;
	
	//���ڲ����´�
	HANDLE hCounterIn=OpenEvent(EVENT_ALL_ACCESS,FALSE,"sam sp 44");

	cout << "Thread " << iID << " begin." << endl;

	//���ó�Ϊ���ź�״̬
	Sleep(1000);
	cout << "Thread " << iID << " set event." << endl;
	SetEvent(hCounterIn);
	Sleep(1000);
	cout << "Thread " << iID << " end." << endl;
	CloseHandle(hCounterIn);
	return 0;
}

DWORD SubThreadB(void* pD)
{//�ȴ�threadA�������ڼ���ִ��
	int iID=(int)pD;
	//���ڲ����´�
	HANDLE hCounterIn=OpenEvent(EVENT_ALL_ACCESS,FALSE,"sam sp 44");

	if(WAIT_TIMEOUT == WaitForSingleObject(hCounterIn,10*1000))
	{
		cout << "Thread " << iID << " wait time out." << endl;
	}
	else
	{
		cout << "Thread " << iID << " wait ok." << endl;
	}
	CloseHandle(hCounterIn);
	return 0;
}


void main(void)
{
	HANDLE hCounter=NULL;
	if( (hCounter=OpenEvent(EVENT_ALL_ACCESS,FALSE,"sam sp 44"))==NULL)
	{
		//���û���������̴�������¼��������´��������¼�Ϊ�˹������¼�
		hCounter = CreateEvent(NULL,TRUE/*�˹�����*/,FALSE,"sam sp 44");
	}

	DWORD IDThread[THREAD_INSTANCE_NUMBER]; 
   	HANDLE hThread[THREAD_INSTANCE_NUMBER];
	int i;

    cout << "Test of manual rest event." << endl;

	//�����߳�
    cout << "CreateThread" << endl;
	for (i=0;i<THREAD_INSTANCE_NUMBER;i++)
	{
		if (i==0)
		{	// Create one SubThreadA
			hThread[i] = CreateThread(NULL, // no security attributes 
	    	     0,                           // use default stack size 
	        	 (LPTHREAD_START_ROUTINE) SubThreadA, // thread function 
	        	 (void *)i,                    // no thread function argument 
	        	 0,                       // use default creation flags 
	        	 &(IDThread[i]));              // returns thread identifier 
		
			// Check the return value for success. 
			if (hThread[i] == NULL)
				cout << "CreateThread error" << i << endl;
				else
				cout << "CreateThread: " << i << endl;
		}
		else
		{	// Create two SubThreadB
			hThread[i] = CreateThread(NULL, // no security attributes 
	    	     0,                           // use default stack size 
	        	 (LPTHREAD_START_ROUTINE) SubThreadB, // thread function 
	        	 (void *)i,                    // no thread function argument 
	        	 0,                       // use default creation flags 
	        	 &(IDThread[i]));              // returns thread identifier 
		
			// Check the return value for success. 
			if (hThread[i] == NULL)
				cout << "CreateThread error" << i << endl;
				else
				cout << "CreateThread: " << i << endl;
		}
		
	}
	//�ȴ��߳̽���
	WaitForMultipleObjects(THREAD_INSTANCE_NUMBER,hThread,TRUE,INFINITE);

	//�رվ��
	CloseHandle(hCounter);

    cout << endl << "Test of auto rest event." << endl;

	if( (hCounter=OpenEvent(EVENT_ALL_ACCESS,FALSE,"sam sp 44"))==NULL)
	{
		//���û���������̴�������¼��������´��������¼�Ϊ�Զ������¼�
		hCounter = CreateEvent(NULL,FALSE/*�Զ�����*/,FALSE,"sam sp 44");
	}

	//�����߳�
    cout << "CreateThread" << endl;
	for (i=0;i<THREAD_INSTANCE_NUMBER;i++)
	{
		if (i==0)
		{	// Create one SubThreadA
			hThread[i] = CreateThread(NULL, // no security attributes 
	    	     0,                           // use default stack size 
	        	 (LPTHREAD_START_ROUTINE) SubThreadA, // thread function 
	        	 (void *)i,                    // no thread function argument 
	        	 0,                       // use default creation flags 
	        	 &(IDThread[i]));              // returns thread identifier 
		
			// Check the return value for success. 
			if (hThread[i] == NULL)
				cout << "CreateThread error" << i << endl;
				else
				cout << "CreateThread: " << i << endl;
		}
		else
		{	// Create two SubThreadB
			hThread[i] = CreateThread(NULL, // no security attributes 
	    	     0,                           // use default stack size 
	        	 (LPTHREAD_START_ROUTINE) SubThreadB, // thread function 
	        	 (void *)i,                    // no thread function argument 
	        	 0,                       // use default creation flags 
	        	 &(IDThread[i]));              // returns thread identifier 
		
			// Check the return value for success. 
			if (hThread[i] == NULL)
				cout << "CreateThread error" << i << endl;
				else
				cout << "CreateThread: " << i << endl;
		}
		
	}

	//�ȴ��߳̽���
	WaitForMultipleObjects(THREAD_INSTANCE_NUMBER,hThread,TRUE,INFINITE);
	//�رվ��
	CloseHandle(hCounter);

	cout << "over" << endl;
   
return ;
}


