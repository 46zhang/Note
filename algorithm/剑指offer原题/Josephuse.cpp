#include<iostream>

/*

算法名称：		约瑟夫环问题
算法来源 ：		剑指Offer 面试题62
算法思想：

算法注意：		
算法效率分析:
算法实现时间:

*/

int LastRemaining(int n, int m) {
	if (n < 1 || m < 1)
		return -1;
	int last = 0;
	for (int i = 2; i <= n; ++i) {
		last = (last + m) % i;
	}
	return last;
}

void josephuseTest() {
	int n = 5, m = 3,num;
	num = LastRemaining(n, m);
	std::cout << num<<std::endl;
}