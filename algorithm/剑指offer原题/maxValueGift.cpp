#include <iostream>
/*
算法名称：		礼物的最大价值
算法来源：		剑指Offer 面试题47
算法思想：		一开始想到的就是用回溯法，但是递归存在大量的重复计算
				采用动态规划的方法会快很多

算法注意：		1.边界检查
				2.递归终止条件
算法效率分析:	算法1时间复杂度 0(nm*nm)
				算法2时间复杂度O(nm)
算法实现时间:	花了20min实现算法2,花了17min实现算法2

*/

int maxValue(int *matrix,int n,int m) {
	if (matrix == nullptr || m <= 0 || n <= 0)
		return 0;
	int * value = new int[n*m];
	value[0] = matrix[0];
	for (int i = 1; i < n*m; ++i) {
		//第一行无法相加上一行的内容
		if (i < m) 
			value[i] = matrix[i]+value[i-1];
		else {
			if (i%m != 0 && matrix[i] + value[i - 1] > matrix[i] + value[i - m])
				value[i] = matrix[i] + value[i - 1];
			else
				value[i] = matrix[i] + value[i - m];

		}
		std::cout << "i: " << i <<"  vaule: "<< value[i] << "  ";
		if (i%m == 1)
			std::cout << std::endl;
	}
	return value[n*m - 1];
}
int maxVauleSolution2(int *matrix, int n, int m,int index) {
	if (matrix == nullptr || m <= 0 || n <= 0||index>=n*m||index<0)
		return 0;
	int value = matrix[index],left=0,down=0;
	//向左
	if ((index+1)%m != 0)
		left = maxVauleSolution2(matrix, n, m, index + 1);
	if (index < n*m)
		down = maxVauleSolution2(matrix, n, m, index + m);
	if (down > left)
		value += down;
	else
		value += left;
	return value;
}
void maxValueTest() {
	int num[16] = { 1,10,3,8,12,2,9,6,5,7,4,11,3,7,16,5 }, n = 4, m = 4;
	//int num[4] = { 1,10,3,8 }, n = 1, m = 4;
	//int num[1], n = 0, m = 0;
	//int a = maxValue(num,n,m);
	int b=maxVauleSolution2(num, n, m,0);
	//std::cout << "最大值： " << a<< std::endl;
	std::cout << "最大值： " << b << std::endl;
}