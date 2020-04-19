#include<iostream>
#include<string>
#include<vector>
using namespace std;

string getCountString(const string& str ) {
	string res;
	int num(1),i;
	for (i = 1; i < str.size(); ++i) {
		if (str[i] != str[i - 1]) {
			res.append(1,str[i - 1]);
			res += '_' + to_string(num)+'_';
			num = 1;
		}
		else
			++num;
	}
	res.append(1,str[i - 1]);
	res +='_' + to_string(num);
	return res;
}
char getCharFromCountString(const string& str,int index) {
	int num(0),sum(0);
	char res(0);
	bool state = false;
	for (int i = 0; i < str.size(); ++i) {
		if (i > 0 && str[i] == '_'&&str[i - 1] >= 'a'&&str[i - 1] <= 'z' && !state)
			state = true;
		else if (state&&str[i] == '_') {
			state = false;
			sum += num;
			num = 0;
			if (sum >= index)
				return res;
		}
		else if (str[i] >= 'a'&&str[i] <= 'z')
			res = str[i];
		else if (state) 
			num = num * 10 + str[i] - '0';
	}
	return res;
}

/*int main() {
	string a = "raaaaddddfffffc";
	cout << getCountString(a) << endl;
	a = "adddfgggtt";
	cout << getCountString(a) << endl;

	cout << getCharFromCountString(getCountString(a), 3) << endl;
	
	cout << getCharFromCountString("a_3_b_10_c_24_d_3", 26) << endl;
	cout << getCharFromCountString("a_3_b_105_c_204_d_3", 261) << endl;
	cout << getCharFromCountString("a_3_b_1050_c_204_d_3", 1000) << endl;
	getchar();
	return 0;
}*/