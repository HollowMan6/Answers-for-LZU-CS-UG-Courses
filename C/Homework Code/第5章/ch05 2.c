//������ ��2��
#include<stdio.h>
int main(void)
{
	int input;
	int i = 0;

	printf("����һ������: ");
	scanf("%d", &input);
	while (i <= 10)
	{
		printf("%d\n", input + i);
		i++;
	}

	return 0;
}