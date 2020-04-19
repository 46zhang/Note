#include <iostream>



/*
算法名称：求二进制中1的个数
算法来源：剑指Offer 面试题15
算法思想：		有多种解法
				1.将整数n与1进行&运算，判断其最后一个位是否为1，然后再右移1位，但是在右移时会受符号位的影响
					负数右移会补充1，所以不要加入移动之后的1，也就是在32位系统中，只计算前32位的1的个数
				2.以 1100为例子，当其减去1时，变成，1011,其右边的数字由0变1，然后最右边的1变为0，因此可以将
					-1前后的结果进行&运算，这样就可以计算出1的个数，比较次数与1的个数一样，能减多少1就有多少个
					1的个数

算法注意：		1.符号号判断
				2.循环终止条件
算法效率分析:	1.循环次数为Int位数，32位循环32次
				2.循环次数为n中1的个数
算法实现时间:	算法1 30min
				算法2 15min

*/

int numOf1II(int n)
{
	
	int num = 0;
	while (n)
	{
		n=(n - 1)&n;
		++num;
	}
	return num;
}

int  numOf1(int n)
{
	/*int a = -1 << 31;
	char s[300];
	_itoa_s(a, s, 2);//itoa转为二进制
	printf("二进制 %s\n", s);//s就是你转换成的数组
	*/
	int num = 0;
	int size_len = sizeof(int) * 8;
	
	int i= 0;
	while (++i<= size_len)
	{
 		if (n & 1)
			++num;
		n=n >> 1;
	}
	
	return num;
}

void  numOf1Test()
{
	int b = -63;
	char s[300];
	_itoa_s(b, s, 2);//itoa转为二进制
	printf("二进制 %s\n", s);//s就是你转换成的数组
	
	int n = -63;
	int a = numOf1(n);
	std::cout << a << std::endl;
	int c = numOf1II(n);
	std::cout << c << std::endl;
}