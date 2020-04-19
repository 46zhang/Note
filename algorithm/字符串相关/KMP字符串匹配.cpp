#include<iostream>
#include<vector>
#include<string>
using namespace  std;


void kmp(string pat,vector<vector<int>>& dp) {
	int M = pat.length();
	
	// dp[状态][字符] = 下个状态
	// base case
	dp[0][pat[0] ]= 1;
	// 影子状态 X 初始为 0
	int X = 0;
	// 构建状态转移图（稍改的更紧凑了）
	for (int j = 1; j < M; j++) {
		for (int c = 0; c < 256; c++)
			dp[j][c] = dp[X][c];
		dp[j][pat[j]] = j + 1;
		// 更新影子状态
		X = dp[X][pat[j]];
	}
}

void kmpII(const string &pat, vector<vector<int>>& dp) {
	dp[0][pat[0]] = 1;
	int x = 0;
	for (int i = 1; i < pat.size(); ++i) {
		for (int j = 0; j < 256; ++j) {
			dp[i][j] = dp[x][j];
		}
		dp[i][pat[i]] = i + 1;
		x = dp[x][pat[i]];
	}
}
bool search(const string& txt,const string&pat, const vector<vector<int>>&dp) {
	int j = 0;
	int len = pat.size();
	for (int i = 0; i < txt.size(); ++i) {
		j = dp[j][txt[i]];
		if (j == len)
		{
			cout << "  i: " << i << "  ";
			return true;
		}
	}
	return false;
}

/*
洗牌算法
*/
template<typename T>
void Shuffle(vector<T> a) {
	int len = a.size()-1 ;
	for (int i = 0; i < a.size(); ++i) {
		//srand(len);
		int index = rand()%(len+1);
		cout << " index: " << index << " a[index]: " << a[index]<< endl;
		swap(a[index], a[len]);
		--len;
	}
}

/*int main() {
	
	string pat{ "ABABC" };
	string txt1{ "AFDFSDFDABAABABCAC" };
	vector<vector<int>> dp(pat.size(), vector<int>(256));
	kmpII(pat, dp);
	cout<<search(txt1, pat,dp);
	cout << endl;
	string txt2{ "AAAABABC" };
	cout << search(txt2, pat, dp);
	cout << endl;
	string txt3{ "ABABABABABABCABABC" };
	cout << search(txt3, pat, dp);
	cout << endl;
	string txt4{ "ABACBABCABACBCABCCACBCABC" };
	cout << search(txt4, pat, dp);
	cout << endl;
	getchar();
	return 0 ;
}*/