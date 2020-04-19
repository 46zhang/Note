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
		//�����������ǰ��ַ������ұ߽�
		//����Ҫ�ж���Գ�λ�õĳ����Ƿ����mx-i���ǵĻ�˵���ᳬ���߽磬�и����Ļ��Ĵ�
		if (i < right)
			palindromeLen[i] = min(right - i, palindromeLen[mid * 2 - i]);
		else
			palindromeLen[i] = 1;
		//����һ�����Բ���
		while (str[i + palindromeLen[i]] == str[i - palindromeLen[i]])
		{
			palindromeLen[i]++;
			
		}
		//˵�����ڵ���ַ����Ѿ����棬��Ҫ���¸����б߽�
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