//������ ��8��
#include<stdio.h>
int main(void)
{
	const float KM_PER_MILE = 1.609;
	const float LT_PER_GALLON = 3.785;
	float miles_travelled, gallons_gas_consumed;
	float miles_per_gallon, liters_per_100km;

	printf("�������е�Ӣ�����: ");
	scanf("%f", &miles_travelled);
	printf("�������ĵļ���������: ");
	scanf("%f", &gallons_gas_consumed);

	miles_per_gallon = miles_travelled / gallons_gas_consumed;
	liters_per_100km = 100. / miles_per_gallon * LT_PER_GALLON / KM_PER_MILE;

	printf("����ÿ����: %.1f\n", miles_per_gallon);
	printf("��ÿ�ٹ���: %.1f\n", liters_per_100km);

	return 0;
}
