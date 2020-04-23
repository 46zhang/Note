#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


/*
题目：找到一个数组抑或和为0的最多划分，例如{3,2,1,9,0,7,0,2,1,3} 
可以划分为 {3,2,1},{0},{0},{2,1,3},{7},{9}，也就是最多有4个组合抑或和为0
采用前缀和+哈希表的做法
*/
int mostNum(vector<int> num) {
	vector<int> dp(num.size()+1, 0);
	unordered_map<int, int>mp;
	mp[0] = 0;
	int sum=0;
	for (int i = 0; i < num.size(); ++i) {
		sum ^= num[i];
		int k(0);
		if (mp.find(sum) != mp.end())
			k = dp[mp[sum]]+1;
		if (i >= 1)
			dp[i+1] = max(dp[i], k);
		else
			dp[i+1] = k;
		mp[sum] = i+1;
	}
	for (auto d : dp) {
		cout << d << "  ";
	}
	cout << endl;
	return dp[num.size()];
}


/*
划分k个等和子集
*/

bool dfs(vector<int>& nums, int k, int target,int index,vector<bool> visit,int sum) {
	if (k == 0)
		return true;
	else if (index >= nums.size()-1)
		return false;
	bool res = false;
	for (int i = index; i < nums.size(); ++i) {
		if (!visit[i] && nums[i] <= target) {
			visit[i] = true;
			res = target ^ nums[i] ? dfs(nums, k, target-nums[i], i + 1, visit,sum) :
				dfs(nums, k-1, sum, index + 1, visit, sum);
			if (!res)
			{
				visit[i] = false;
				while (i + 1 < nums.size() && nums[i + 1] == nums[i])
					++i;//减枝头
			}
			else
				return res;

		}
	}
	return res;

}
static bool canPartitionKSubsets(vector<int>& nums, int k) {
	int sum = 0,target;
	for (auto a : nums)
		sum += a;
	if (sum%k != 0)
		return false;
	target = sum / k;
	vector<bool> visit(nums.size(), false);
	return dfs(nums, k, target,0,visit,target);
}

/*int main() {
	vector<int> num{ 3522,181,521,515,304,123,2512,312,922,407,146,1932,4037,2646,3871,269 };
	//mostNum(num);
	cout<<canPartitionKSubsets(num,5);
	getchar();
}*/