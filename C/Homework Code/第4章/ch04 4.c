//������ ��4��
#include<stdio.h>
int main()
{
	const float INCHES_PER_FEET = 12;
	float height;
	char name[40];

	printf("���������: ");
	scanf("%s", name);
	printf("���Ӣ�������?: ");
	scanf("%f", &height);
	printf("%s, you are %.3f feet tall.\n", name, height / INCHES_PER_FEET);

	return 0;
}