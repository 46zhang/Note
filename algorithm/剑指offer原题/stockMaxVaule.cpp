#include<iostream>

/*

�㷨���ƣ�		��Ʊ���������
�㷨��Դ ��		��ָOffer ������63
�㷨˼�룺

�㷨ע�⣺
�㷨Ч�ʷ���:
�㷨ʵ��ʱ��:

*/

int stockMaxValue(int *pNum,int len) {
	int value =0,max=0,minStock=pNum[0];

	for (int i = 1; i < len; ++i) {
		if (pNum[i] > minStock)
			value =  pNum[i] - minStock;
		else {
			minStock = pNum[i];
			value = 0;
		}
		if (max < value)
			max = value;
		std::cout << value<<"  ";
	}
	return max;
}

void stockMaxVauleTest() {
	//int num[10] = { 9,111,8,5,7,12,16,14,20 }, n = 9;
	//int num[10] = { 1,2,3,4,5,12,16,2,220 }, n = 9;
	int num[10] = { 111,22,17,16,15,12,11,5,2 }, n = 9;
	int max = stockMaxValue(num, n);
	std::cout << "��Ʊ������ֵΪ�� " << max<<std::endl;
}