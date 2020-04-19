#include <iostream>
/*
算法名称：在二维数组中查找数字
算法来源：剑指Offer 面试题4
算法思想：		有多种解法
				1.对最后一行的每个数据进行比较，如果大于num，说明Num可能存在该列，然后再对该列进行二分查找
				2.采用阴影范围缩小法，选择右上角的数据，如果大于Num，说明所在行不可能存在num，如果小于num说明所在列不存在num
					逐渐缩小范围
算法注意：		1.二维数组的传递
				2.下标的检查
算法效率分析:	1.最坏情况下，需要查找n列，二分查找时间复杂度为O(logn),所以最坏的时间复杂度O(nlogn),空间复杂度O(1)
				2.时间复杂度O(n),最多比较n个右上角的元素就可以找到是否存在重复的数字了
算法实现时间:	算法1 忘了计时，大概30min把
				算法2有了思路实现很快，6min搞定
*/

//二分查找
bool searchBinary(int(*arr)[4],int i, int n,int num)
{
	if (NULL == arr || n <= 0 || i <= 0)
		return false;
	int begin = 0, end = n-1;
	//每一列进行二分查找
	while (begin <= end)
	{
		int mid = (begin + end) / 2;
		if (arr[mid][i] == num)
			return true;
		else if (arr[mid][i] > num)
			end = mid - 1;
		else
			begin = mid + 1;
	}
	return false;
}
//二维数组arr ,n行，m列
bool findNumInArray(int arr[][4],int n,int m,int num)
{
	if (NULL == arr || n <= 0 || m <= 0)
		return false;
	int end=0;
	bool result = false;
	//在最后一行先找出大于Num的列，说明num可能存在该列中
	while (end < n)
	{
		if (arr[n - 1][end] > num)
			break;
		if (arr[n - 1][end] == num)
			return true;
		++end;
	}
	for (int i = end; i < m; ++i)
	{
		//对可能存在Num的每一列进行二分查找
		result = searchBinary(arr, i, n, num);
		if (result == true)
			return true;
	}
	return false;
}
//二维数组arr ,n行，m列
bool findNum(int arr[][4], int n, int m, int num)
{
	//边界检测
	if (NULL == arr || n <= 0 || m <= 0)
		return false;
	int i =  0, j = m - 1;
	while (i < n && j >= 0)
	{
		//比较右上角的数据
		if (arr[i][j] == num)
			return true;
		//如果小于num,说明num不存在这一行
		else if (arr[i][j] < num)
			++i;
		//如果大于num，说明num不存在这一列
		else
			--j;
	}
}
void  findNumInArrayTest()
{
	int numArray[5][4] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}, {9,10,18,20} };
	int(*point)[4] = numArray;
	int n = 5, m = 4, num = 8;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			std::cout << point[i][j]<<"  ";
	}
	std::cout << std::endl;
	//bool s=findNumInArray(numArray, n, m, num);
	bool s=findNum(numArray, n, m, num);
	if (s == true)
		std::cout << "存在";
	else
		std::cout << "不存在";
}
