#include <iostream>
#include <string>
using namespace std;
//反转字符串中的单词 III
string reverseWords(string s) {
	if (s.size()<=0)
		return "";
	auto lastIter = s.begin();
	for (auto iter = s.begin(); iter != s.end(); ++iter) {
		if (*iter == ' ') {
			reverse(lastIter, iter);
			lastIter = iter+1;
		}
	}
	if (lastIter != s.end())
		reverse(lastIter, s.end());
	
	return s;
}
void reverseWordsTest() {
	string a = "Let's take LeetCode contest ab";
	//string a = "";
	string b = reverseWords(a);
	std::cout << b << std::endl;
}