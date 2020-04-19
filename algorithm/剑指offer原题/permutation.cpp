#include <iostream>
#include <vector>
/*
�㷨���ƣ��ַ���������
�㷨��Դ����ָOffer ������37
�㷨˼�룺		���ַ����ֳ������֣�ͷ�ڵ�����ַ���
					1. �Ƚ���ÿ��ͷ�ڵ㣬���� a,b,c �ͽ�����  bac cba
					2. Ȼ���ٽ������ַ�����ȫ�����ж����֣�ͨ���ݹ齻��ͷ�ڵ�Ϳ���ʵ��

�㷨ע�⣺		1.�߽���
				2.�ݹ鴫��ʱע�������ѡ�񣬲�Ҫ�ظ���ҪԽ��
�㷨Ч�ʷ���:	O(nlong(n))
�㷨ʵ��ʱ��:	�㷨1 ���˰��Сʱʵ���㷨�����˰��Сʱdebug

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
	
		//�Ƚ���ͷ�ڵ�
		char temp = allString[head];
		allString[head] = allString[change];
		allString[change] = temp;
		printString(allString);
		//Ȼ���Ը�ͷ�ڵ�Ϊ��ʼ���ݹ齻������һ��λ�õ�ͷ�ڵ�
		permutation(allString, head + 1, head + 2);
		//�����������ٴν���ͷ�ڵ�
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