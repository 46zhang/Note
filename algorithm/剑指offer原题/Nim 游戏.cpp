#include <iostream>
#include <string >
using namespace std;

//leecode 292题目

bool canWinNim(int n) {
	int time = 0;
	while (n > 3) {
		n = n - 3;
		++time;
	}
	return time % 2 == 0;
}

void cnaWimNimTest() {
	int n = 4;

	if (canWinNim(n))
		std::cout << "能赢" << std::endl;
	else
		std::cout << "不能赢" << std::endl;
}