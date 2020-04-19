#include <iostream>
#include <vector>
/*
算法名称：字符串的排序
算法来源：剑指Offer 面试题37
算法思想：		把字符串分成俩部分，头节点跟子字符串
					1. 先交换每个头节点，例如 a,b,c 就交换成  bac cba
					2. 然后再交换求字符串的全排序有多少种，通过递归交换头节点就可以实现

算法注意：		1.边界检查
				2.递归传递时注意参数的选择，不要重复不要越界
算法效率分析:	O(nlong(n))
算法实现时间:	算法1 花了半个小时实现算法，花了半个小时debug

*/
void printString(char *str) {
	char *p = str;
	while (*p != '\0') {
		std::cout << *p << "  ";
		++p;
	}
	std::cout << std::endl;
}
void permutation(char *allString,int head,int change) {
	while (allString == NULL || head> strlen(allString)||change>strlen(allString))
	{
		std::cout << "over" << std::endl;
		return;
	}
	//std::cout << "NOT NULL";
	int strSize = strlen(allString+head);
	while (change<=strSize) {
	
		//先交换头节点
		char temp = allString[head];
		allString[head] = allString[change];
		allString[change] = temp;
		printString(allString);
		//然后以该头节点为起始，递归交换其下一个位置的头节点
		permutation(allString, head + 1, head + 2);
		//交换回来，再次交换头节点
		temp = allString[head];
		allString[head] = allString[change];
		allString[change] = temp;
		++change;
	}
}
void combination(char *pStr,int m,std::vector<char>&result) {
	if (pStr == NULL||*pStr=='\0'||m<=0)
		return;
	int len = strlen(pStr);
	
	for (int i = 0; i < len; ++i) {
		result.push_back(pStr[i]);
		if (m == result.size()) {
			for (auto iter = result.begin(); iter != result.end(); ++iter)
				std::cout << " " << *iter << " ";
			std::cout << std::endl;
		}
		else
			combination(pStr + i + 1, m, result);
		
		result.pop_back();

	}
	
	
	
}
void stringCombination(char *str) {
	if (str == NULL)
		return;
	std::vector<char> result;
	int i = 0;
	while (++i <= strlen(str)) {
		combination(str, i, result);
	}
}
void permutationTest() {
	char str[10] = "123";
	//permutation(str,0,0);
	stringCombination(str);
}