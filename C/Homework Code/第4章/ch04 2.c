//������ ��2��
#include<stdio.h>
int main()
{
	char name[20];
	int name_length;

	printf("�����������: ");
	scanf("%s", name);
	name_length = strlen(name);
	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("\"%*s\"\n", name_length + 3, name);

	return 0;
}