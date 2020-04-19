#include <iostream>
/*
算法名称：		求斐波拉契数列
算法来源：		剑指Offer 面试题10
算法思想：		有多种解法
				1.递归
				2.递推，有点类似动态规划
算法注意：		1.递推式的实现
				2.
算法效率分析:	1 
算法实现时间:	
*/

int jumpFloorII(int number) {
	int result = 1,pre_result = 3;
	if (number <= 2)
		return number;
	for (int i = 3; i <= number; ++i)
	{
		result = pre_result+1;
		pre_result += result;
	}
	return result;
}
long long frogStep(int n)
{
	if (n <= 0)
		return 0;
	int pre1 = 1, pre2 = 2, cur = 0;
	for (int i = 3; i <= n; ++i)
	{
		cur = pre1 + pre2;
		pre1 = pre2 ;
		pre2 = cur;
		
	}
	
	return cur;
}
long long fibonacci(int n)
{
	if (n <= 0)
		return 0;
	int * num = new int[n+1];
	//int *num = (int *)malloc(sizeof(int)*(n + 1));
	for (int i = 1; i <= n; ++i)
	{
		if (1 == i || 2 == i)
			num[i] = 1;
		else
			num[i] = num[i - 1] + num[i - 2];
	}
	for (int i = 1; i <= n; ++i)
		std::cout << num[i]<<"  ";
	std::cout << std::endl;
	int a = num[n];
 	delete num;
	return a;
}

void fibonacciTest()
{
	long long a=fibonacci(4);
	std::cout << a;
	std::cout << std::endl;
	long long b= frogStep(5);
	std::cout << b;
	std::cout << std::endl;
	long long c = jumpFloorII(6);
	std::cout << c;
	std::cout << std::endl;
}