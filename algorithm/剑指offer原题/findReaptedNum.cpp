#include <iostream>



/*
算法内容：		在长度为n的找到数组找到任一中重复的数字(数字范围0~n-1)
算法来源：		剑指Offer面试题3
算法思想：		有多种解法
				1.先排序后查找:慢,排序算法时间复杂度为(nlogn)
				2.哈希表;快，占内存，空间复杂度为(n)
				3.使用交换判断法，如果不存在重复的话，那么数字i所在的位置是对应下标i所指的空间
					所以交换每个数字，让其处于对应的位置，若有重复数字，则会出现所需交换的空间
					存在与自己值相等的数据
				4.借鉴二分查找的思想，如果不存在重复的数字，例如n=8,令m=n/2=4，那么0~3应该出现4次，4~8应该出现4次
算法注意：		1.检查数字范围的有效性
				2.判断数组是否维空
算法效率分析:	每个数字最多只需要交换俩次就能找到自己的位置，所以时间复杂度为O(n),空间复杂度O(1)
算法实现时间:	算法3 花了39min
				算法4的书上的实现我认为存在问题，当输入0，或者将strat改为0时存在问题
				自己采用递归实现算法4花了快90min,递归真的很坑，调式起来相当不方便，我佛了

*/

int countRange(const int* numbers, int length, int start, int end);

bool findReaptedNum(int arr[],int n,int *num)
{
	if (arr == NULL || n <= 0)
		return false;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i]<0 || arr[i]>n)
		{
			std::cout << "数字范围出错" << std::endl;
			return false;

		}
			
	}
	for (int k = 0; k < n; k++)
	{
		std::cout << "  " << arr[k];
	}
	std::cout << '\n';
	for (int i = 0; i < n; i++)
	{
		//如果不存在重复的话，当排好序时，下标i对应的是arr[i]的值
		if (i != arr[i])
		{
			for (int j = i; j < n;++j)
			{
				if (arr[i] == arr[arr[i]])
				{
					*num = arr[i];
					return true;
				}
				else {
					//交换
					int temp = arr[i];
					arr[i] = arr[arr[i]];
					arr[temp] = temp;
					std::cout << " i的值 "<<i<< " j的值" << j<<std::endl;
					for (int k=0;k<n;k++)
					{
						std::cout <<"  "<< arr[k];
					}
					std::cout << '\n';
				}
			
				if (arr[i] == i)
					break;
				
			}
		}
	}
	return false;
}

int binaryFindNum(int arr[], int begin,int end,int n)
{
	int big=0, small=0, mid = (begin + end) / 2,num=-1;
	if (begin >= end)
		return mid;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] >= mid&&arr[i]<end)
			++big;
		else if(arr[i]<mid&&arr[i]>=begin)
			++small; 
	}
	//说明 0-mid有重复数字
	if (small > mid-begin)
	{
		end = mid-1 ;
		num=binaryFindNum(arr,begin,end,n);
	}
	else if(big>end-mid)
	{
		begin = mid ;
		num=binaryFindNum(arr, begin, end, n);
	}
	else {
		num = binaryFindNum(arr, begin, mid, n);
		if (num == -1)
			num = binaryFindNum(arr, mid, end, n);
	}
	
	if (num != -1)
		return num;
	
	return -1;
	
	
}

//用二分查找的思想来实现找到重复数字
bool findReaptedNumByBinaryFine(int arr[], int n, int *num)
{
	if (arr == NULL || n <= 0)
		return false;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i]<0 || arr[i]>n)
		{
			std::cout << "数字范围出错" << std::endl;
			return false;

		}

	}
	for (int k = 0; k < n; k++)
	{
		std::cout << "  " << arr[k];
	}
	std::cout << '\n';
	
	*num = binaryFindNum(arr, 0,n,n);
	if (*num != -1)
		return true;
	return false;
}
int getDuplication(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return -1;

	int start = 1;
	int end = length - 1;
	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start;
		int count = countRange(numbers, length, start, middle);
		if (end == start)
		{
			if (count > 1)
				return start;
			else
				break;
		}

		if (count > (middle - start + 1))
			end = middle;
		else
			start = middle + 1;
	}
	return -1;
}

int countRange(const int* numbers, int length, int start, int end)
{
	if (numbers == nullptr)
		return 0;

	int count = 0;
	for (int i = 0; i < length; i++)
		if (numbers[i] >= start && numbers[i] <= end)
			++count;
	return count;
}



void findReaptedNumTest()
{
	int arr[10]{3,3,3,5,6,7,8,0,2,9}, n = 10,num;
	for (auto a : arr)
	{
		std::cout << a;
	}
	/*if (true == findReaptedNum(arr, n, &num))
	{
		std::cout << " 重复的数字是 " << num << std::endl;
	}
	else {
		std::cout << " 出现错误情况  " << "\n";
	}*/
	//num=getDuplication(arr,n);
	//std::cout << " 重复的数字是 " << num << std::endl;
	
	if (true == findReaptedNumByBinaryFine(arr, n, &num))
	{
		std::cout << " 重复的数字是 " << num << std::endl;
	}
	else {
		std::cout << " 出现错误情况  " << "\n";
	}

}