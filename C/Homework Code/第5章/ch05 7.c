//������ ��6��
#include<stdio.h>
double cubed(double n); // prototype declaration for cubed
int main(void)
{
	double input;
	printf("����һ����������: ");
	scanf("%lf", &input);

	printf("%.3f �������� %.3f\n", input, cubed(input));

	return 0;
}

double cubed(double n)
{
	return n * n * n;
}