#include <iostream>

/*
�㷨���ƣ�		���������е�ĳһλ����
�㷨��Դ��		��ָOffer ������44
�㷨˼�룺		���ҹ��ɣ���

�㷨ע�⣺		1.�߽���
				2.�ݹ���ֹ����

�㷨Ч�ʷ���:	�㷨1ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(1)
				�㷨2ʱ�临�Ӷ�O(logn)���ռ临�Ӷ�O(1)

�㷨ʵ��ʱ��:	����1��Сʱ��Сʱ˼��ʵ���㷨

*/

std::pair<int,int> indexBetweenNum(int index) {
	int time = 1, max = 10;
	while (index > max) {
		max *= 10;
		++time;
	}
	return { max,time };
}
int digitalAtIndex(int index) {
	if (index <= 0)
		return 0;
	else if (index < 10)
		return index;
	std::pair<int,int> a = indexBetweenNum(index);
	int max = a.first, n = a.second,tempIndex=index,result=0;
	tempIndex -= 10;
	for (int i = 2; i < n-1; ++i) {
		tempIndex -= i * (9 * pow(10, i - 1));
	}
	int temp = tempIndex;
	int time = 2;
	while (temp > 100) {
		temp /= 10;
		++time;
	}
	result = tempIndex / time + pow(10, time - 1);
	int i = tempIndex % time;
	while (++i<time) {
		result /= 10;
	}
	result = result % 10;
	std::cout << " index: "<<index<<" tempIndex: "<<tempIndex <<" result: "<<result<< std::endl;
	return result;
	
}
void digitalAtIndexTest() {
	int a=digitalAtIndex(19);
	//int a = digitalAtIndex(1001);
	std::cout << a;
}
