#include<stdio.h>
#include<string.h>
struct student
{
	char name[20];
	char num[20];
	char tel[12];
	long birth;
};
struct student stu[5];
void main()
{
	int k=1,i;
	char c[20];
	printf("Please input name,num,tel,birth:\n");
	
	for(i=0;i<5;i++)
		scanf("%s %s %s %ld",stu[i].name,stu[i].num,stu[i].tel,&stu[i].birth);
	printf("����Ҫ���ҵ�ѧ��:");
	scanf("%s",c);
	for(i=0;i<5;i++)
	{
		if(!strcmp(stu[i].num,c))
			{
				printf("�ҵ���ѧ�ŵ�ѧ��.\n");
				k=0;
				break;
			}
	} 
	if(k)
		printf("�����ڸ�ѧ�ŵ�ѧ��.");
}
