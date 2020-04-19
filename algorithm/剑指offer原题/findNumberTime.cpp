#include <iostream>
#include <vector>

/*

算法名称：		数组中数字出现的次数
算法来源：		剑指Offer 面试题56
算法思想：

算法注意：		1.边界检查
				2.循环终止条件
算法效率分析:	算法时间复杂度O(n)，空间复杂度O(1)

算法实现时间:	花了50min实现算法1,花了40min实现算法2

*/

using namespace std;
void findTwoNumberAppearOneTime(vector<int> data, int* num1, int *num2) {
	if (data.size() <= 0)
		return ;
	int len = data.size(),xorSum=data[0];
	*num1 = 0, *num2 = 0;
	for (int i = 1; i < len; ++i)
		xorSum = xorSum^data[i];
	std::cout << xorSum << std::endl;
	int n = 0,div=1;
	while ((xorSum & 1) == 0 && n < 8 * sizeof(int)) {
		++n;
		xorSum =xorSum>> 1;
	}
	while (n-- > 0)
		div <<= 1;
	for (int i = 0; i < len; ++i) {
	std:; cout << (data[i] & div) << "  ";
		if ((data[i] & div) == div)
			*num1 ^= data[i];
		else
			*num2 ^= data[i];
	}
	std::cout << xorSum << "  " << div << std::endl;
}

int findOnlyNumber(vector<int> data) {
	if (data.size() <= 0)
		return -1;
	int bitNum[32] = {0}, result = 0;
	for (int i = 0; i < 32; ++i) {
		std::cout << bitNum[i]<<" ";
	}
	for (int i = 0; i < data.size(); ++i)
	{

		int bitMask = 1;
		for (int j = 31; j >= 0; --j)
		{
			if ((bitMask & data[i]) == bitMask) 
				bitNum[j] += 1;
			bitMask <<= 1;
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < 32; ++i) 
		std::cout << bitNum[i]<<" " ;
	for (int i = 0; i < 32; ++i) {
		std::cout << bitNum[i];
		bitNum[i] %= 3;
		result += bitNum[i]<<(31-i);
	}
	return result;
		
}

void findTwoNumberAppearOneTimeTest() {
	vector<int> numVec{ 2,4,3,6,3,2,5,5 };
	//vector<int> num3Vec{ 2,4,3,6,3,2,5,5,5,2,4,4,3 };
	vector<int> num3Vec{ 2,2,2,6,3,3,3 ,5,5,5};
	int num1, num2;
	//findTwoNumberAppearOneTime(numVec, &num1, &num2);
	//std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;
	int a=findOnlyNumber(num3Vec);
	std::cout << "result: " << a<<std::endl;
}