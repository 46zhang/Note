#include <iostream>
#include <vector>

/*

�㷨���ƣ�		���������ֳ��ֵĴ���
�㷨��Դ��		��ָOffer ������56
�㷨˼�룺

�㷨ע�⣺		1.�߽���
				2.ѭ����ֹ����
�㷨Ч�ʷ���:	�㷨ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)

�㷨ʵ��ʱ��:	����50minʵ���㷨1,����40minʵ���㷨2

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