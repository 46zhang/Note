#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include <string>
using namespace std;
/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
 
bool compare(string s,string word, vector<int>&dp) {
	int isMatch = 0;
	//dp[j]=1说明有一个访问过，不可再重复访问
	//dp[j]>1说明是被之前某一个元素重复访问的，可以被新的元素所访问
	//dp[j]=0说明没被访问过
	for (int i = 0,j=0; i < s.size(); ++i) {
		if (s[i] == word[0] && !dp[i]) {
			for (j = 0; j < word.size() && j+i<=s.size(); ++j)
				if (word[j] != s[j+i]||dp[i+j]==1)
					break;
			//只有当其完全匹配才进行状态改变
			if (j >= word.size()) {
				isMatch += 1;
				//cout << j << endl;
				while (--j >= 0) dp[j+i] = isMatch;
				isMatch +=1;
			}

		}
	}
	return isMatch;
	
}
bool wordBreakII(string s, vector<string>& wordDict) {
	int target = s.size();
	vector<int>dp(target, false);
	for (auto word : wordDict) {
		compare(s, word, dp);
	}
	int result = 1;
	for (auto a : dp) {
		result =result & a ;
		cout << a << "  ";
	}
	cout << endl;
	return result!=0;
}

bool canFind(const string &s,int begin,int end,const string &w) {
	int i;
	for (i=0; i < w.size() && i + begin <= end; ++i)
		if (w[i] != s[i + begin])
			break;
	return i >= w.size();
}

bool wordBreak(string s, vector<string>& wordDict) {
	int target = s.size();
	vector<int>dp(target+1, false);
	unordered_map<string, int> wordMap;
	for (auto w : wordDict)
		wordMap.insert(pair<string,int>(w,1));
	//wordMap.insert((pair<string, int>("", 1)));
	dp[0] = true;
	for (int i = 0; i < target; ++i) {
		for (int j = 1; j <= target-i; ++j) {
			cout<< (s.substr(i, j))<< "  "<<(wordMap.find(s.substr(i, j)) != wordMap.end())<<endl;
			if (dp[i] && wordMap.find(s.substr(i,j))!= wordMap.end()) {
				std::cout << i <<"  "<< "  "<<j << s.substr(i, j) << endl;
				dp[j+i] = true;
				
			}
		}
	}
	for (auto a : dp)
		cout << a<<"  ";
	return dp[target];
}


void wordBreakTest() {
	/*
	"bb"
	["a","b","bbb","bbbb"]
	*/
	/*
	"catsandog"
	["cats","dog","sand","and","cat"]
	*/
	/*
	"cars"
	["car","ca","rs"]
	*/
	/*
	"aaaaaaa"
	["aaaa","aaa"]
	*/
	string s = "aaaaaaa";
	vector<string> wordDict{ "aaaa","aaa" };

	if (wordBreak(s, wordDict))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}