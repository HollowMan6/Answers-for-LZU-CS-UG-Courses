// �����ϰ ������ ��7��
#include <stdio.h>
int main(void)
{
	float PINTS_PER_CUP = .5;
	float OUNCES_PER_CUP = 8;
	float TBS_PER_CUP = 2 * OUNCES_PER_CUP; 
	float TSP_PER_CUP = 3 * TBS_PER_CUP; 
	float cups;

	printf("���뱭��:");
	scanf("%f", &cups);
	printf("%f ���൱��:\n", cups);
	printf("%f Ʒ��\n", cups * PINTS_PER_CUP);
	printf("%f ��˾\n", cups * OUNCES_PER_CUP);
	printf("%f ����\n", cups * TBS_PER_CUP);
	printf("%f ����\n", cups * TSP_PER_CUP);

	return 0;
}