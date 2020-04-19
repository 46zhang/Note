#include <iostream>
#include <string>
#include <vector>
using namespace std;
//leecode 344Ã‚
void reverseString(vector<char>& s) {
	int len = s.size();
	if (len <= 1)
		return;
	for (int i = 0, j = len-1; i < j; ++i, --j) {
		int temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

void reverseStringTest() {
	vector<char> s { 'h','e','l','l','o' };
	for (auto a : s)
		std::cout << a<<"  ";
	std::cout << std::endl;
	reverseString(s);
	for (auto a : s)
		std::cout << a << "  ";
	std::cout << std::endl;
}