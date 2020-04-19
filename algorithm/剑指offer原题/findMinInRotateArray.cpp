#include <iostream>

/*
算法名称：旋转数组的最小数字
算法来源：剑指Offer 面试题11
算法思想：		在不考虑存在重复数字的情况下，采用二分查找的思路，逐步去缩小比较的范围
					(1). 先找中间节点是否大于最后一个节点，是跳转2，否跳转3(是的话说明现在中间节点属于旋转序列否则说明属于递增序列)
					(2). end=mid
					(3). begin=mid
					(4). 再次进行比较，begin位于递增序列的最后一个节点，end位于选择序列的第一个节点时结束循环
					(5). 返回end，end就是我们要的最小值
					(6). 如果存在重复数字，需要考虑中间节点==最后一个节点的情况，此时无法确定最小值的存在需要进行顺序查找
算法注意：		1.考虑旋转0个的情况
				2.考虑存在重复数字的情况{1,0,1,1,1,1},{1,1,1,0,1}的情况
				3.边界检测，内存判断
算法效率分析:	1.
				2.
算法实现时间:	算法1 

*/

int findMinInRotateArray(int arr[],int n)
{
	int a=0, b=n-1,mid;
	if (arr == NULL||n<=0)
		return -1;
	if (arr[0] < arr[b])
		return arr[0];
	while (a+1<b)
	{
		mid = (a + b) / 2;
		if (arr[mid] > arr[b])
			a = mid;
		else if (arr[mid] == arr[b])
			break;
		else
			b = mid;

	}
	return arr[b];
}

int minInOrder(int arr[],int a,int b)
{
	for (int i = a; i < b-1; ++i)
	{
		if (arr[i] > arr[i + 1])
			return arr[i+1];
	}
	return -1;
}
int findMinInRotateArrayWithReaptedNum(int arr[], int n)
{
	int a = 0, b = n - 1, mid;
	if (arr == NULL || n <= 0)
		return -1;
	//说明旋转0个数字
	if (arr[0] < arr[b])
		return arr[0];
	while (a + 1 < b)
	{
		mid = (a + b) / 2;

		if (arr[mid] == arr[b] && arr[mid] == arr[a])
			return minInOrder(arr, a, b);
		if (arr[mid] >= arr[b])
			a = mid;
		else if(arr[mid]<=arr[a])
			b = mid;

	}
	return arr[b];
}

void findMinInRotateArrayTest()
{
	int arr[7] = {1, 1,0,1,1,1,1 },n=7;
	int min= findMinInRotateArrayWithReaptedNum(arr, n);
	std::cout << min;
}