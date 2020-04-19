#include<iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
//leecode第174周周赛
//力扣第1344题，难度hard
/*
给你一个整数数组 arr 和一个整数 d 。每一步你可以从下标 i 跳到：

i + x ，其中 i + x < arr.length 且 0 < x <= d 。
i - x ，其中 i - x >= 0 且 0 < x <= d 。
除此以外，你从下标 i 跳到下标 j 需要满足：arr[i] > arr[j] 且 arr[i] > arr[k] ，其中下标 k 是所有 i 到 j 之间的数字（更正式的，min(i, j) < k < max(i, j)）。

你可以选择数组的任意下标开始跳跃。请你返回你 最多 可以访问多少个下标。

请注意，任何时刻你都不能跳到数组的外面。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-v

*/

int getRithtJumpsNum(vector<int> &arr,int d,int curIndex) {
	int len = arr.size(),time=0;
	stack<pair<int,int>> index;
	index.push(pair<int,int>(curIndex,1));
	while (index.size() != 0) {
		pair<int, int>last = index.top();
		curIndex=last.first;
		int t = last.second;
		//std::cout << "curIndex: " << curIndex << " t: " << t << std::endl;
		index.pop();
		bool flag = false;
		for (int i = 1; i <= d && curIndex + i < len; ++i) {
			if (arr[curIndex] > arr[curIndex + i])
			{
				flag = true;
				index.push(make_pair(curIndex + i, t + 1));
			}
			else
				break;
		}
		//只有当有数据入栈才需要加1
		if(time<t)
			time=t;
	}
	return time;

}

/*int getRithtJumpsNum(vector<int> &arr, int d, int curIndex) {
	int len = arr.size(), time = 0;
	stack<int> index;
	index.push(curIndex);
	while (index.size() != 0) {
		curIndex = index.top();
		index.pop();
		bool flag = false;
		for (int i = 1; i <= d && curIndex + i < len; ++i) {
			if (arr[curIndex] > arr[curIndex + i])
			{
				flag = true;
				index.push(curIndex + i);
			}
		}
		//只有当有数据入栈才需要加1
		if (flag || curIndex == len - 1)
			++time;
	}
	return time;

}*/


int maxJumps(vector<int>& arr, int d) {
	if (arr.size() <= 0)
		return 0;
	int len = arr.size(),result=0;
	int * indexNum = new int[len];
	memset(indexNum, 0, len);
	for (int i = 0; i < len; ++i) {
		int  right=0,max = 0;
		if (i > 0) {
			int j = 0;
			while (++j <= d && i - j >= 0) {
				if (arr[i] > arr[i - j]) {
					if(indexNum[i - j] > max)
						max = indexNum[i - j];
				}
				else
					break;
			}
		}
		right = getRithtJumpsNum(arr, d, i);
		//std::cout << i << "  " << right << std::endl;
		max += 1;
		if (right > max)
			max = right;
		indexNum[i] = max ;
		if (max  > result)
			result = max;
	}
	for (int i = 0; i < len; ++i)
		std::cout << "  " << indexNum[i];
	return result;
}

int maxJumpsII(vector<int>& arr, int d) {
	int n = arr.size();
	vector<vector<int>> temp;
	vector<int> dp(n, 0);
	int res = 1;
	for (int i = 0; i < arr.size(); i++)
		temp.push_back({ arr[i],i });
	sort(temp.begin(), temp.end());
	
	for (int i = 0; i < n; i++) {
		int index = temp[i][1]; //编号;
		dp[index] = 1;
		//向左找
		for (int j = index - 1; j >= index - d && j >= 0; j--) {
			if (arr[j] >= arr[index]) break;
			if (dp[j] != 0) dp[index] = max(dp[index], dp[j] + 1);
		}
		//向右找
		for (int j = index + 1; j <= index + d && j < n; j++) {
			if (arr[j] >= arr[index]) break;
			if (dp[j] != 0) dp[index] = max(dp[index], dp[j] + 1);
		}
		res = max(dp[index], res);
	}
	for (auto a : dp) {
		std::cout << "  " << a ;
	}
	std::cout << std::endl;
	return res;

}

void maxJumpsTest() {
	//vector<int>arr{ 6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12 };
	//int d = 2, a;
	//vector<int>arr{ 3,2,1 };
	//int d = 1,a;
	//vector<int>arr{ 7,1,7,1,7,1 };
	//int d = 2, a;
	vector<int>arr{ 59,8,74,27,92,36,95,78,73,54,75,37,42,15,59,84,66,25,35,61,97,16,6,52,49,18,22,70,5,59,92,85 };
	
	int d = 20, a, b;
	b = maxJumpsII(arr, d);
	a=maxJumps(arr, d);
	
	std::cout << "\n结果是： " << a <<" 正确结果是： "<<b<< std::endl;
}