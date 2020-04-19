#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


string longestPalindrome(string s) {
	string str(s.size() * 2 + 2,'#');
	for (int i = 0, j = 2; i < s.size(); ++i, j += 2)
		str[j] = s[i];
	str[0] = '$';
	cout << str<<endl;
	int strLen = str.size(), right = 0, maxIndex = 0;
	vector<int> palindromeLen(strLen, 0);
	for (int i = 1, mid = 0; i < strLen; ++i) {
		//如果不超过当前最长字符串的右边界
		//则需要判断其对称位置的长度是否大于mx-i，是的话说明会超过边界，有更长的回文串
		if (i < right)
			palindromeLen[i] = min(right - i, palindromeLen[mid * 2 - i]);
		else
			palindromeLen[i] = 1;
		//再做一次线性查找
		while (str[i + palindromeLen[i]] == str[i - palindromeLen[i]])
		{
			palindromeLen[i]++;
			
		}
		//说明现在的最长字符串已经更替，需要重新更新有边界
		if (i + palindromeLen[i] > right) {
			mid = i;
			right = i + palindromeLen[i];
		}
		
		if(palindromeLen[i] > palindromeLen[maxIndex])
			maxIndex =  i;
		//cout << " i: " << i << " palindromeLen[i]: " << palindromeLen[i] <<" mid: "<<mid<< " right: " << right<<endl;
	}
	return s.substr((maxIndex- palindromeLen[maxIndex]) /2, palindromeLen[maxIndex] - 1);
}

void longestPalindromeTest() {
	string s = "adsgsdg";
	string r = "";
	r=longestPalindrome(s);
	cout << r << endl;
}