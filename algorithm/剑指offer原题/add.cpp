#include<iostream>
/*

�㷨���ƣ�		���üӼ��˳����ӷ�
�㷨��Դ��		��ָOffer ������65
�㷨˼�룺

�㷨ע�⣺		1.�߽���
				2.�ݹ���ֹ����
�㷨Ч�ʷ���:	�㷨1ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(1)
				�㷨2ʱ�临�Ӷ�O(logn)���ռ临�Ӷ�O(1)
�㷨ʵ��ʱ��:

*/
int add(int p,int q) {
	int sum = 0, carry = 0;
	do {
		sum = p ^ q;
		carry = (p&q) << 1;
		p = sum;
		q = carry;
	} while (q != 0);
	std::cout << "sum: "<<p;
	return p;
}

void addTest() {
	add(3, -5);
}