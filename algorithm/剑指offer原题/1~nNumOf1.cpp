#include<iostream>
#include <string>

/*
算法名称：		1-n整数中出现1的个数
算法来源：		剑指Offer 面试题43
算法思想：		比较直接的想法就是遍历1—n的每个整数然后累加
				书中给出的解法更为精妙，通过观察数字的规律找出一些新的解法
					以23456为例子，首先其最高位的1的个数 为  10000-19999 共10000个数，如果其为123456
					那么最高位出现的数字为  10000-13456 共 3457个数字,所以最高位置1的个数为 
						if 最高位数字 >1  次数=pow(10,总位数-1)，else 次数=剩余数字大小+1
					解决了最高位后就需要找剩下的，需要找出 23456中在剩下4个位数出现1的概率，把23456分成俩部分
					3456-13455，13456-23456，这俩部分的数字每位数字都有出现0-9这10个数字的可能,由排列组合公式可知
						次数=2(因为划分为俩部分)*4(数字位数-1)*10^3（每位数字都有10种可能）
					把这俩部分加起来就是3456~23456的个数
					然后再递归求(3456)的个数

算法注意：		1.边界检查
				2.递归终止条件
算法效率分析:	算法1时间复杂度O(nlogn)，空间复杂度O(1)
				算法2时间复杂度O(logn)，空间复杂度O(1)
算法实现时间:	花了1个小时20min思考实现算法，前期的构思花了很多时间，所以写代码的时候一遍过，没有bug

*/

int numOfOne(int n) {
	if (n <= 0)
		return 0;
	else if (n < 10)
		return 1;
	std::string numStr = std::to_string(n);
	int len = numStr.size(), time = 0;
	std::string nextStr(numStr.substr(1, len));
	int nextNum = 0;
	//先算最高为1出现的个数
	nextNum=stoi(nextStr);
	nextStr = numStr.substr(1, len);
	std::cout << numStr <<"  "<< nextStr<<std::endl;
	if (numStr[0] > '1')
		time = pow(10, len - 1);
	else  
		time += nextNum+1;
	int high = numStr[0] - '0';
	std::cout << "计算完最高位time:" << time<<std::endl;
	time += high * (len - 1)*pow(10, len - 2);
	std::cout << "计算完剩下n位time:" << time << std::endl;
	time += numOfOne(nextNum);
	std::cout << "计算完剩下一个数字time:" << time << std::endl;
	return time;
	
		
}

void numOfOneTest() {
	int n = 10;
	int a = (numOfOne(n));
}