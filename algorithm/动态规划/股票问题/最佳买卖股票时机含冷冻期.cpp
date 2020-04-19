#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include <string>
using namespace std;



int maxProfit(vector<int>& prices) {
	int len = prices.size();
	vector<int> dp(len, 0);
	int max = 0;
	for (int j = 1; j < len; ++j) {
		int temp = 0;
		for (int i = j - 1; i >= 0; --i) {
			temp = prices[j] - prices[i];
			//如果i大于1说明可以加上冷冻期前的
			if (i >= 2)
				temp += dp[i - 2];
			//cout << " j: "<<j<<" i: "<<i <<" temp "<< temp << "  " << dp[j - 1] << endl;
			if (temp > dp[j])
				dp[j] = temp;
		}
		if (dp[j] < dp[j-1])
			dp[j]=dp[j-1];
	}
	//for (auto a : dp)
		//cout << a<<"  ";
	cout << endl << dp[len - 1] << endl;
	return dp[len-1];
}

int maxProfitImprove(vector<int>& prices) {
	int len = prices.size();
	if (len <= 1)
		return 0;
	vector<vector<int>> dp(len+1, vector<int>(2));
	dp[0][0] = 0;
	dp[0][1] = -10000000;
	dp[1][1] = -prices[0];
	for (int i = 1; i <= len; ++i) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i-1]);
		if (i >= 2)
			dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i-1]);
		cout << i << "   " << dp[i][0] << "  " << dp[i][1] << endl;;
	}
	return dp[len][0];
}

void maxProfitTest() {
	/*
	[6,1,6,4,3,0,2]
	*/
	/*
	[2,1,4]
	*/
	/*
	[1,2,3,0,2]
	*/
	vector<int>num{ 1,2,3,0,2 };
	maxProfitImprove(num);
}