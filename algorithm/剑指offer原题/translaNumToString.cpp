#include<iostream>
#include <string>
using namespace std;
/*
�㷨���ƣ�		�����ַ�����ַ���
�㷨��Դ��		��ָOffer ������46
�㷨˼�룺		���ö�̬�滮�ķ���

�㷨ע�⣺		1.�߽���
				2.�ݹ���ֹ����
�㷨Ч�ʷ���:	�㷨1ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(1)
				�㷨2ʱ�临�Ӷ�O(logn)���ռ临�Ӷ�O(1)
�㷨ʵ��ʱ��:	����40min

*/
int translaNumToString(char* pStr) {
	if (pStr == NULL || *pStr == '\0')
		return 0;
	int len = strlen(pStr);
	int *pNum = new int[len];
	//memset(pNum, 0, len);
	pNum[0] = 1,pNum[1]=1;
	if (pStr[1] - '0' + 10 * (pStr[0] - '0') < 25) 
		pNum[1] +=1;
	for (int i = 2; i < len; ++i) {
		//pNum[i - 1] = pNum[i - 2];
		int a = pStr[i] - '0' + 10 * (pStr[i - 1] - '0');
		std::cout << a << "  ";
		if (pStr[i] - '0' + 10 * (pStr[i - 1] - '0') <= 25) {
			pNum[i] = pNum[i - 2] + 2;
			
		}
		else {
			pNum[i] = pNum[i - 2] + 1;
		}
		cout << " i: " << i << " Pnum[i]: " << pNum[i] <<"  "<< std::endl ;
			
	}
	len = pNum[len-1];
	delete[] pNum;
	return len;
}
void translaToStringTest() {
	char s[100] = "122518";
	//std::cout << '9' - '0';
	int a = translaNumToString(s);
	std::cout << a << std::endl;
}

