#include<iostream>
#include<algorithm>

/*

�㷨���ƣ�		�˿����е�˳��
�㷨��Դ��		��ָOffer ������61
�㷨˼�룺

�㷨ע�⣺		1.�߽���
				2.�ݹ���ֹ����
�㷨Ч�ʷ���:
�㷨ʵ��ʱ��:

*/

bool isContinue(int *pNum,int len) {
	if (pNum == nullptr || len <= 0)
		return false;
	int *begin = pNum,*p=begin, *end = pNum + len, zeroNum = 0, notContinueNum = 0;
	std::sort(begin, end);
	while (*p == 0) {
		++zeroNum;
		++p;
	}
	p = p + 1;
	while (p != end) {
		if (*p == *(p - 1))
			return false;
		notContinueNum += *p - *(p - 1) - 1;
		++p;
	}
	std::cout << notContinueNum << "  " << zeroNum;
	return notContinueNum <= zeroNum;
}

void isContinueTest() {
	int num[10] = { 0,1,3,5}, n = 4;
	if (isContinue(num, n))
		std::cout << "��������" << std::endl;
	else
		std::cout << "����������" << std::endl;
}