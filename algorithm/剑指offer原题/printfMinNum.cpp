#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
/*
�㷨���ƣ�		�������ų���С����
�㷨��Դ��		��ָOffer ������45
�㷨˼�룺		

�㷨ע�⣺		1.�߽���
				2.�ݹ���ֹ����
�㷨Ч�ʷ���:	�㷨1ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(1)
				�㷨2ʱ�临�Ӷ�O(logn)���ռ临�Ӷ�O(1)
�㷨ʵ��ʱ��:	����30min˼��ʵ���㷨
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
	//����ת�ַ���
	for (int i = 0; i < len; ++i) 
		strVector.push_back(std::to_string(num[i]));
	std::sort(strVector.begin(), strVector.end(), compare);
	for (auto s : strVector) {
		std::cout << s << "  ";
		result += s;
	}
		
	std::cout << '\n' << "��С�������ǣ� "<<result<<std::endl;
	
}

void printMinNumberTest() {
	int num[3] = { 3,32,321 },n=3;
	printMinNum(num,n);
}