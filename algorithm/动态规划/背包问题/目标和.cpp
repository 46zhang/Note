#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:

输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		/*
		设所有元素和为 M , 正元素和为 P, 负元素和为 N;
		则有： P + N = S; P - N = M; ==> 2P = S + M ==> P = (S+M)/2
		则问题等价为求 nums 中和为 P 的子集数，一共有多少个子集的和为 P
		由此可知 M-S=2N
		*/
		int sum = computeSum(nums);
		if (sum < S) {
			return 0;
		}
		sum = sum + S;
		if (sum % 2 != 0) {
			return 0;
		}
		sum /= 2;

		/* 枚举，对每个 num， 计算 +num, -num 的个数
		return dfs(nums, 0, 0, 0, S);
		*/

		/*
		状态 ： dp[i][j] : 前 i 个数中， 和为 j 的子集个数
		状态转移：
		1. nums[i] 不取： dp[i][j] = dp[i-1][j]
		2. nums[i] 取：   dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]
		*/
		vector<int> dp(sum + 1, 0);
		dp[0] = 1; // 初始状态，容积为0时, 只有一种全部不取的解法；
		for (auto num : nums) {
			for (int j = sum; j >= num; j--) {
				dp[j] = dp[j] + dp[j - num];
			}
		}
		return dp[sum];

	}
	int computeSum(vector<int>& nums) {
		int sum = 0;
		for (auto num : nums) {
			sum += num;
		}
		return sum;
	}
	int dfs(vector<int>& nums, int i, int sum, int count, int target) {
		if (i == nums.size()) {
			if (sum == target) {
				return ++count;
			}
			return count;
		}
		else {
			return dfs(nums, i + 1, sum + nums[i], count, target) + dfs(nums, i + 1, sum - nums[i], count, target);
		}
	}
};

int findTargetSumWaysImproveVersion(vector<int> &nums, int S) {
	int sum = 0;
	for (auto a : nums) 
		sum += a;
	if (sum < S ||(sum-S)%2==1) {
		cout << "over" << endl;
		return 0;
	}
	int target = (sum - S) / 2;
	vector<int>dp(target+1,0);
	dp[0] = 1;
	for (auto a : nums) {
		for (int i = target; i >= a; --i) {
			dp[i] = dp[i] + dp[i - a];
		}
	}
	cout << "\ntarget: " << target <<"  dp[target]: "<< dp[target] << endl;
	return dp[target];
}
//由于题目说的数组的和不过超过1000，所以最小值为 1000-S
//当小于1000-S时，不用再考虑和会等于S了
int findTargetSumWays(vector<int>& nums, int S) {
	int sum(0);
	for (auto a : nums)
		sum += a;
	if (S > sum)
		return 0;
	vector<vector<int>>dp(2, vector<int>(sum * 2 + 2));
	int i, j;
	dp[0][-nums[0] + sum] += 1;
	dp[0][nums[0] + sum] += 1;
	for (i = 1; i < nums.size(); ++i) {
		for (j = 0; j <= sum * 2; ++j) {
			dp[i % 2][j] = 0;
			if (j - nums[i] >= 0)
				dp[i % 2][j] += dp[(i - 1) % 2][j - nums[i]];
			if (j + nums[i] <= sum * 2)
				dp[i % 2][j] += dp[(i - 1) % 2][j + nums[i]];
			//cout << i << "  " << j<<"  "<<" 结果是： "<< dp[i % 2][j]<<std::endl ;
		}
	}
	// cout << sum + S << endl;
	cout << dp[(i - 1) % 2][sum + S];

	return dp[(i - 1) % 2][sum + S];
}

void findTaegetSumWaysTest() {
	vector<int> nums{ 7,9,3,8,0,2,4,8,3,9 };
	int S = 0;
	findTargetSumWays(nums,S);
	findTargetSumWaysImproveVersion(nums, S);
}