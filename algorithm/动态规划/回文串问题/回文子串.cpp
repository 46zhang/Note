#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include <string>
using namespace std;
/*

����һ���ַ�������������Ǽ�������ַ������ж��ٸ������Ӵ���

���в�ͬ��ʼλ�û����λ�õ��Ӵ�����ʹ������ͬ���ַ���ɣ�Ҳ�ᱻ��Ϊ�ǲ�ͬ���Ӵ���

ʾ�� 1:

����: "abc"
���: 3
����: ���������Ӵ�: "a", "b", "c".
ʾ�� 2:

����: "aaa"
���: 6
˵��: 6�������Ӵ�: "a", "a", "a", "aa", "aa", "aaa".

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/palindromic-substrings
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
	cout << "����ǣ� " << a << endl;
}