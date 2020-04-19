#include <iostream>
#include <set>
/*
算法名称：		最小的k个数
算法来源：		剑指Offer 面试题40
算法思想：		有2种解法
				1. 借助快排的思想，进行排序，当结束下标为k时，结束分治，前k个就是最小的k个数
					优点：算法速度快，不需要辅助空间，但是需要修改原数组
				2. 借助容器这一辅助空间，每次存k个数，当有新的数字进来时与最大值进行比较，如果小的话进入容器
					利用 红黑树、最大堆，其每次获取最大的数值的时间复杂度为O(1)，但是删除、增加树的节点需要的
					时间复杂度为O(log k),算法实现可以用set,mutilset其都是基于红黑树的
						优点：不修改原来数组，适用于海量数据
算法注意：		1.边界检查
				2.结尾NULL指针的设置
算法效率分析:	算法1 时间复杂度O(n)，空间复杂度O(1)
				算法2 时间复杂度O(nlogk),空间负责度O(n)
算法实现时间:	花了半个小时实现算法1，花了半个小时算法2

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