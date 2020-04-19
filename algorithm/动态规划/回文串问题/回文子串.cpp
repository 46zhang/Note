#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include <string>
using namespace std;
/*

给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

示例 1:

输入: "abc"
输出: 3
解释: 三个回文子串: "a", "b", "c".
示例 2:

输入: "aaa"
输出: 6
说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindromic-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

vector<int> manacher(const string& s) {
	string str(s.size() * 2 + 2, '#');
	for (int i = 0, j = 2; i < s.size(); ++i, j += 2)
		str[j] = s[i];
	str[0] = '$';
	cout << str << endl;
	int right = 0;
	vector<int> len(str.size());
	for (int i = 1, mid = 0; i < str.size(); ++i)
	{
		if (i < right)
			len[i] = min(right - i, len[mid * 2 - i]);
		else
			len[i] = 1;
		while (str[i + len[i]] == str[i - len[i]])
			len[i]++;
		if (i >= right)
		{
			mid = i;
			right = i + len[i];
		}
	}
	return len;
}
int countSubstrings(string s) {
	int sum = 0;
	if (s.size() <= 0)
		return sum;
	vector<int> len(manacher(s));
	for (int i = 1; i < len.size(); ++i)
	{
		//cout << (len[i]) << endl;
		sum += (len[i])/2;
	}
	return sum;
}

void  countSubstringsTest() {
	int a=countSubstrings("aaccc");
	cout << "结果是： " << a << endl;
}