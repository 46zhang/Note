#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool compare(vector<int> a, vector<int>b) {
	if (a[0] == b[0])
		return a[1] < b[1];
	return a[0] < b[0];
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
	if (envelopes.size() <= 0)
		return 0;
	//nlogn
	sort(envelopes.begin(), envelopes.end(), compare);
	/*for(auto e:envelopes){
		for(auto a:e){
			cout<<a<<"  ";
		}
		cout<<endl;
	}*/
	int len = envelopes.size();
	int w(0), h(0);
	int res(1);
	vector<int> height;
	//n
	for (int i = 0; i < len; ++i) {
		if (w < envelopes[i][0])
		{
			height.push_back(envelopes[i][1]);
			w = envelopes[i][0];
			//h=envelopes[i][1];
		}
		else if (w == envelopes[i][0]) {
			height[height.size() - 1] = envelopes[i][1];
			w = envelopes[i][0];
		}
	}
	/*for(auto a:height)
		cout<<a<<"  ";
	cout<<endl;*/
	vector<int> end(height.size(), 0);
	end[0] = height[0];

	int rightEnd(0);
	for (int i = 1; i < len; ++i) {
		int left = 0, right = rightEnd;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (end[mid] < height[i])
				left = mid + 1;
			else
				right = mid - 1;
			//cout<<left<<"  "<<"  "<<right<<endl;
		}
		
		res = max(left + 1, res);
		end[left] = height[i];
		rightEnd = max(rightEnd, left);
		for (int i = 0; i <= rightEnd; ++i)
			cout << height[i] << "  ";
		cout << endl;
	}
	return res;
}
void qsort(vector<int>& num,int begin,int end) {
	if (begin >= end)
		return;
	int i = begin, j = end;
	int target = num[begin];
	while (i < j) {
		while (j > 0 && num[--j] > target);
		while (i < end-1 && num[++i] < target);
		if (i < j)
			swap(num[i], num[j]);
	}
	num[begin] = num[j];
	num[j] = target;
	qsort(num, begin, j);
	qsort(num, j + 1, end);
}
/*int main() {
	vector<vector<int>> num{ {4,5},{4,6},{6,7},{2,3},{1,1} };
	//maxEnvelopes(num);
	vector<int> n{ 1,4,1,2,5,6 };
	qsort(n, 0, n.size());
	for (auto a : n)
		cout << a << "  ";
	cout << endl;
	getchar();
	return 0;
}*/