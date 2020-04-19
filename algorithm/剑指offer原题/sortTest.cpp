#include <iostream>
/*
算法名称：快速排序
算法来源：
算法思想：		有多种解法
				1.使用递归构造法，通过观察中序数组跟先序数组，发现每个先序数组的第一个值就是子树的根节点，由于不存在重复的值
					所以找到该值在中序数组中的位置x，中序数组中值在x左边为左子树，在右边的为右子树
					算法步骤：
					(1). 先取出前序数组的一个值
					(2). 找出中序数组的该值的位置x
					(3). 以该值创建节点，为该子树的根节点
					(4). 判断x左边是否有值,有的话，进行递归构造左子树
					(5). 判断x右边是否有值,有的话，进行递归构造右子树

算法注意：		1.边界检查
				2.递归传递时注意参数的选择，不要重复不要越界
算法效率分析:	1.最坏情况下，需要查找n列，二分查找时间复杂度为O(logn),所以最坏的时间复杂度O(nlogn),空间复杂度O(1)
				2.时间复杂度O(n),最多比较n个右上角的元素就可以找到是否存在重复的数字了
算法实现时间:	

*/

//选择中间比较枢纽
int chocieMidIndex(int num[],int begin,int mid,int end)
{
	if (begin >= end)
		return begin;
	if (num[begin] * 2 > num[mid] + num[end - 1] &&num[begin]<=num[mid]||num[begin]<=num[end-1])
		return begin;
	else if (num[mid] * 2 > num[begin] + num[end - 1] && num[mid] <= num[begin] || num[mid] <= num[end - 1])
		return mid;
	else
		return end-1;
}

//快速排序
bool quickSort(int *num,int begin,int end)
{
	if (num == NULL||begin>=end)
		return false;
	int mid = (end + begin) / 2;
	//采用三点选择法选择合适的比较中枢
	mid = chocieMidIndex(num, begin, mid, end);
	int a = begin, b = end-1,temp=num[mid];
	while (a <= b)
	{
		while (a<end&&num[a] <= temp)
			++a;
		while (b > begin && num[b] >= temp)
			--b;
		if (a >= b)
			break;
		int t = num[a];
 		num[a] = num[b];
		num[b] = t;
		++a, --b;
		for (int i = begin; i < end; ++i)
		{
			std::cout << num[i] << " ";
		}
		std::cout <<" 交换中" <<std::endl;
	}
	int min = (a > b ? b : a);
	//最后进行交换赋值
	num[mid] = num[min];
	num[min] = temp;
	for (int i = 0; i < end; ++i)     
	{
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;
	//一趟排序结束
	quickSort(num, begin, min);
	quickSort(num, min+1, end);
	return true;
}

//快速排序
bool quickSortII(int *num, int begin, int end)
{
	if (num == NULL || begin >= end)
		return false;
	int mid = (end + begin) / 2;
	//采用三点选择法选择合适的比较中枢
	mid = chocieMidIndex(num, begin, mid, end);
	int a = begin - 1, b = end, temp = num[mid];
	while (a < b)
	{
		while (a < end&&num[++a] <= temp)
			;
		while (b > begin && num[--b] >= temp)
			;
		if (a >= b)
			break;
		int t = num[a];
		num[a] = num[b];
		num[b] = t;
	}
	int min = (a > b ? b : a);
	//最后进行交换赋值
	num[mid] = num[min];
	num[min] = temp;
	for (int i = 0; i < end; ++i)
	{
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;
	//一趟排序结束
	quickSortII(num, begin, min);
	quickSortII(num, min + 1, end);
	return true;
	
}

int *createRandomNumList(int n)
{
	int *num = new int[n + 1];
	for (int i = 0; i < n; ++i)
	{
		num[i]=(rand() % (n*n + 1)) + 0;
	}
	return num;
}
void sortTest()
{
	int n = 8 ,*num = createRandomNumList(n);
	for (int i = 0; i < n; ++i)
	{
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;
	bool status=quickSort(num, 0, n);
	if (status == false)
		std::cout << "排序失败";
	else
	{
		for (int i = 0; i < n; ++i)
		{
			std::cout << num[i] << " ";
		}
		std::cout << std::endl;
	}
	/*bool status1 = quickSortII(num, 0, n);
	if (status1 == false)
		std::cout << "排序失败";
	else
	{
		for (int i = 0; i < n; ++i)
		{
			std::cout << num[i] << " ";
		}
		std::cout << std::endl;
	}*/
	
}