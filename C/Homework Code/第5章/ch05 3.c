//������ ��3��
#include<stdio.h>
const int DAYS_PER_WEEK = 7;
int main(void)
{
	int days;

	printf("��������(�������� 0 �˳�): ");
	scanf("%d", &days);
	while (days > 0)
	{
		printf("%d days are %d weeks, %d days.\n", days, days / DAYS_PER_WEEK,
			days % DAYS_PER_WEEK);

		printf("��������(�������� 0 �˳�): ");
		scanf("%d", &days);
	}

	return 0;
}