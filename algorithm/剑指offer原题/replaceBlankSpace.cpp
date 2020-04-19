#include <iostream>
#include <map>
#include <vector>
#pragma  warning (disable:4996) 
/*
�㷨���ƣ�		�ַ����滻�ո�
�㷨��Դ��		��ָOffer ������5
�㷨˼�룺		�ж��ֽⷨ
				1.ʹ��stringƴ�ӣ������µ��ַ���
				2. ʹ��Char,�����µ��ַ��� ǰ����������ҪO��n���Ŀռ�
				3��������ʹ���ȱ�����Ų����˼�룬����Ҫ�����µ��ַ�����ֱ����ԭ�ַ����Ͻ���Ų��
					(1).�ȴ������ұ����ַ���
					(2).�ҵ��ո�ĸ�������¼��������¼�¸�����λ�ÿ��Լ�¼Ҳ���Բ��ǣ���Ϊ��������ָ���ʾ
					(3).�ж�ʣ��ռ乻�������������  strlen(oldstring)+�ո����*2���ڴ��С�Ź�
					(4).����Ų�����ҵĴ���ʵ���ǽ���һ���������洢�ո��λ�����꣬������ָOffer����ֱ����ָ��ָ��
						�Ϳ��Խ�ʡ�ռ�
�㷨ע�⣺		1.ʣ���ڴ�ռ���ж�
				2.�ַ�����ƴ��
�㷨Ч�ʷ���:	1 \2.ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
				3.ʱ�临�Ӷ�O(n),ʹ������ָ��ʱ���ռ临�Ӷ�O(1)
�㷨ʵ��ʱ��:	�㷨1 10min
				�㷨2 20min
				�㷨3 50min
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

//ͨ��String�������滻
bool replaceBlankByString(std::string str, std::string & newStr)
{
	if (str.size() == 0)
		return false;
	//��ʼ��newStr
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

//��ԭ�����ַ����Ͻ����滻
bool replaceBlankInOldArray(char *str, int memoryLen)
{
	if (str == NULL || memoryLen <= 0)
		return false;
	int j = 0,i=0;
	const int strLen = strlen(str);
	std::map<int,int> indexList;
	//�ȴ����ұ���һ��,���¿ո�ĸ����Լ�λ������
	for (i = 0; i < strLen; ++i)
	{
		if (str[i] == ' ')
		{
			++j;
			//�������Ӧ�����������ڵ�λ��
			indexList[i]=j*2+i;
		}
	}
	for (auto a : indexList)
	{
		std::cout << a.first <<"  "<< a.second << std::endl;
	}
	std::cout << strLen << ' ' << memoryLen << std::endl;
	//�ж�ʣ��ռ��Ƿ��㹻���±䳤�������
	if (memoryLen < j * 2 + strLen)
		return false;
	str[j * 2 + strLen] = '\0';
	for (int k = j * 2 + strLen-1; k >= 0;)
	{
		
		if (j <= 0)
			break;
		//������±�Ϊ�ո��±�����滻
		if (indexList.find(k - 2 * j) != indexList.end())
		{
			str[k--] = '0';
			str[k--] = '2';
			str[k--] = '%';
			--j;
		}
		//����ͽ���Ųλ
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