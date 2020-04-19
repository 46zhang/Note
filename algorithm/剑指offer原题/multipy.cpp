#include<iostream>
#include<vector>
/*
算法名称：		构建乘积数组
算法来源：		剑指Offer 面试题66
算法思想：		

算法注意：		1.边界检查
				2.递归终止条件
算法效率分析:	算法1时间复杂度O(nlogn)，空间复杂度O(1)
				算法2时间复杂度O(logn)，空间复杂度O(1)
算法实现时间:	

*/

using namespace std;
void mutilpy(const vector<double> &arrA, vector<double> &arrB) {
	if (arrA.size() <= 0)
		return;
	vector<double > c{ arrA }, d{ arrA };
	c[0] = 1.0;
	d[arrA.size() - 1] = 1.0;
	for (int i = 1; i < arrA.size(); ++i) {
		
			c[i] = c[i - 1] * arrA[i - 1];
			d[arrA.size() - 1 - i] = d[arrA.size() - i] * arrA[arrA.size() - i];
		
	}
	for (int i = 0; i < arrA.size(); ++i) {
		arrB.push_back( c[i] * d[i]);
		std::cout << arrB[i] << std::endl;
	}
	
}

void mutilpyTest() {
	vector<double>a{ 2,2,3,4,5 }, b;
	mutilpy(a,b);
}