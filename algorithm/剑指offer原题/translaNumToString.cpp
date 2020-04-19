#include<iostream>
#include <string>
using namespace std;
/*
算法名称：		把数字翻译成字符串
算法来源：		剑指Offer 面试题46
算法思想：		采用动态规划的方法

算法注意：		1.边界检查
				2.递归终止条件
算法效率分析:	算法1时间复杂度O(nlogn)，空间复杂度O(1)
				算法2时间复杂度O(logn)，空间复杂度O(1)
算法实现时间:	花了40min

*/
int translaNumToString(char* pStr) {
	if (pStr == NULL || *pStr == '\0')
		return 0;
	int len = strlen(pStr);
	int *pNum = new int[len];
	//memset(pNum, 0, len);
	pNum[0] = 1,pNum[1]=1;
	if (pStr[1] - '0' + 10 * (pStr[0] - '0') < 25) 
		pNum[1] +=1;
	for (int i = 2; i < len; ++i) {
		//pNum[i - 1] = pNum[i - 2];
		int a = pStr[i] - '0' + 10 * (pStr[i - 1] - '0');
		std::cout << a << "  ";
		if (pStr[i] - '0' + 10 * (pStr[i - 1] - '0') <= 25) {
			pNum[i] = pNum[i - 2] + 2;
			
		}
		else {
			pNum[i] = pNum[i - 2] + 1;
		}
		cout << " i: " << i << " Pnum[i]: " << pNum[i] <<"  "<< std::endl ;
			
	}
	len = pNum[len-1];
	delete[] pNum;
	return len;
}
void translaToStringTest() {
	char s[100] = "122518";
	//std::cout << '9' - '0';
	int a = translaNumToString(s);
	std::cout << a << std::endl;
}

