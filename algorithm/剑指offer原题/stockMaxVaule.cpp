#include<iostream>

/*

算法名称：		股票的最大利润
算法来源 ：		剑指Offer 面试题63
算法思想：

算法注意：
算法效率分析:
算法实现时间:

*/

int stockMaxValue(int *pNum,int len) {
	int value =0,max=0,minStock=pNum[0];

	for (int i = 1; i < len; ++i) {
		if (pNum[i] > minStock)
			value =  pNum[i] - minStock;
		else {
			minStock = pNum[i];
			value = 0;
		}
		if (max < value)
			max = value;
		std::cout << value<<"  ";
	}
	return max;
}

void stockMaxVauleTest() {
	//int num[10] = { 9,111,8,5,7,12,16,14,20 }, n = 9;
	//int num[10] = { 1,2,3,4,5,12,16,2,220 }, n = 9;
	int num[10] = { 111,22,17,16,15,12,11,5,2 }, n = 9;
	int max = stockMaxValue(num, n);
	std::cout << "股票的最大价值为： " << max<<std::endl;
}