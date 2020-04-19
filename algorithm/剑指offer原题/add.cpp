#include<iostream>
/*

算法名称：		不用加减乘除做加法
算法来源：		剑指Offer 面试题65
算法思想：

算法注意：		1.边界检查
				2.递归终止条件
算法效率分析:	算法1时间复杂度O(nlogn)，空间复杂度O(1)
				算法2时间复杂度O(logn)，空间复杂度O(1)
算法实现时间:

*/
int add(int p,int q) {
	int sum = 0, carry = 0;
	do {
		sum = p ^ q;
		carry = (p&q) << 1;
		p = sum;
		q = carry;
	} while (q != 0);
	std::cout << "sum: "<<p;
	return p;
}

void addTest() {
	add(3, -5);
}