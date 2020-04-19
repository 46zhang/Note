#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*vector<vector<int>> threeSum(vector<int>& nums) {
	int len = nums.size();
	int p(0), q(len - 1);
	vector<vector<int>> res;
	if (len < 3)
		return res;
	sort(nums.begin(), nums.end());
	while (p < q) {
		for (int cur = q - 1; cur > p;) {
			int sum = nums[cur] + nums[q] + nums[p];
			if (sum < 0)
				++p;
			else if (sum == 0)
			{
				//找到一个就退出，因为3数之和，俩个数 p,q确定的，cur是唯一的，所以如果不退出会有重复数组
				res.push_back({ nums[p],nums[cur],nums[q] });
				break;
			}
			else
				--cur;
		}
		--q;
		//已经算过的就不用再进行计算
		while (q > p && nums[q] == nums[q + 1])
			--q;
		//if (nums[q] + nums[q + 1] + nums[p] < 0)
		//	++q, ++p;
		
	}
	return res;
}*/

/*
三数之和
*/
vector<vector<int>> threeSum(vector<int>& nums) {
	int len = nums.size();
	int p(0), q(len - 1);
	vector<vector<int>> res;
	if (len < 3)
		return res;
	sort(nums.begin(), nums.end());
	for (; p < len; ++p) {
		if (nums[p] > 0)
			return res;
		int left = p + 1;
		for (int right = len - 1; right > left;)
		{
			int sum = nums[p] + nums[left] + nums[right];
			if (sum == 0)
			{
				res.push_back({ nums[p],nums[left],nums[right] });
				--right; ++left;
				while (right > left && nums[right] == nums[right + 1])
					--right;
				while (left < right && nums[left] == nums[left - 1])
					++left;
				
			}
			else if (sum < 0)
				++left;
			else
				--right;
		}

		while (p + 1 < len && nums[p + 1] == nums[p])
			++p;

	}

	return res;
}


/*
四数之和
*/
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	int len = nums.size();
	vector<vector<int>> res;
	if (len < 4)
		return res;
	sort(nums.begin(), nums.end());
	for (int a = 0; a < len - 3; ++a) {
		if (nums[a] > target)
			break;
		for (int b = a + 1; b < len; ++b) {
			int c = b + 1;
			int d = len - 1;
			int sum = 0;
			while (c < d) {
				sum = nums[a] + nums[b] + nums[c] + nums[d];
				if (sum == target) {
					res.push_back({ nums[a],nums[b],nums[c],nums[d] });
					c++, --d;
					while (c < d && nums[c] == nums[c - 1])
						++c;
					while (d > c && nums[d] == nums[d + 1])
						--d;
				}
				else if (sum > target)
					--d;
				else
					++c;
			}
			while (b + 1 < len && nums[b] == nums[b + 1])
				++b;
		}
		while (a + 1 < len && nums[a] == nums[a + 1])
			++a;
	}
	return res;
}

/*int main() {
	

	vector<int> nums{ 0,4,-5,2,-2,4,2,-1,4 };
	vector<vector<int>> res= fourSum(nums,12);
	for (auto a : res) {
		for (auto b : a)
			cout << b << "  ";
		cout << endl;
	}
	getchar();
}*/