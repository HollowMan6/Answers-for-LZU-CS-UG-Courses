//������ ��9��
#include<stdio.h>
#include <stdio.h>
void Temperatures(double fahr);
int main(void)
{
	double fahr;
	printf("������򽫻��϶�תΪ���϶ȺͿ����Ķ�.\n");
	printf("����һ�����϶�(q �˳�): ");
	while (scanf("%lf", &fahr) == 1)
	{
		Temperatures(fahr); 
		printf("����һ�����϶� (q �˳�): ");
	}

	printf("����\n");
}

void Temperatures(double fahr)
{
	const double FAHR_TO_CEL_SCALE = 5.0 / 9.0;
	const double FAHR_TO_CEL_OFFSET = -32.0;
	const double CEL_TO_KEL_OFFSET = 273.16;

	double celsius = (fahr + FAHR_TO_CEL_OFFSET) * FAHR_TO_CEL_SCALE;
	double kelvin = celsius + CEL_TO_KEL_OFFSET;

	printf("%.2f ���϶ȵ��� %.2f ���϶Ȼ� %.2f �����Ķ�.\n",
		fahr, celsius, kelvin);
}