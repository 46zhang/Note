#include<iostream>
#include<string>
using namespace std;

/*
���ַ����Ŀո�תΪ%20
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
��ת�ַ�������ABCDE��ǰNλ�ƶ�������
���� ABCDE 3
��� DEABC
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