#include <iostream>

/*
算法名称：用回溯法求出机器人的运动范围
算法来源：剑指Offer 面试题13
算法思想：		有多种解法
				1.使用回溯法进行判断
算法注意：		1.边界检查
				2.递归传递时注意参数的选择，不要重复不要越界
算法效率分析:	1. 使用了递归，算法效率最坏应该是O(logn)
算法实现时间:	与面试题12一共花了快3个小时实现，平均应该一道题得1个半钟，这道题写的时间长的原因
					并不是其有多难，而是在于我看错了，理解错了题目，导致一直无法ac

*/

bool smallerThanK(int rows, int cols,int index,int k)
{
	int  x = index % cols;
	int y = index / cols;
	
	return (x/10+x%10 + y/10+y%10  <= k);
}
int robotMove(int index,int k,int rows,int cols,bool *visit)
{
	visit[index] = true;
	std::cout << index << " ";
	int result = 0;
	//可以上下左右移动
	if (index - cols >= 0 && !visit[index - cols]&&true == smallerThanK( rows, cols, index - cols, k))
		result += 1+robotMove(index - cols, k, rows, cols, visit);
	if(index + cols < rows*cols && !visit[index + cols] && true==smallerThanK( rows, cols, index + cols, k))
		result += 1 + robotMove(index + cols, k, rows, cols, visit);
	if (index % cols != 0 && !visit[index -1] && true == smallerThanK(rows, cols, index - 1, k))
		result += 1 + robotMove(index - 1,k, rows, cols, visit);
	if ((index + 1) % cols!=0 && !visit[index + 1] && true == smallerThanK(rows,cols,index + 1,k))
		result += 1 + robotMove(index + 1, k, rows, cols, visit);
	return result;
}

int movingCount(int threshold, int rows, int cols)
{
	if (threshold <= 0 || rows <= 0 || cols <= 0)
		return 0;
	bool *visit = new bool[rows*cols];
	memset(visit, false, rows*cols);
	int result = 1;
	visit[0] == true;
	result+= robotMove(0,threshold, rows, cols, visit);
	delete []visit;
	return result;
	
}



int movingCountII(int threshold, int rows, int cols) {
	int m = rows;
	int n = cols;
	int k = threshold;

	if (k > m * n) {
		return m * n;
	}

	if (k >= m) {
		return m * (k - m + 1) + (k + 1 <= n ? (m + 1) * m / 2 : (m + k - n + 2) * (m - k + n - 1) / 2);
	}
	else {
		return k + 1 <= n ? (k + 1) * (k + 2) / 2 : (2 * k - n + 3) * n / 2;
	}
}

void robotMoveTest()
{
	int rows = 10, cols = 10,k=5;
	int cout=movingCount(k, rows, cols);
	int cou1=movingCountII(k, rows, cols);
	std::cout << "到达的格子个数为 :"<<cou1 << std::endl;
}