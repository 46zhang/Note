#include <iostream>
/*
算法名称：		在排序数组中查找数字
算法来源：		剑指Offer 面试题53
算法思想：		在排序数组中查找数字最好就是用二分查找，时间效率快，题中3道小题都是基于二分查找的思想

算法注意：		1.边界检查
				2.循环终止条件
算法效率分析:	算法时间复杂度O(logn)，空间复杂度O(1)
				
算法实现时间:	花了20min实现算法1，花了20min实现算法2,花了15Min实现算法3

*/
int getFirstK(int *sortArray, int len,int k) {
	if (sortArray == NULL || len <= 0)
		return 0;
	int begin = 0, end = len - 1,mid;
	while (begin <= end) {
		mid = (begin + end) / 2;
		if (sortArray[mid] == k)
		{
			if (mid == 0 || mid > 0 && sortArray[mid - 1] != k)
				return mid;
			else
				end = mid - 1;
		}
		else if (sortArray[mid] < k)
			begin = mid + 1;
		else
				end = mid - 1;
	}
	return -1;
}
int getLastK(int *sortArray,int len,int k) {
	if (sortArray == NULL || len <= 0)
		return 0;
	int begin = 0, end = len - 1, mid;
	while (begin <= end) {
		mid = (begin + end) / 2;
		if (sortArray[mid] == k)
		{
			if (mid == end || mid < end && sortArray[mid + 1] != k)
				return mid;
			else
				begin = mid + 1;
		}
		else if (sortArray[mid] < k)
			begin = mid + 1;
		else
			end = mid - 1;
	}
	return -1;
}

static int getNumOfK(int *sortArray,int len,int k) {
	if (sortArray == NULL || len <= 0)
		return 0;
	int start, end;
	start = getFirstK(sortArray,len,k);
	end = getLastK(sortArray, len, k);
	std::cout << "start: " << start << " end: " << end << std::endl;
	if (start < 0 || end < 0)
		return -1;
	else
		return end - start+1;
}

static int findLostNum(int *sortArr,int len) {
	if (sortArr == NULL || len <= 0)
		return -1;
	int begin = 0, end = len - 1;
	int mid = 0;
	while (begin <= end) {
		mid = (begin + end) / 2;
		if (sortArr[mid] > mid) {
			if (mid == 0 || mid > 0 && sortArr[mid - 1] <= mid - 1)
				return mid;
			else
				end = mid - 1;
		}
		else
			begin = mid + 1;
	}
	return -1;
}

bool findEqualIndexNumTest(int *sortArr, int len, int &num) {
	if (sortArr == NULL || len <= 0)
		return false;
	int begin = 0, end = len - 1;
	while (begin <= end) {
		int mid = (begin + end) / 2;
		if (sortArr[mid] == mid) {
			num = mid;
			return true;
		}
		else if (sortArr[mid] > mid)
			end = mid - 1;
		else
			begin = mid + 1;
	}
	return false;
}

static void findEqualIndexNumTest() {
	int arr[10] = { -1,-2,0,1,2,5,6,7,7,10 }, n = 10, num = 0;
	if (true == findEqualIndexNumTest(arr, n, num))
		std::cout << "结果是： " << num;
	else
		std::cout << "找不到" << std::endl;
}
static void findLostNumTest() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 },n=10;
	int num = findLostNum(arr,n);
	std::cout << "缺失的数字是: " << num << std::endl;
}

static void getNumOfKTest() {
	int arr[10] = { 1,1,2,2,3,4,5,7,7,7 }, n = 10, k = 1;
	int kTime = getNumOfK(arr, n, k);
	std::cout << kTime << std::endl;
}
void findNumInSortArrayTest() {
	//getNumOfKTest();
	//findLostNumTest();
	findEqualIndexNumTest();
}