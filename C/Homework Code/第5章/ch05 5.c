//������ ��5��
#include<stdio.h>
int main(void)
{
	int count, sum, max_count;
	sum = 0;
	count = 1;

	printf("������Ӷ��ٸ�����? ");
	scanf("%d", &max_count);
	while (count <= max_count)
	{
		sum = sum + count;
		count++;
	}
	printf("�� = %d\n", sum);

	return 0;
}