// �����ϰ ������ ��7��
#include <stdio.h>
int main(void)
{
	float CM_PER_INCH = 2.54;
	float height;

	printf("�������Ӣ�����: ");
	scanf("%f", &height);
	printf("���ܹ� %f ���׸�.\n", height * CM_PER_INCH);

	return 0;
}