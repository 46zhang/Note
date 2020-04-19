#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
/*
算法名称：		把数组排成最小的数
算法来源：		剑指Offer 面试题45
算法思想：		

算法注意：		1.边界检查
				2.递归终止条件
算法效率分析:	算法1时间复杂度O(nlogn)，空间复杂度O(1)
				算法2时间复杂度O(logn)，空间复杂度O(1)
算法实现时间:	花了30min思考实现算法
*/ 
bool compare(std::string a,std::string b)
{
	return a + b < b + a;
}
void printMinNum(int *num,int len) {
	if (num == NULL || len <= 0)
		return;
	std::vector<std::string> strVector;
	std::string result;
	//数字转字符串
	for (int i = 0; i < len; ++i) 
		strVector.push_back(std::to_string(num[i]));
	std::sort(strVector.begin(), strVector.end(), compare);
	for (auto s : strVector) {
		std::cout << s << "  ";
		result += s;
	}
		
	std::cout << '\n' << "最小的数字是： "<<result<<std::endl;
	
}

void printMinNumberTest() {
	int num[3] = { 3,32,321 },n=3;
	printMinNum(num,n);
}