#include<iostream>

/*

�㷨���ƣ�		Լɪ������
�㷨��Դ ��		��ָOffer ������62
�㷨˼�룺

�㷨ע�⣺		
�㷨Ч�ʷ���:
�㷨ʵ��ʱ��:

*/

int LastRemaining(int n, int m) {
	if (n < 1 || m < 1)
		return -1;
	int last = 0;
	for (int i = 2; i <= n; ++i) {
		last = (last + m) % i;
	}
	return last;
}

void josephuseTest() {
	int n = 5, m = 3,num;
	num = LastRemaining(n, m);
	std::cout << num<<std::endl;
}