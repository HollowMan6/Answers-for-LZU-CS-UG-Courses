//������ ��6��
#include<stdio.h>
int main(void)
{
	int sum, count, max_count;
	sum = 0;
	count = 1;

	printf("������Ӷ��ٸ�ƽ����? ");
	scanf("%d", &max_count);
	while (count <= max_count)
	{
		sum = sum + count * count;
		count++;
	}
	printf("ͷ %d ��ƽ������: %d\n", max_count, sum);

	return 0;
}