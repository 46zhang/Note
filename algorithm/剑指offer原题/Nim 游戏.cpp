#include <iostream>
#include <string >
using namespace std;

//leecode 292��Ŀ

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
		std::cout << "��Ӯ" << std::endl;
	else
		std::cout << "����Ӯ" << std::endl;
}