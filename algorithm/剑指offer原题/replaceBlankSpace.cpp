#include <iostream>
#include <map>
#include <vector>
#pragma  warning (disable:4996) 
/*
算法名称：		字符串替换空格
算法来源：		剑指Offer 面试题5
算法思想：		有多种解法
				1.使用string拼接，返回新的字符串
				2. 使用Char,返回新的字符串 前俩个都是需要O（n）的空间
				3，第三个使用先遍历后挪动的思想，不需要构造新的字符串，直接在原字符串上进行挪动
					(1).先从左往右遍历字符串
					(2).找到空格的个数，记录下来，记录下个数，位置可以记录也可以不记，因为后续可用指针表示
					(3).判断剩余空间够不够，必须得有  strlen(oldstring)+空格个数*2的内存大小才够
					(4).进行挪动，我的代码实现是借助一个容器来存储空格的位置坐标，可以像剑指Offer那样直接用指针指向
						就可以节省空间
算法注意：		1.剩余内存空间的判断
				2.字符串的拼接
算法效率分析:	1 \2.时间复杂度O(n),空间复杂度O(n)
				3.时间复杂度O(n),使用俩个指针时，空间复杂度O(1)
算法实现时间:	算法1 10min
				算法2 20min
				算法3 50min
*/


char changeString[4]="%20";
bool replaceBlankByCharArray(char *str,char *newStr,int newStrLength)
{
	if (NULL == str || newStr == NULL)
		return false;
	int len = strlen(str);
	int j = 0;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == ' ')
		{
			if (j + 3 < newStrLength)
			{
				for (int k = 0; k < 3; ++k)
					newStr[j++] = changeString[k];
			}
			else
				return false;
		}
		else
			newStr[j++] = str[i];
		if (j > newStrLength)
			return false;
	}
	newStr[j] = '\0';
	return true;
}

//通过String对象来替换
bool replaceBlankByString(std::string str, std::string & newStr)
{
	if (str.size() == 0)
		return false;
	//初始化newStr
	newStr = "";
	for (auto a = str.begin(); a != str.end(); ++a)
	{
		if (*a == ' ')
			newStr += "%20";
		else
			newStr += *a;
	}
	for (auto c : newStr)
		std::cout << c;
	std::cout << std::endl;
	return true;
}

//在原来的字符串上进行替换
bool replaceBlankInOldArray(char *str, int memoryLen)
{
	if (str == NULL || memoryLen <= 0)
		return false;
	int j = 0,i=0;
	const int strLen = strlen(str);
	std::map<int,int> indexList;
	//先从左到右遍历一遍,记下空格的个数以及位置坐标
	for (i = 0; i < strLen; ++i)
	{
		if (str[i] == ' ')
		{
			++j;
			//记下其对应的新数组所在的位置
			indexList[i]=j*2+i;
		}
	}
	for (auto a : indexList)
	{
		std::cout << a.first <<"  "<< a.second << std::endl;
	}
	std::cout << strLen << ' ' << memoryLen << std::endl;
	//判断剩余空间是否足够存下变长后的数组
	if (memoryLen < j * 2 + strLen)
		return false;
	str[j * 2 + strLen] = '\0';
	for (int k = j * 2 + strLen-1; k >= 0;)
	{
		
		if (j <= 0)
			break;
		//如果该下标为空格下标进行替换
		if (indexList.find(k - 2 * j) != indexList.end())
		{
			str[k--] = '0';
			str[k--] = '2';
			str[k--] = '%';
			--j;
		}
		//否则就进行挪位
		else if (str[i-1] == ' ')
			--i;
		else
			str[k--] = str[--i];
	}
	
 	return true;
}
void replaceBlankSpaceTest()
{
	std::string a = "We are happy",newString;
	char str[30] = "We are happy", *p, len = strlen(str)*3;
	p = (char*)malloc(sizeof(char)*len );
	//bool status=replaceBlankByString(a, newString);
	//for (auto c : newString)
	//	std::cout << c;
	//bool status = replaceBlankByCharArray(str, p, len );
	//for (int i = 0; p[i]!='\0'; i++)
		//std::cout << p[i];
	bool status = replaceBlankInOldArray(str,30);
	for (int i = 0; i<strlen(str); i++)
		std::cout << str[i];
}