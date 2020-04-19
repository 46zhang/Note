#include <iostream>
#include <set>
/*
�㷨���ƣ�		��С��k����
�㷨��Դ��		��ָOffer ������40
�㷨˼�룺		��2�ֽⷨ
				1. �������ŵ�˼�룬�������򣬵������±�Ϊkʱ���������Σ�ǰk��������С��k����
					�ŵ㣺�㷨�ٶȿ죬����Ҫ�����ռ䣬������Ҫ�޸�ԭ����
				2. ����������һ�����ռ䣬ÿ�δ�k�����������µ����ֽ���ʱ�����ֵ���бȽϣ����С�Ļ���������
					���� ����������ѣ���ÿ�λ�ȡ������ֵ��ʱ�临�Ӷ�ΪO(1)������ɾ�����������Ľڵ���Ҫ��
					ʱ�临�Ӷ�ΪO(log k),�㷨ʵ�ֿ�����set,mutilset�䶼�ǻ��ں������
						�ŵ㣺���޸�ԭ�����飬�����ں�������
�㷨ע�⣺		1.�߽���
				2.��βNULLָ�������
�㷨Ч�ʷ���:	�㷨1 ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
				�㷨2 ʱ�临�Ӷ�O(nlogk),�ռ为���O(n)
�㷨ʵ��ʱ��:	���˰��Сʱʵ���㷨1�����˰��Сʱ�㷨2

*/
void partition(int *pNum,int begin,int end,int k) {
	if (pNum == nullptr || begin>=end || k <= 0)
		return;
	int temp, i = end, j = begin,time=0;
	while (j < i) {
		while (j < end && pNum[++j]<pNum[begin]);
		while (i > begin &&  pNum[--i]>pNum[begin]);
		if (j >= i)
			break;
		temp = pNum[j];
		pNum[j] = pNum[i];
		pNum[i] = temp;
		time++;
	}
	temp = pNum[begin];
	pNum[begin] = pNum[i];
	pNum[i] = temp;
	
	if (j == k)
		return;
	else if(j<k)
		partition(pNum, i + 1, end, k);
	else
		partition(pNum, begin, i, k);

		
}
void getLeastNumbers(int *pNum,int n,int k) {
	if(pNum==nullptr||n<=0||k<=0)
		return ;
	partition(pNum, 0, n, k);
	for (int i = 0; i < k; ++i)
		std::cout << "  " << pNum[i];
}
typedef std::multiset<int,std::greater<int>> intSet;
typedef std::multiset<int, std::greater<int>>::iterator setIterator;

void getLeastNumbersBySet(int *pNum, int n, int k) {
	intSet leastKSet;
	if (pNum == nullptr || n <= 0 || k <= 0)
		return;
	for (int i = 0; i < n; ++i) {
		if (leastKSet.size() < k) {
			leastKSet.insert(pNum[i]);
		}
		else {
			setIterator iter = leastKSet.begin();
			if (pNum[i] < *iter) {
				leastKSet.erase(iter);
				leastKSet.insert(pNum[i]);
			}
		}
	}
	for (auto iter = leastKSet.begin(); iter != leastKSet.end(); ++iter)
		std::cout << "  " << *iter;
}
void getLeastNumbersTest() {
	//[0, 0, 1, 2, 4, 2, 2, 3, 1, 4]
	//8
	int num[10] = { 0, 0, 1, 2, 4, 2, 2, 3, 1, 4 }, n = 10,k=8;
	getLeastNumbers(num, n,k);
	//getLeastNumbersBySet(num, n, k);
}
/*int main() {
	getLeastNumbersTest();
	getchar();
}*/