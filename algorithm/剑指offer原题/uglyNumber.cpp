#include <iostream>

/*

算法名称：		丑数
算法来源：		剑指Offer 面试题49
算法思想：		用空间换时间，因为数只能被2、3、53个数字整数，所以所有丑数都是这三个的倍数，以这三个进行乘就行

算法注意：		1.边界检查
				2.递归终止条件
算法效率分析:	算法1时间复杂度O(n)
算法实现时间:	花了20min实现算法，前期的构思花了很多时间，所以写代码的时候一遍过，没有bug

*/
int min(int num2, int num3, int num5) {
	int min = num2 < num3 ? num2 : num3;
	min = min < num5 ? min : num5;
	return min;
}
int uglyNumber(int index) {
	int *num = new int[index];
	num[0] = 1;
	int *numMutil2 = num, *numMutil3 = num, *numMutil5 = num, i = 1;
	while (i < index) {
		num[i] = min(*numMutil2 * 2, *numMutil3 * 3, *numMutil5 * 5);
		while (*numMutil2 * 2 <= num[i])
			++numMutil2;
		while (*numMutil3 * 3 <= num[i])
			++numMutil3;
		while (*numMutil5 * 5 <= num[i])
			++numMutil5;
		std::cout << "i：" << i << " num[i]: " << num[i]<<std::endl;
		++i;
	}
	int result = num[i - 1];
	delete[] num;
	return result;

}
void uglyNumberTest() {
	int i = 1500;
	int a=uglyNumber(i);
	std::cout << "第 " << i << " 个丑数是: " << a << std::endl;
}