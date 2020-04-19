#include <iostream>
/*
算法名称：正则表达式匹配
算法来源：剑指Offer 面试题19
算法思想：		先判断模式字符串第二个是否是* ，是的话就需要进行做一些特殊处理，
					有2种选择：
					(1).模式字符串第一个=字符串||模式字符串第一个为‘.’且目标字符串不为空
							可以有3种选择 
								a.模式字符串,目标字符串+1,继续递归下去，相当于*匹配了n个字符
								b.模式字符串+2，目标字符串,相当于 * 匹配0个字符
								c.模式字符串+2,目标字符串+1,相当与*匹配1个字符
					(2). 模式字符串第一个！=目标字符串第一个&&模式字符串第一个不为‘.’或者目标字符串为空
						模式字符串+2，目标字符串,相当于 * 匹配0个字符

算法注意：		1.递归结束的条件
				2.在判断模式字符串是否为"."时要注意此时的目标字符串是否位空
算法效率分析:	1.nlog(n)
算法实现时间:	算法1 花了半个小时实现算法，花了1个小时debug，太坑了，一值没去注意好检
					查模式字符串是否为"."时要注意此时的目标字符串是否位空

*/
bool match(char *str,char *mode) {
	std::cout << str << "  " << mode<<std::endl;
	if (*str == '\0' && *mode == '\0')
	{
		std::cout << "都为Null啦" << std::endl;
		return true;
	}
	else if (*str == '\0' || *mode == '\0') {
		std::cout << "sdsdf" << std::endl;
		return false;
	}
		
	int len = strlen(mode);
	bool s = false;
	if (len > 1 && mode[1] == '*') {
		if (str[0] == mode[0] ||( mode[0] == '.'&&*str!='\0')) {
			std::cout << "2131" << std::endl;
			return match(str, mode + 2) || match(str + 1, mode) || match(str + 1, mode + 2);
		}
		else
			return match(str, mode + 2);
	}
	else {
		if (mode[0] == str[0] || (mode[0] == '.'&& *str != '\0'))
			return  match(str + 1, mode + 1);
		
	}
	return false;
		
}
bool matchAll(char *str, char *mode)
{
	if (str == nullptr || mode == nullptr)
		return false;
	return match(str, mode);
}
void reMatch() {
	//char str[20] = "bcbbabab";
	//char mode1[20] = ".*a*a",mode2[20]="ab*ac*afdb";
	char str[20] = "a";
	char mode1[20] = ".*",mode2[20]="ab*ac*afdb";
	bool s1 = matchAll(str, mode1);
	bool s2 = matchAll(str, mode2);
	if (s1)
		std::cout << "与模式1匹配" << std::endl;
	else
		std::cout << "与模式1不匹配" << std::endl;
	if (s2)
		std::cout << "与模式2匹配" << std::endl;
	else
		std::cout << "与模式2不匹配" << std::endl;
}