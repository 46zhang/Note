#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


/*
用哈希表来保存前缀和
*/
int numberOfSubarrays(vector<int>& nums, int k) {
	unordered_map<int, int>mp;
	mp[-1] = -1;
	int cur = 0, sum = 0, count = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] % 2 != 0)
		{
			mp[count] = i;
			//cout<<count<<"  "<<mp[count]<<endl;
			++count;
		}
	}
	mp[count] = nums.size();
	for (int i = count; i >= k; --i) {
		int a = i - k;
		//cout<<i<<"  "<<mp[i]<<" "<<a<<"  "<<mp[a]<<endl;
		sum += (mp[i] - mp[i - 1])*(mp[a] - mp[a - 1]);
	}

	return sum;
}