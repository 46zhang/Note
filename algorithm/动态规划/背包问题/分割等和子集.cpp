#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
/*
����һ��ֻ�����������ķǿ����顣�Ƿ���Խ��������ָ�������Ӽ���ʹ�������Ӽ���Ԫ�غ���ȡ�

ע��:

ÿ�������е�Ԫ�ز��ᳬ�� 100
����Ĵ�С���ᳬ�� 200
ʾ�� 1:

����: [1, 5, 11, 5]

���: true

����: ������Էָ�� [1, 5, 5] �� [11].

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/partition-equal-subset-sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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