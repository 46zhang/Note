#include<iostream>
#include <vector>
#include <map>
using namespace std;
/*

算法名称：		第一个只出现一次的字符
算法来源：		剑指Offer 面试题50
算法思想：		用空间换时间，统计字符串用哈希表来表示出现过的次数

算法注意：		1.边界检查
				2.递归终止条件
算法效率分析:	算法1时间复杂度O(n)
算法实现时间:	花了20min实现算法
				第二个算法是针对字符流的，大概花了20min

*/

char firstNotRepeating(char *pStr) {
	char position[256];
	memset(position, -1, 256);
	for (int i = 0; i < strlen(pStr); ++i) {
		position[pStr[i]]++;
	}
	for (int i = 0; i < strlen(pStr); ++i)
	{
		if (position[pStr[i]] == 0)
			return pStr[i];
	}
}

char firstNotRepeatingCharInCharStream(vector<char> strVector) {
	map<char, int> repeatingNum;
	int i = 0,minIndex=strVector.size();
	char result='\0';
	for (auto iter = strVector.begin(); iter != strVector.end(); ++iter,++i) {
		if (repeatingNum.find(*iter) == repeatingNum.end())
			repeatingNum[*iter] = i;
		else
			repeatingNum[*iter] = -1;
	}
	for (auto iter = repeatingNum.begin(); iter != repeatingNum.end(); ++iter) {
		if (iter->second > 0 && iter->second < minIndex) {
			minIndex = iter->second;
			result = iter->first;
			
		}
			
	}
	return result;

}

void firstNotRepeatingTest() {
	char str[122] = "sfsdf34~!24";
	vector<char> strVec({ 's','f','s','d','f','3','4','~','!','2','4' });
	std::cout<<"结果是: "<<firstNotRepeating(str)<<std::endl;
	std::cout << "结果是: " << firstNotRepeatingCharInCharStream(strVec) << std::endl;
}