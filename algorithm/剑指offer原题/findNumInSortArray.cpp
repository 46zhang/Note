#include <iostream>
/*
�㷨���ƣ�		�����������в�������
�㷨��Դ��		��ָOffer ������53
�㷨˼�룺		�����������в���������þ����ö��ֲ��ң�ʱ��Ч�ʿ죬����3��С�ⶼ�ǻ��ڶ��ֲ��ҵ�˼��

�㷨ע�⣺		1.�߽���
				2.ѭ����ֹ����
�㷨Ч�ʷ���:	�㷨ʱ�临�Ӷ�O(logn)���ռ临�Ӷ�O(1)
				
�㷨ʵ��ʱ��:	����20minʵ���㷨1������20minʵ���㷨2,����15Minʵ���㷨3

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
		std::cout << "����ǣ� " << num;
	else
		std::cout << "�Ҳ���" << std::endl;
}
static void findLostNumTest() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 },n=10;
	int num = findLostNum(arr,n);
	std::cout << "ȱʧ��������: " << num << std::endl;
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