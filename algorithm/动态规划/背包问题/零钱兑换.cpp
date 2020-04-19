#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int coinChange(vector<int>& coins, int amount) {
	if (amount == 0)
		return 0;
	vector<int> dp(amount + 1, amount+1);
	dp[0] = 0;
	for (auto c : coins) {
		for (int j = c; j <=amount ; ++j) {
			dp[j] = min(dp[j], dp[j - c] + 1);
		}
	}
	int i = 0;
	for (auto a : dp) {
		cout <<" i: "<<i++<<" ½á¹û: "<< a << "  " << endl;
	}
	cout << dp[amount] << endl;
	return (dp[amount]==0)?-1:dp[amount];
}

void coinChangeTest() {
	vector<int> coins{ 1,2 ,5};
	int amount = 201;
	cout<<coinChange(coins,amount);
}