#include <iostream>

/*
�㷨���ƣ���ӡ��1��nλ�������
�㷨��Դ����ָOffer ������17
�㷨˼�룺		�ж��ֽⷨ
				

�㷨ע�⣺		
�㷨Ч�ʷ���:	
�㷨ʵ��ʱ��:	�㷨1 20min
				�㷨2 ����40Min
*/

//���������������⣬��n��λ������INT��󳤶�ʱ��������
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