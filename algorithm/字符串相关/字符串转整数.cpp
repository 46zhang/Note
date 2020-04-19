#include<iostream>
#include<string>
#include<vector>
using namespace std;

int errorNo=0;
const int maxInt = INT_MAX;
const int minInt = INT_MIN;
int strToInt(const string& str) {
	errorNo = 0;
	if (str.size() <= 0)
	{
		errorNo = 1;
		return 0;
	}
	int i = 0,bit=0;
	while (str[i] == ' ')
		++i;
	while (str[i] == '-' || str[i] == '+') {
		if (bit == 1 && str[i] == '-')
		{
			errorNo = 2; return 0;
		}
		if(bit==-1&& str[i]=='+')
		{
			errorNo = 2; return 0;
		}
		bit = str[i] == '-' ? -1 : 1;
		++i;
	}
	int res=0;
	while (i < str.size()) {
		if (str[i] <= '9'&&str[i] >= '0') {
			if (res>= maxInt/10&&(bit<0&&str[i]>='3')||(bit>0&&str[i]>='2')) 
			{
				errorNo = 4;
				return bit > 0?maxInt:minInt;
			}
			else 
				res = res * 10 + str[i] - '0';
		}
		else
		{
			errorNo = 3;
			return 0;
		}
		++i;

	}
	return res;
}
/*int main() {
	cout << (strToInt("-13451351531315")) << endl;
	cout << (strToInt("-1345135153131515313")) << endl;
	cout << (strToInt("-1345135dsfsdf1531315")) << endl;
	cout << (strToInt("sgfsg13451351531315")) << endl;
	cout << (strToInt("-+-+-13451351531315")) << endl;
	cout << (strToInt("------13451351531315")) << endl;
	cout << (strToInt("++++++13451351531315")) << endl;
	cout << (strToInt("-3262262")) << endl;
	cout << (strToInt(to_string(INT_MIN))) << endl;
	cout << (strToInt(to_string(INT_MAX))) << endl;
	getchar();

}*/