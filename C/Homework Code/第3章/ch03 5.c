// �����ϰ ������ ��5��
#include<stdio.h>
int main(void)
{
	unsigned int SECONDS_PER_YEAR = 31560000;
	unsigned int age;

	printf("�������: ");
	scanf("%u", &age);
	printf("����� %u ����!\n", SECONDS_PER_YEAR * age);

	return 0;
}