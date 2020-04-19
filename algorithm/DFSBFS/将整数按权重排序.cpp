/*
我们将整数 x 的 权重 定义为按照下述规则将 x 变成 1 所需要的步数：

如果 x 是偶数，那么 x = x / 2
如果 x 是奇数，那么 x = 3 * x + 1
比方说，x=3 的权重为 7 。因为 3 需要 7 步变成 1 （3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1）。

给你三个整数 lo， hi 和 k 。你的任务是将区间 [lo, hi] 之间的整数按照它们的权重 升序排序 ，如果大于等于 2 个整数有 相同 的权重，那么按照数字自身的数值 升序排序 。

请你返回区间 [lo, hi] 之间的整数按权重排序后的第 k 个数。

注意，题目保证对于任意整数 x （lo <= x <= hi） ，它变成 1 所需要的步数是一个 32 位有符号整数。

示例 1：

输入：lo = 12, hi = 15, k = 2
输出：13
解释：12 的权重为 9（12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1）
13 的权重为 9
14 的权重为 17
15 的权重为 17
区间内的数按权重排序以后的结果为 [12,13,14,15] 。对于 k = 2 ，答案是第二个整数也就是 13 。
注意，12 和 13 有相同的权重，所以我们按照它们本身升序排序。14 和 15 同理。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-integers-by-the-power-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
unordered_map<int, int> mp;
/*
采用递归来求得每个数字的权重
借助哈希表实现记忆搜索提高求权重的性能
*/
int getWeight(int n) {
	if (n == 1)
		return 0;
	if (mp.find(n) != mp.end()) return mp[n];
	if (n % 2 == 1)
		mp[n] = 1 + getWeight(n * 3 + 1);
	else
		mp[n] = 1 + getWeight(n / 2);
	return mp[n];
}
int getKth(int lo, int hi, int k) {
	vector<int>num(hi - lo + 1);

	for (int i = 0; i < hi - lo + 1; ++i)
		num[i] = lo + i;
	// cout<<i<<" "<<num[i]<<" "<<lo+i<<endl;

	//借助lambda表达式来实现递增排序
	sort(num.begin(), num.end(), [](int& a, int& b) {
		int aw = getWeight(a);
		int bw = getWeight(b);
		if (aw != bw)
			return aw < bw;
		else
			return a < b;
	});
	//for(auto a:num)
   //     cout<<a<<" ";
   // cout<<endl;

	return num[k - 1];
}

