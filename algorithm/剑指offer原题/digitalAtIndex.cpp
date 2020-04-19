#include <iostream>

/*
算法名称：		数字序列中的某一位数字
算法来源：		剑指Offer 面试题44
算法思想：		先找规律，再

算法注意：		1.边界检查
				2.递归终止条件

算法效率分析:	算法1时间复杂度O(nlogn)，空间复杂度O(1)
				算法2时间复杂度O(logn)，空间复杂度O(1)

算法实现时间:	花了1个小时半小时思考实现算法

*/

std::pair<int,int> indexBetweenNum(int index) {
	int time = 1, max = 10;
	while (index > max) {
		max *= 10;
		++time;
	}
	return { max,time };
}
int digitalAtIndex(int index) {
	if (index <= 0)
		return 0;
	else if (index < 10)
		return index;
	std::pair<int,int> a = indexBetweenNum(index);
	int max = a.first, n = a.second,tempIndex=index,result=0;
	tempIndex -= 10;
	for (int i = 2; i < n-1; ++i) {
		tempIndex -= i * (9 * pow(10, i - 1));
	}
	int temp = tempIndex;
	int time = 2;
	while (temp > 100) {
		temp /= 10;
		++time;
	}
	result = tempIndex / time + pow(10, time - 1);
	int i = tempIndex % time;
	while (++i<time) {
		result /= 10;
	}
	result = result % 10;
	std::cout << " index: "<<index<<" tempIndex: "<<tempIndex <<" result: "<<result<< std::endl;
	return result;
	
}
void digitalAtIndexTest() {
	int a=digitalAtIndex(19);
	//int a = digitalAtIndex(1001);
	std::cout << a;
}
