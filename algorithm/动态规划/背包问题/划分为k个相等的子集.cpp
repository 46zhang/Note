#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
/*
给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

示例 1：

输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
输出： True
说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets

*/
using namespace std;
bool dfs(vector<int>& nums, int k, int id, int curLen, int len, vector<bool>& visit);

bool canPartitionKSubsets(vector<int>& nums, int k) {
	if (k <= 0)
		return false;
	vector<bool> visit (nums.size()+1,false);
	
	sort(nums.begin(), nums.end());
	int sum(0);
	for (auto a : nums)
		sum += a;
	if (sum % k > 0)
		return false;
	int len(sum / k);
	cout << "len:" << len <<nums.size()-1<< endl;
	return dfs(nums,k,nums.size()-1,len,len,visit);

}
bool dfs(vector<int>& nums, int k,int id,int curLen,int len, vector<bool>& visit) {
	if (k == 0 || id < 0) {
		if (k == 0)
			return true;
		else
			return false;
	}
		
	bool isOk = false;
	for (int i = id; i >= 0; --i) {
		if (!visit[i] && nums[i] <= curLen) {
			visit[i] = true;
			int a = nums[i];
			//如果相加刚好等于长度的话就继续遍历id的下一个
			//如果相加不为0，则需要判断是否要取该数字，毕竟不是每个相加小于len的长度都要取
			//例如{ 4，5，1，2，6}，k=3 如果4先取了1，那么不会和2匹配了
			std::cout << "k: " << k << "  curLen^nums[i] " << (curLen ^ nums[i]) << " id: " << id << " i: " << i << " nums[i] :" << nums[i] << " curLen - nums[i] " << curLen - nums[i] << endl;

			isOk = curLen^nums[i] ? dfs(nums, k, i - 1, curLen-nums[i], len, visit):
				dfs(nums, k - 1, nums.size() - 1, len, len, visit);
			
			if (isOk || !curLen) return isOk;
			//说明不可取
			visit[i] = false;
			//该nums[i]不可取，则再次遇到该数直接跳过，减枝
			while (i > 0 && nums[i - 1] == nums[i]) --i;
		
		}
	}
	return isOk;
}

class Solution {
public:
	int n, len;
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		n = nums.size();
		vector<bool> vis(n, false);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; i++) len += nums[i];
		if (len%k != 0) return false;
		len = len / k;
		
		return dfs(n - 1, len, n, nums, vis);
	}

	//当前从id位置开始枚举,还有有个sz子集未合法是否能够使所有子集合法
	bool dfs(int id, int cur, int sz, vector<int>& arr, vector<bool>& vis) {
		if (sz == 0) return true; //n个数全部装下
		bool isok = false;
		for (int i = id; i >= 0; i--) {
			if (!vis[i] && cur >= arr[i]) { //当前的数能够装入当前子集中
				vis[i] = true;
				std::cout << "k: " << sz << "  curLen^nums[i] " << (cur ^ arr[i]) << " id: " << id << " i: " << i << " nums[i] :" << arr[i] << " curLen - nums[i] " << cur - arr[i] << endl;

				isok = cur ^ arr[i] ? dfs(i - 1, cur - arr[i], sz - 1, arr, vis) : dfs(n - 1, len, sz - 1, arr, vis);
				if (isok || !cur) return isok;
				vis[i] = false;
				while (i > 0 && arr[i - 1] == arr[i]) i--; //判重剪枝
			}
		}
		return isok;
	}
};


void canPartitionKSubsetsTest() {
	/*[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
	5*/
	/*
	[10,10,10,7,7,7,7,7,7,6,6,6]
	3
	*/
	/*
	[1,1,1,1,1,1,6]
	4
	*/
	/*
	[3522,181,521,515,304,123,2512,312,922,407,146,1932,4037,2646,3871,269]
	5
	*/
	/*
	[1,1,1,1,1,1,1,1,1,1]
	5
	*/
	vector<int>nums = { 3522,181,521,515,304,123,2512,312,922,407,146,1932,4037,2646,3871,269 };
	int k = 5;
	Solution * obj =new Solution();
	//obj->canPartitionKSubsets(nums, k);
	if (canPartitionKSubsets(nums, k))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}