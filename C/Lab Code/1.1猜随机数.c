#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int number,ask,times = 1;
	long t;
	srand((unsigned)time(NULL));
	number = rand() % 100;
	printf("���������µ����֣�1 ~ 100��:");
	scanf("%d", &ask);
	t = time(NULL);
	while (ask!= number)
	{
		if (ask > number)printf("\n ���µ����ִ���.����������:");
		if (ask < number)printf("\n ���µ�����С��.����������:");
		scanf("%d", &ask);
		times++;
	}
	t = time(NULL)-t;
	printf("\n ��ϲ�����ش���ȷ.������%d�Σ���ʱ%d��.\n", times,t);
}