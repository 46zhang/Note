#include<iostream>
#include<vector>
/*
�㷨���ƣ�		�����˻�����
�㷨��Դ��		��ָOffer ������66
�㷨˼�룺		

�㷨ע�⣺		1.�߽���
				2.�ݹ���ֹ����
�㷨Ч�ʷ���:	�㷨1ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(1)
				�㷨2ʱ�临�Ӷ�O(logn)���ռ临�Ӷ�O(1)
�㷨ʵ��ʱ��:	

*/

using namespace std;
void mutilpy(const vector<double> &arrA, vector<double> &arrB) {
	if (arrA.size() <= 0)
		return;
	vector<double > c{ arrA }, d{ arrA };
	c[0] = 1.0;
	d[arrA.size() - 1] = 1.0;
	for (int i = 1; i < arrA.size(); ++i) {
		
			c[i] = c[i - 1] * arrA[i - 1];
			d[arrA.size() - 1 - i] = d[arrA.size() - i] * arrA[arrA.size() - i];
		
	}
	for (int i = 0; i < arrA.size(); ++i) {
		arrB.push_back( c[i] * d[i]);
		std::cout << arrB[i] << std::endl;
	}
	
}

void mutilpyTest() {
	vector<double>a{ 2,2,3,4,5 }, b;
	mutilpy(a,b);
}