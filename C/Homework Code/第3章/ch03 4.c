// �����ϰ ������ ��4��
#include <stdio.h>
int main(void)
{
	float flt_input;

	printf("Enter a floating-point value: ");
	scanf("%f", &flt_input);
	printf("Fixed-point notation: %f\n", flt_input);
	printf("Exponential notation: %e\n", flt_input);
	printf("P notation: %.2a\n", flt_input);

	return 0;
}
