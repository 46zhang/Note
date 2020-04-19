#include <iostream>

/*
算法名称：计算数值的N整次方
算法来源：剑指Offer 面试题16
算法思想：		有多种解法
				1.正常的循环然后累乘，例如求 2的30次方需要*30次
				2. 利用公式，2 的8次方相当于 2(8)=2(4)*2(4) 2(4)=2(2)*(2) 2(2)=2*2 ，只需要计算log(n)次

算法注意：		1.边界检查,参数检查
				2.该题说明不考虑大数问题，否则需要考虑数值溢出的情况
算法效率分析:	1.n
				2.log(n)
算法实现时间:	算法1 花了半个小时实现算法
				算法2 花了20Min
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
		//如果是奇数要多乘一次
		if(exponent)
			result *= base;
		//如果exponent是负数要转变为倒数
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
	std::cout << "结果是： " << power(base, n)<< std::endl;
	std::cout << "结果是： " << result << std::endl;

}