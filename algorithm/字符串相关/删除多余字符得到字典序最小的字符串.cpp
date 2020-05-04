#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;

string deleteCharAndGetString(string s) {
	unordered_map<char, int> mp;
	string res;
	int len = s.size();
	for (auto c : s)
		++mp[c];
	int left = 0, right = 0;
	while (right < len) {
		if (mp[s[right]] == -1 || --mp[s[right]] > 0)
			right++;
		else {
			int pick = right;
			for (int i = left; i <= right; ++i) {
				if (mp[s[i]] != '-1'&&s[i] < s[pick])
					pick = i;
			}
			left = pick + 1;
			res += s[pick];
			mp[s[pick]] = -1;
			for (int i = pick + 1; i <= right; ++i) {
				if(mp[s[i]]!='-1')
					++mp[s[i]];
			}
			right = left;
		}
	}
	cout << res << endl;
	return res;
}

/*int main() {
	string a = "dbcacbcaaa";
	deleteCharAndGetString(a);
	string b = "dbacbcbcdgabc";
	//deleteCharAndGetString(b);
	getchar();
	return 0;
}*/