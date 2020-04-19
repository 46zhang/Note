#include<iostream>
#include<string>
using namespace std;
/*
给你一个回文字符串 palindrome ，请你将其中 一个 字符用任意小写英文字母替换，使得结果字符串的字典序最小，且 不是 回文串。

请你返回结果字符串。如果无法做到，则返回一个空串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/break-a-palindrome

*/
string breakPalindrome(string palindrome) {
	if (palindrome.size() <= 1)
		return "";
	for (int i = 0, j = palindrome.size() - 1; i <= j; ++i, --j) {
		if (palindrome[i] != 'a') {
			if (i < j) {
				palindrome[i] = 'a';
				return palindrome;
			}
			else if (j == i && i > 0) {
				break;
			}
			else
				return "";
		}
	}
	palindrome[palindrome.size() - 1] = 'b';
	return palindrome;

}

void breakPalindromeTest() {
	string a=breakPalindrome("aaabaaa");
	std::cout << a;
}