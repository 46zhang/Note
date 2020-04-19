#include<iostream>
#include<algorithm>

/*

算法名称：		扑克牌中的顺子
算法来源：		剑指Offer 面试题61
算法思想：

算法注意：		1.边界检查
				2.递归终止条件
算法效率分析:
算法实现时间:

*/

bool isContinue(int *pNum,int len) {
	if (pNum == nullptr || len <= 0)
		return false;
	int *begin = pNum,*p=begin, *end = pNum + len, zeroNum = 0, notContinueNum = 0;
	std::sort(begin, end);
	while (*p == 0) {
		++zeroNum;
		++p;
	}
	p = p + 1;
	while (p != end) {
		if (*p == *(p - 1))
			return false;
		notContinueNum += *p - *(p - 1) - 1;
		++p;
	}
	std::cout << notContinueNum << "  " << zeroNum;
	return notContinueNum <= zeroNum;
}

void isContinueTest() {
	int num[10] = { 0,1,3,5}, n = 4;
	if (isContinue(num, n))
		std::cout << "是连续的" << std::endl;
	else
		std::cout << "不是连续的" << std::endl;
}