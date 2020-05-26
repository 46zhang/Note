
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
�ж������ַ����Ƿ�Ϊ��ת�ʣ�����
a="123456"
b="234561"
����true

a="123456"
b="4561231"
����false
*/
bool isRotaedWord(const string& a,const string &b) {
	int lenA = a.size(), lenB = b.size();
	if (lenA != lenB)
		return false;
	int slow(0), fast(0), p(0);
	if (a == b)
		return true;
	while (p < lenA) {
		while (fast < lenB&&b[fast] != a[p])
			++fast;
		if (fast >= lenB) {
			if (a[p] != b[slow])
				break;
			++slow;
		}
		++p;
	}
	return true;
}
/*
���Ž�
*/
bool isRotation(const string &a, const string& b) {
	if (a.size() != b.size())
		return false;
	string res = b + b;
	
	return res.find(a)!=string::npos;
}
/*int main() {
	string a = "123456";
	string b = "234561";
	cout<<" res: "<<isRotaedWord(a,b)<<endl;
	cout << " res: " << isRotation(a, b) << endl;
	getchar();
	return 0;
}*/