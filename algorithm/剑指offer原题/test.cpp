#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*int main() {
	int n;
	cin >> n;
	if (n <= 0)
		cout << 0;
	vector<int> num(n);
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	vector<vector<int>> dp(n, vector<int>(2,1));
	//dp[0] = 1;
	int maxLen(1);
	int flag=0;
	cout << "  ";
	for (int i = 1; i < n; ++i) {
		flag = 0;
		for (int j = i - 1; j >= 0; --j) {
			if (num[j] < num[i] && flag < 2) {
				if (flag == 0 && num[j + 1] > num[j])
					dp[i][0] = max(dp[i][0], dp[j][0] + 1);
				else {
					dp[i][1] = max(dp[i][1], dp[j][0] + 1);
					flag += 1;
				}
			}
			else if (flag >= 2)
			{
				break;
				//cout << " i: " << i << " j: " << j << endl;
			}
			else
				++flag;
		}

		cout <<"i: "<<i<<"  "<< dp[i][0] << " "<<dp[i][1]<<" "<<endl;
		maxLen = max(maxLen,max(dp[i][0], dp[i][1]));
	}
	cout << maxLen;
	getchar();
	getchar();
	getchar();
	return 0;
}*/
/*int main() {
	int n;
	cin >> n;
	if (n < 3)
		return 0;
	vector<vector<int>> num(2, vector<int>(n));
	long int a(0), b(0);
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j)
		{
			cin >> num[i][j];
			if (i == 0)
				a += num[i][j];
			else
				b += num[i][j];
		}
	}
	cout<<"a: "<<a<<" b: "<<b<<endl;
	if (n <= 3)
		return a > b ? a : b;
	sort(num[0].begin(), num[0].end(), greater<int>());
	sort(num[1].begin(), num[1].end(), greater<int>());
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j)
			cout << num[i][j] << "  ";
		cout << endl;
	}
	int maxValue = max(num[0][0] + num[0][1] + num[0][2], num[1][0] + num[1][1] + num[1][2]);
	cout << maxValue;
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	return 0;
}*/