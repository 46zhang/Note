#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
算法名称：		翻转字符串
算法来源：		剑指Offer 面试题58
算法思想：		
算法注意：		1.边界检查
				2.递归终止条件
算法效率分析:	算法1时间复杂度O(nlogn)，空间复杂度O(1)
				算法2时间复杂度O(logn)，空间复杂度O(1)
算法实现时间:	花了1个小时20min思考实现算法，前期的构思花了很多时间，所以写代码的时候一遍过，没有bug

*/


bool reverseString(char *pStr,char * pResult) {
	if (pStr == NULL || pResult == NULL)
		return false;
	int len = strlen(pStr), k = 0, lastI = len,i;
	for ( i = len ; i >= 0; --i) {
		if (pStr[i] == ' ') {
			for (int j = i + 1; j < lastI; j++)
				pResult[k++] = pStr[j];
			pResult[k++] = ' ';
			lastI = i;
		}
	}
	for (int j = i + 1; j < lastI; j++)
		pResult[k++] = pStr[j];
	pResult[k++] = '\0';
	std::cout << pStr << std::endl;
	std::cout << pResult << std::endl;
	return true;
}

string reverseString(string str) {
	vector<string> strVec;
	string temp,result;
	for (auto c : str) {
		if (c == ' ') {
			strVec.push_back(temp);
			strVec.push_back(" ");
			temp = "";
		}
		else
			temp += c;
	}
	strVec.push_back(temp);
	for (auto iter = strVec.rbegin(); iter != strVec.rend(); ++iter) {
		result += *iter;
	}
	std::cout << result<<std::endl;
	return result;
}

string LeftRotateString(string str, int n) {
	if (str.size() <= 0 || n <= 0 || n >= str.size())
		return str;
	string result;
	for (int i = n; i < str.size(); ++i) {
		result += str[i];
	}
	for (int i = 0; i < n; ++i)
		result += str[i];
	return result;
}
void reverStringTest() {
	char pStr[100]{ " I am a student. " }, pResult[100];
	string s = " I am a student. ";
	string str = "abcdefg";
	//reverseString(pStr, pResult);
	//reverseString(s);
	std::cout<< LeftRotateString(str, 6);
}