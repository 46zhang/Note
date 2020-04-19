#include<iostream>
#include <vector>
#include<memory.h>
/*
算法名称：		n个骰子的点数
算法来源：		剑指Offer 面试题60
算法思想：

算法注意：		1.边界检查
				2.递归终止条件
算法效率分析:	
算法实现时间:

*/

const int gMaxValue = 6;

void coutProbility(int number,int curIndex,int sum,int *result) {
	//最后一个骰子
	if (curIndex == number) {
		result[sum - number] += 1;
	}
	else {
		for (int i = 1; i <= gMaxValue; ++i) {
			coutProbility(number, curIndex + 1, i + sum, result);
		}
	}
}

void printProbility(int number) {
	if (number <= 0)
		return;
	//申请内存，result[i]表示何为i的出现次数
	int * result = new int[gMaxValue * number - number + 1];
	//memset(result, 0, gMaxValue * number - gMaxValue + 1);
	for (int i = 0; i < gMaxValue * number - number + 1; ++i)
		result[i] = 0;
	coutProbility(number,0,0,result);
	double r = pow(gMaxValue, number);
	std::cout << r << std::endl;
	double s = 0;
	for (int i = 0; i < gMaxValue * number - number + 1; ++i) {
		double a=(double)result[i] /(double) r;
		std::cout <<" result: " <<result[i]<<" 概率： "<< a;
		s += a;
		if (i % 3 == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl<< s << std::endl;
	delete[] result;
}
//使用循环实现，效率更高
void printProbilityII(int number) {
	int *pProbility[2];
	for (int i = 0; i < 2; ++i) {
		pProbility[i] = new int[number*gMaxValue + 1];
		for (int j = 0; j < number*gMaxValue + 1; ++j)
			 pProbility[i][j]=0;
	}
	int flag = 0;
	for (int i = 1; i <= gMaxValue; ++i) {
			pProbility[flag][i] = 1;
	}
	for (int k = 2; k <= number; ++k) {
		for (int i = k; i < gMaxValue * k + 1; ++i) {
			pProbility[1 - flag][i] = 0;
			for (int j = 1; j <=gMaxValue && i - j > 0; ++j) {
				pProbility[1 - flag][i] += pProbility[flag][i - j];
			}
				
		}
		flag = 1 - flag;

	}
	double r = pow(gMaxValue, number);
	std::cout << r << std::endl;
	double s = 0;
	for (int i = 0; i < number*gMaxValue + 1; ++i) {
		double a = (double)pProbility[flag][i] / (double)r;
		std::cout << " result: " << pProbility[flag][i] << " 概率： " << a;
		s += a;
		if (i % 3 == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl << s << std::endl;

}
void probilityTest() {
	//printProbility(2);
	printProbilityII(2);
}