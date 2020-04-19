#include <iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> result;

void dfs(string s, int left, int n) {
	if (n <= 0) {
		for (int i = 0; i < left; ++i)
			s += ")";
		result.push_back(s);
		return;
	}
	dfs(s + "(", left + 1, n - 1);
	for (int i = 1; i <= left; ++i) {
		s += ')';
		dfs(s + "(", left - i + 1, n - 1);
	}

}
vector<string> generateParenthesis(int n) {
	dfs("", 0, n);
	return result;
}
/*int main() {
	int n=3;
	generateParenthesis(n);
	return 0;
}*/