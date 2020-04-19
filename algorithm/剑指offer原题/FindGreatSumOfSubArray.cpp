#include <iostream>

/*
算法名称：		连续子数组的最大值
算法来源：		剑指Offer 面试题42
算法思想：		3种解法
				1. 直接求各种子组合O(n*n)的时间复杂度
				2. 观察数组的特点，当其相加之和小于原来的数字时，说明其前面都是负数，直接丢弃前面的子数组的和
					当其加上num[i]小于原先子数组的值时，先保存下该值，然后再继续相加
				3. 使用动态规划，sum[i]表示下标为i的最大子数组的和，当sum[i-1]<0时，sum[i]=num[i]
					当sum[i-1]>0时，sum[i]=sum[i-1]+sum[i]
算法注意：		1.边界检查
				2.结尾NULL指针的设置
算法效率分析:	1. 时间复杂度O(n*n)，空间复杂度O(1)
				2. 时间复杂度O(n)，空间复杂度O(1)
				3. 时间复杂度O(n)，空间复杂度O(n)		
算法实现时间:	花了半个小时实现算法1
				花了半个小时实现算法2
				花了20min实现算法3

*/


//求组合的做法有问题，因此其可以是不连续的
int findGreatSumOfSubArrayError(int *pNum,int len,int index,int *result,int *max) {
	if (pNum == NULL || len <= 0||index>=len)
		return 0;
	for (int i = index; i < len; ++i) {
		std::cout <<  "加之前 result: " << *result << std::endl;
		*result = *result + pNum[i];
		std::cout << " index: " << index << " i " << i << " pnum[i] " << pNum[i] << " result: " << *result << std::endl;
		if (*result > *max)
			*max = *result;
		findGreatSumOfSubArrayError(pNum, len, i + 1, result, max);
		*result =*result- pNum[i];
		std::cout << " index: " << index << " i " << i << " pnum[i] " << pNum[i] << " result: " << *result << std::endl;
	}
	return *max;
}

//用动态规划的思想实现
int findGreatSumOfSubArrayII(int *pNum, int len) {
	if (pNum == nullptr || len <= 0)
		return 0;
	int *sum = new int[len],result=0;
	sum[0] = pNum[0];
	for (int i = 1; i < len; ++i) {
		if (sum[i - 1] < 0)
			sum[i] = pNum[i];
		else
			sum[i] = sum[i-1]+pNum[i];
		if (sum[i] > result)
			result = sum[i];
	}
	
	delete[] sum;
	return result;
}


int findGreatSumOfSubArray(int *pNum,int len) {
	if (pNum == nullptr || len <= 0)
		return 0;
	int temp = 0, result = 0;
	for (int i = 0; i < len; ++i) {
		if (pNum[i] + temp < pNum[i])
			temp = pNum[i];
		else if (pNum[i] + temp < temp) {
			if (result < temp)
				result = temp;
			temp += pNum[i];
		}
		else
			temp += pNum[i];
	}
	if (result < temp)
		result = temp;
	return result;
}
void findGreatSumOfSubArrayTest() {
	int num[8] = { 1,-2,3,10,-4,7,2,-5 }, n = 8;
	//int num[4] = { 1,-4,7,-2}, n = 4;
	int result = 0,max=0;
	//int a = findGreatSumOfSubArrayError(num,n,0,&result,&max);
	//int a = findGreatSumOfSubArray(num, n);
	int a = findGreatSumOfSubArrayII(num, n);
	std::cout << a << std::endl;
}