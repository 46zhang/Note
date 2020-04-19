#include<iostream>
/*
算法名称：剪绳子
算法来源：剑指Offer 面试题13
算法思想：		算法1：使用动态规划去实现，用一个len数组保存下每次求得的结果，然后采用递推关系式len[n]=len[i]*len[n-i]去得出
					len[n]的结果
				算法2：贪婪算法，当n>=5时，尽可能地切长度为3的段数，因为 当n>5时，n*(n-3)>n,n*(n-2)>n
					当n=4时，n*(n-3)跟n*(n-2)一样都是4

算法注意：		1.注意审题，切的段数必须大于一段
算法效率分析:	1.O(n*n)
				2. O(n) 时间效率非常之高，但是如果选择才能实现最佳需要进行判断
算法实现时间:	算法1 43min
				算法2 20min

*/

//贪婪算法实现
//当n>=5时，尽量剪切长度为3的绳子
int cutRopeByGreed(int n)
{
	int len[5] = { 0,0,1,2,4 }, max = 0, num = 1, a[5] = {0,1,2,3,4};
	if (n <= 1)
		return 0;
	else if (n <= 4)
		return len[n];
	while (n >= 5)
	{
		n -= 3;
		num*=3;
	}
	std::cout << num << "   " << a[n]<<std::endl;
	max = num * a[n];
	return max;

}

int cutRope(int n) {
	if (n <= 1)
		return 0;
	int *len = new int[n + 1], i = 0;
	memset(len, 0, n + 1);
	len[2] = 1,len[3]=2;
	for (i = 4; i <= n; ++i)
	{
		//分别对每段绳子进行求长
		for (int j = i-1; j >= i/2; --j)
		{
 			int temp1 = len[j] * len[i - j],temp2 = j * (i-j);
			int max = temp1>temp2?temp1:temp2;
			//std::cout << len[j] << "  " << len[i - j] << std::endl;;
			if (max > len[i])
				len[i] = max;
		}
	}
	int result = len[n];
	for (int i = 0; i <= n; ++i)
		std::cout << len[i] << "  ";
	std::cout<<std::endl;
	delete[] len;
	return result;
}

void cutRopeTest()
{
	cutRope(8);
	int a=cutRopeByGreed(8);
	std::cout << a << std::endl;
}