//������ ��1��
#include <stdio.h>
const int MINUTES_PER_HOUR = 60;
int main(void)
{
	int minutes;

	printf("�������: "); 
	scanf("%d", &minutes);

	while (minutes > 0)
	{
		printf("%d ������ %d Сʱ�� %d ����.\n",
			minutes,
			minutes / MINUTES_PER_HOUR, // hours
			minutes % MINUTES_PER_HOUR); // minutes

		printf("�������: "); 
		scanf("%d", &minutes);
	}

	return 0;
}