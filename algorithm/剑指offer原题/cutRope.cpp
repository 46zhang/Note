#include<iostream>
/*
�㷨���ƣ�������
�㷨��Դ����ָOffer ������13
�㷨˼�룺		�㷨1��ʹ�ö�̬�滮ȥʵ�֣���һ��len���鱣����ÿ����õĽ����Ȼ����õ��ƹ�ϵʽlen[n]=len[i]*len[n-i]ȥ�ó�
					len[n]�Ľ��
				�㷨2��̰���㷨����n>=5ʱ�������ܵ��г���Ϊ3�Ķ�������Ϊ ��n>5ʱ��n*(n-3)>n,n*(n-2)>n
					��n=4ʱ��n*(n-3)��n*(n-2)һ������4

�㷨ע�⣺		1.ע�����⣬�еĶ����������һ��
�㷨Ч�ʷ���:	1.O(n*n)
				2. O(n) ʱ��Ч�ʷǳ�֮�ߣ��������ѡ�����ʵ�������Ҫ�����ж�
�㷨ʵ��ʱ��:	�㷨1 43min
				�㷨2 20min

*/

//̰���㷨ʵ��
//��n>=5ʱ���������г���Ϊ3������
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
		//�ֱ��ÿ�����ӽ�����
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