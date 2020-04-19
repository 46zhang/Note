#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int>> result;
int len;
bool traceBack(vector<int>& candidates, const int& target, int curSum, int index, vector<int>& temp) {
	cout << index << "  " << curSum << endl;

	if (curSum == target) {
		result.push_back(temp);
		return true;
	}
	else if (curSum > target)
		return false;
	bool flag(true), res(false);
	int num(INT_MAX);
	for (int i = index; i < len; ++i) {

		temp.push_back(candidates[i]);

		flag = traceBack(candidates, target, curSum + candidates[i], i + 1, temp);
		while (i + 1 < len&&candidates[i] == candidates[i + 1])
			++i;
		temp.pop_back();
		if (!flag&&candidates[i]+curSum>target)
			break;
		else
			res = flag;


	}
	return res;
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	if (candidates.size() <= 0)
		return result;
	len = candidates.size();
	vector<int> temp;
	sort(candidates.begin(), candidates.end());
	traceBack(candidates, target, 0, 0, temp);
	return result;
}



/*int main() {
	vector<int> a{ 10,1,2,7,6,5 };
	combinationSum2(a, 8);
	
	getchar();
	return 0;
	
}*/