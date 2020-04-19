#include<iostream>
#include<deque>
#include<vector>
using namespace std;

/*
算法名称：		队列的最大值
算法来源：		剑指Offer 面试题59
算法思想：		

算法注意：		1.边界检查
				2.递归终止条件
算法效率分析:	算法1时间复杂度O(nlogn)，空间复杂度O(1)
				算法2时间复杂度O(logn)，空间复杂度O(1)
算法实现时间:	

*/

vector<int> maxVauleInQqueue(vector<int> data,int k) {
	if (data.size() <= 0||k<=0)
		return data;
	deque<int> index{0};
	vector<int> maxValue;
	for (int i = 1; i < data.size(); ++i) {
		//队列不为空且当且数据大于队头，清空之前的队列
		if (!index.empty() &&data[i] > data[index.front()]) {
			while (!index.empty())
 			index.push_front(i);
		}
		else {
			while (!index.empty()&&data[i] > data[index.back()]) {
				index.pop_back();
			}
			//如果小于队列，加入到队尾
			index.push_back(i);
		}
		//加入最大值
		if (i >= k - 1)
			maxValue.push_back(data[index.front()]);
		//如果与队头相差为k-1说明是一个滑动窗口的了
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