#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> res;
void dfs(vector<int>&nums,int index,int n,vector<int>& temp ) {
	/*if (n == temp.size()) {
		res.push_back(temp);
		return;
	}*/
	if (index >= nums.size()||n>=nums.size())
		return;
	for (int i = index; i < nums.size(); ++i) {
		temp.push_back(nums[i]);
		res.push_back(temp);
		while (i + 1 < nums.size() && nums[i + 1] == nums[i])
			++i;
		dfs(nums, i + 1, n + 1, temp);
		temp.pop_back();
	}
}
void quickSort(vector<int>& nums,int begin,int end) {
	if (begin >= end)
		return;
	int i = begin, j = end,target=nums[i];
	while (i < j) {
		while (i < end && nums[++i] < target);
		while (j > begin && nums[--j] > target);
		if (i < j)
			swap(nums[i], nums[j]);
	}
	nums[begin] = nums[j];
	nums[j] = target;
	quickSort(nums, begin, j);
	quickSort(nums,j+1,end);
}
/*int main() {
	vector<int> nums{ 1,2,3 ,4,3};
	sort(nums.begin(), nums.end());
	vector<int> temp;
	dfs(nums, 0, 0, temp);
	for (auto v : res) {
		for (auto n : v) {
			cout << n << "  ";
		}
		cout << endl;
	}
	getchar();
	return 0;
}*/