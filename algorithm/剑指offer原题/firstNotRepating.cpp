#include<iostream>
#include <vector>
#include <map>
using namespace std;
/*

�㷨���ƣ�		��һ��ֻ����һ�ε��ַ�
�㷨��Դ��		��ָOffer ������50
�㷨˼�룺		�ÿռ任ʱ�䣬ͳ���ַ����ù�ϣ������ʾ���ֹ��Ĵ���

�㷨ע�⣺		1.�߽���
				2.�ݹ���ֹ����
�㷨Ч�ʷ���:	�㷨1ʱ�临�Ӷ�O(n)
�㷨ʵ��ʱ��:	����20minʵ���㷨
				�ڶ����㷨������ַ����ģ���Ż���20min

*/

char firstNotRepeating(char *pStr) {
	char position[256];
	memset(position, -1, 256);
	for (int i = 0; i < strlen(pStr); ++i) {
		position[pStr[i]]++;
	}
	for (int i = 0; i < strlen(pStr); ++i)
	{
		if (position[pStr[i]] == 0)
			return pStr[i];
	}
}

char firstNotRepeatingCharInCharStream(vector<char> strVector) {
	map<char, int> repeatingNum;
	int i = 0,minIndex=strVector.size();
	char result='\0';
	for (auto iter = strVector.begin(); iter != strVector.end(); ++iter,++i) {
		if (repeatingNum.find(*iter) == repeatingNum.end())
			repeatingNum[*iter] = i;
		else
			repeatingNum[*iter] = -1;
	}
	for (auto iter = repeatingNum.begin(); iter != repeatingNum.end(); ++iter) {
		if (iter->second > 0 && iter->second < minIndex) {
			minIndex = iter->second;
			result = iter->first;
			
		}
			
	}
	return result;

}

void firstNotRepeatingTest() {
	char str[122] = "sfsdf34~!24";
	vector<char> strVec({ 's','f','s','d','f','3','4','~','!','2','4' });
	std::cout<<"�����: "<<firstNotRepeating(str)<<std::endl;
	std::cout << "�����: " << firstNotRepeatingCharInCharStream(strVec) << std::endl;
}