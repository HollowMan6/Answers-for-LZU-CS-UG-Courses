// �����ϰ ������ ��6��
#include <stdio.h>
int main(void)
{
	float H20_MASS = 3.0e-23;
	float GRAMS_H20_PER_QUART = 950.;
	float quarts;

	printf("����ˮ�Ŀ�����: ");
	scanf("%f", &quarts);
	printf("���� %f �������� %f ���ѵ�ˮ��.\n", quarts * GRAMS_H20_PER_QUART / H20_MASS, quarts);

	return 0;
}
