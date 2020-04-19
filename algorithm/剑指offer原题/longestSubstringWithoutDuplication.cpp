#include <iostream>
#include <string>

int longestSubstringWithoutDuplication(const std::string &str) {
	int len = str.size();
	int *num = new int[len],i=1,j=0,d=0,max=0;
	num[0] = 1;
	for (i = 1; i < len; ++i) {
		for (d = 1, j = i-1; j >= 0; --j)
		{
			if (str[j] == str[i])
				break;
			++d;
		}

		if (d > num[i - 1] || d > i)
			num[i] = num[i - 1] + 1;
		else if (d > 1 && d < num[i - 1])
			num[i] = num[i - 1] - d + 1;
		else if (d == num[i - 1])
			num[i] = num[i - 1];
		else if (d == 1&&i!=1)
			num[i] = 1;
		if (max < num[i])
			max = num[i];
		std::cout <<" d: "<<d<<"   " <<num[i]<<"   ";
	}
	delete[] num;
	return max;
}

int longestSubstringWithoutDuplicationII(const std::string &str) {
	if (str.size() <= 0)
		return 0;
	int len=str.size(), maxLen=0, curLen=0, preIndex=0;
	int * position = new int[26];
	memset(position, -1, 26);
	for (int i = 0; i < len; ++i) {
		preIndex = position[str[i] - 'a'];
		//如果该字符没出现过或者出现的下标大于当前的长度(即不把其算在内了)
		if (preIndex<0 || i-preIndex>curLen)
			++curLen;
		else {
			if (maxLen < curLen)
				maxLen = curLen;
			curLen = i-preIndex;
		}
		//更新坐标
		position[str[i] - 'a'] = i;

	}
	if (maxLen < curLen)
		maxLen = curLen;
	delete[] position;
	return maxLen;

}
void longestSubstringTest() {
	std::string str = "arabcacfr";
	//std::string str = "bcdaab";
	//int a = longestSubstringWithoutDuplication(str);
	int a = longestSubstringWithoutDuplicationII(str);
	std::cout << "最大的子字符串为 : " << a << std::endl;
}