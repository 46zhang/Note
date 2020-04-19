#include <iostream>

/*
�㷨���ƣ�������ֵ��N���η�
�㷨��Դ����ָOffer ������16
�㷨˼�룺		�ж��ֽⷨ
				1.������ѭ��Ȼ���۳ˣ������� 2��30�η���Ҫ*30��
				2. ���ù�ʽ��2 ��8�η��൱�� 2(8)=2(4)*2(4) 2(4)=2(2)*(2) 2(2)=2*2 ��ֻ��Ҫ����log(n)��

�㷨ע�⣺		1.�߽���,�������
				2.����˵�������Ǵ������⣬������Ҫ������ֵ��������
�㷨Ч�ʷ���:	1.n
				2.log(n)
�㷨ʵ��ʱ��:	�㷨1 ���˰��Сʱʵ���㷨
				�㷨2 ����20Min
*/

double power(double base,int exponent)
{
	double result=1.0;
	if (base - 0 < 0.00000001&&base-0> 0.00000001)
		return 0;
	if (exponent == 0)
		return 1;
	else if (exponent > 0)
	{
		while (exponent--) {
			result *= base;
			if (result >= DBL_MAX)
				return DBL_MAX;
			else if (result <= DBL_MIN)
				return DBL_MIN;
		}
			
	}
	else
	{
		while (exponent++) {
			result *= 1/base;
			if (result >= DBL_MAX)
				return DBL_MAX;
			else if (result <= DBL_MIN)
				return DBL_MIN;
		}
	}
	return result;
}
/*
double coutPowerN(double base, int exponent)
{
	if(exponent==)
}*/
double powerII(double base, int exponent)
{
	double result=1.0;
	bool flag = false;
	if (base - 0 < 0.00000001&&base - 0 > 0.00000001)
		return 0;
	if (exponent == 0)
		return 1;
	else {
		if (exponent < 0)
		{
			exponent *= -1;
			flag = true;
		}
		double base_n = base;
		
		while (exponent>1) {
			result = base_n * base_n;
			base_n = result;
			exponent /= 2;
		}
		//���������Ҫ���һ��
		if(exponent)
			result *= base;
		//���exponent�Ǹ���Ҫת��Ϊ����
		if (flag)
			result = 1.0 / result;
	}
	return result;
}
void powerTest()
{
	std::cout << "DBL_MAX = " << DBL_MAX << std::endl;
	std::cout << "DBL_MIN = " << DBL_MIN << std::endl;
	//double base = 2, n = -4, result = 0;
	//double base = 2, n = 4000, result = 0;
	double base = 2, n = 3, result = 0;
	result=powerII(base,n);
	std::cout << "����ǣ� " << power(base, n)<< std::endl;
	std::cout << "����ǣ� " << result << std::endl;

}