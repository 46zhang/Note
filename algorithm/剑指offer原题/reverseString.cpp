#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
�㷨���ƣ�		��ת�ַ���
�㷨��Դ��		��ָOffer ������58
�㷨˼�룺		
�㷨ע�⣺		1.�߽���
				2.�ݹ���ֹ����
�㷨Ч�ʷ���:	�㷨1ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(1)
				�㷨2ʱ�临�Ӷ�O(logn)���ռ临�Ӷ�O(1)
�㷨ʵ��ʱ��:	����1��Сʱ20min˼��ʵ���㷨��ǰ�ڵĹ�˼���˺ܶ�ʱ�䣬����д�����ʱ��һ�����û��bug

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