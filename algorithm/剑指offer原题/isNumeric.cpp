#include<iostream>
#include <map>

std::map<char, int>opera = { {'-',0},{'+',0},{'.',-2},{'e',1},{'E',1} };

bool isNumericI(char *str) {
	int eFlag = false;
	for (int i = 0; str[i]; ++i) {
		if (str[i] >= '0' && str[i] <= '9')
			continue;
		else if (opera.find(str[i]) != opera.end()) {
			//说明后面一定要跟数字
			if (opera[str[i]] <= 0) {
				if (eFlag&&opera[str[i]] == -2 )
					return false;
				else if (str[i + 1] != '\0'&&str[i + 1] >= '0' && str[i + 1] <= '9')
					continue;
				else if (opera[str[i]] == 0 && opera.find(str[i+1]) != opera.end()&& opera[str[i + 1]]==-2)
					continue;
				else 
					return false;
			}
			else {
				eFlag = true;
				if (str[i + 1] != '\0'&&str[i + 1] >= '0' && str[i+1] <= '9')
					continue;
				else if (str[i + 1] != '\0'&&opera.find(str[i+1]) != opera.end() && opera[str[i+1]] == 0)
					continue;
				else
					return false;
			}
		}
		else
			return false;
	}
	return true;
}

bool scanUnsignedInteger(char **str) {
	char *before = *str;
	while (*str != '\0'&&**str >= '0'&&**str <= '9')
		++(*str);
	return *str > before;
}
bool scanInteger(char **str) {
	while (*str != '\0'&&**str == '-' || **str == '+')
		++(*str);
	return scanUnsignedInteger(str);
}
bool isNumericII(char *str) {
	if (str == NULL)
		return false;
	bool numeric = scanInteger(&str);
	//如果是小数点，允许前面没有整数，但是后面一定要有整数
	if (*str == '.') {
		++str;
		numeric = scanUnsignedInteger(&str) || numeric;
	}
	//前面一定要有整数
	if (*str == 'e' || *str == 'E') {
		++str;
		numeric = scanInteger(&str) && numeric;
	}
		
	return numeric && *str == '\0';
}
void isNumericTest()
{
	double a = 12e+5;
	//char str[20] = "12e+5.4";
	//char str[20] = "-.123";
	//char str[20] = "-1E-16";
	char str[20] = "1+123";
	if (true == isNumericII(str))
		std::cout << "是数字" << std::endl;
	else
		std::cout << "不是数字" << std::endl;

}