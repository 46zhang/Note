#include <iostream>
#include <stack>
bool isPopOrder(const int * pPush, const int * pPop, int length) {
	if (pPush == NULL || pPop == NULL || length <= 0)
		return false;
	int i = 0, j = 0;
	std::stack<int> numStack;
	while (i < length*2) {
		if (numStack.size() != 0 && pPop[j] == numStack.top())
		{
			std::cout << "TOP:" << numStack.top() << std::endl;
			++j;
			numStack.pop();
		}
		else if (pPop[j] == pPush[i])
			++j;
		else if (i < length)
			numStack.push(pPush[i]);
		else
			break;
		++i;
	}
	std::cout << i <<"  "<<j<< std::endl;
	if (numStack.size() != 0 || j < length)
		return false;
	return true;
}

void isPopOrderTest() {
	int p[5] = { 1,2,3,4,5 }, q[5] = { 4,5,3,2,1 }, n = 5;
	if (isPopOrder(p, q, n))
		std::cout << "是弹出序列" << std::endl;
	else
		std::cout << "不不不不是弹出序列" << std::endl;
}