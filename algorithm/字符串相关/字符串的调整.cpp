#include<iostream>
#include<string>
using namespace std;

/*
把字符串的空格转为%20
*/
string changeString(const string&str) {
	int num(0);
	for (auto c : str)
		if (c == ' ')
			++num;
	num = num * 2 + str.size();
	string res(num, 0);
	int k = num - 1;
	for (int i = str.size() - 1; i >= 0; --i) {
		if (str[i] == ' ') {
			res[k--] = '0';
			res[k--] = '2';
			res[k--] = '%';
		}
		else
			res[k--] = str[i];
	}
	return res;
}
/*
旋转字符串，将ABCDE的前N位移动至后面
输入 ABCDE 3
输出 DEABC
*/
string reverseString(string &a,int index) {
	int i = 0, j = a.size() - 1;
	while (i < j) 
		swap(a[i++], a[j--]);
	i = 0, j = a.size()-index-1 ;
	while (i < j)
		swap(a[i++], a[j--]);
	i = a.size()-index, j = a.size() - 1;
	while(i<j)
		swap(a[i++], a[j--]);
	cout << a << endl;
	return a;
}



/*int main() {
	cout << changeString("a b c   d") << endl;
	cout << changeString("a    ") << endl;
	cout << changeString("    a") << endl;

	string a = "123456";
	reverseString(a,5);
	a = "abcdef";
	reverseString(a, 2);
	getchar();
	return 0;
}*/