#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
/*
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-equal-subset-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
void takePack(const vector<int>& nums, int &pack) {
	
}
bool canPartition(vector<int>& nums) {
	long int sum = 0, pack1 = 0, pack2 = 0;
	for (auto a : nums)
		sum += a;
	if (sum % 2 != 0)
		return false;
	sum /= 2;
	/*vector<vector<bool> >dp(nums.size(), vector<bool>(sum + 1));
	for (auto a : dp)
		for (auto b : a)
			b = false;
	int temp = 0;
	//sort(nums.begin(), nums.end(), greater<int>());
	cout << sum;
	for (int i = 0; i <= sum; ++i)
		dp[0][i] = false;
	for (int i = 1; i < nums.size(); ++i) {
		for (int j = 1; j <= sum; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (nums[i] == j)
				dp[i][j] = true;
			if (nums[i] < j) {
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
			}

		}
	}
	
	return dp[nums.size()-1][sum];*/
	int target = sum;
	vector<bool> dp(target + 1, false);
	for (auto a : nums) {
		for (int i = target; i >= a; --i) {
			if (a == i)
				dp[i] = true;
			if (i > a)
				dp[i] = dp[i] || dp[i - a];
		}
	}
	return dp[target];
}
void canPartitionTest() {
	vector<int> nums{ 1,2,3,4,5,6,7 };
	if (true == canPartition(nums))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}