#include<iostream>
#include<deque>
#include<vector>
using namespace std;

/*
�㷨���ƣ�		���е����ֵ
�㷨��Դ��		��ָOffer ������59
�㷨˼�룺		

�㷨ע�⣺		1.�߽���
				2.�ݹ���ֹ����
�㷨Ч�ʷ���:	�㷨1ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(1)
				�㷨2ʱ�临�Ӷ�O(logn)���ռ临�Ӷ�O(1)
�㷨ʵ��ʱ��:	

*/

vector<int> maxVauleInQqueue(vector<int> data,int k) {
	if (data.size() <= 0||k<=0)
		return data;
	deque<int> index{0};
	vector<int> maxValue;
	for (int i = 1; i < data.size(); ++i) {
		//���в�Ϊ���ҵ������ݴ��ڶ�ͷ�����֮ǰ�Ķ���
		if (!index.empty() &&data[i] > data[index.front()]) {
			while (!index.empty())
 			index.push_front(i);
		}
		else {
			while (!index.empty()&&data[i] > data[index.back()]) {
				index.pop_back();
			}
			//���С�ڶ��У����뵽��β
			index.push_back(i);
		}
		//�������ֵ
		if (i >= k - 1)
			maxValue.push_back(data[index.front()]);
		//������ͷ���Ϊk-1˵����һ���������ڵ���
		if (i-index.front() >= k - 1) 
			index.pop_front();
		
	}
	for (auto i : maxValue)
		std::cout << i << " ";
	return maxValue;
} 

void maxValueInQueueTest() {
	vector<int> data{ 2,3,4,2,6,2,5,1 };
	int k = 3;
	maxVauleInQqueue(data, k);
}