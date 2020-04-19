#include <iostream>

/*
算法名称：打印从1到n位最大数字
算法来源：剑指Offer 面试题17
算法思想：		有多种解法
				

算法注意：		
算法效率分析:	
算法实现时间:	算法1 20min
				算法2 花了40Min
*/

//这种做法存在问题，当n的位数超过INT最大长度时存在问题
void printOneToMaxOfDigital(int n) {
	int num = 10;
	if (n <= 0)
		return;
	while (--n) {
		num *= 10;
		if (num > INT_MAX / 10&&n)
			break;
	}
	for (int i = 1; i < num; ++i)
		std::cout << i <<"  ";
}

void increaseStr(char *str,int n) {
	
	while (n--) {
		
		if (str[n] == '\0')
		{
			str[n] = '1';
			break;
		}
		else if (str[n] - '0' == 9)
			str[n] = '0';
		else {
			str[n] += 1;
			break;
		}
			
	}
}

void printOneToMaxOfDigitalByString(int n) {
	char * str = new char[n + 1],*aim=new char[n+1];
	memset(str, 0, n + 1);
	memset(aim, '9', n);
	aim[n] = '\0';
	std::cout << aim << std::endl;
	if (n <= 0)
		return;
	
	while (strcmp(str, aim)!=0)
	{
		
		increaseStr(str,n);
		for (int i = 0; i<n; ++i)
			std::cout << str[i];
		std::cout << std::endl;
		
	}
	delete[]  str;
	delete[]  aim;

}
void printOneToMaxOfDigitalTest() {
	int n = 3;
	//printOneToMaxOfDigital(n);
	printOneToMaxOfDigitalByString(n);
}