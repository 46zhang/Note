#include <iostream>
/*
�㷨���ƣ��ڶ�ά�����в�������
�㷨��Դ����ָOffer ������4
�㷨˼�룺		�ж��ֽⷨ
				1.�����һ�е�ÿ�����ݽ��бȽϣ��������num��˵��Num���ܴ��ڸ��У�Ȼ���ٶԸ��н��ж��ֲ���
				2.������Ӱ��Χ��С����ѡ�����Ͻǵ����ݣ��������Num��˵�������в����ܴ���num�����С��num˵�������в�����num
					����С��Χ
�㷨ע�⣺		1.��ά����Ĵ���
				2.�±�ļ��
�㷨Ч�ʷ���:	1.�����£���Ҫ����n�У����ֲ���ʱ�临�Ӷ�ΪO(logn),�������ʱ�临�Ӷ�O(nlogn),�ռ临�Ӷ�O(1)
				2.ʱ�临�Ӷ�O(n),���Ƚ�n�����Ͻǵ�Ԫ�ؾͿ����ҵ��Ƿ�����ظ���������
�㷨ʵ��ʱ��:	�㷨1 ���˼�ʱ�����30min��
				�㷨2����˼·ʵ�ֺܿ죬6min�㶨
*/

//���ֲ���
bool searchBinary(int(*arr)[4],int i, int n,int num)
{
	if (NULL == arr || n <= 0 || i <= 0)
		return false;
	int begin = 0, end = n-1;
	//ÿһ�н��ж��ֲ���
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
//��ά����arr ,n�У�m��
bool findNumInArray(int arr[][4],int n,int m,int num)
{
	if (NULL == arr || n <= 0 || m <= 0)
		return false;
	int end=0;
	bool result = false;
	//�����һ�����ҳ�����Num���У�˵��num���ܴ��ڸ�����
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
		//�Կ��ܴ���Num��ÿһ�н��ж��ֲ���
		result = searchBinary(arr, i, n, num);
		if (result == true)
			return true;
	}
	return false;
}
//��ά����arr ,n�У�m��
bool findNum(int arr[][4], int n, int m, int num)
{
	//�߽���
	if (NULL == arr || n <= 0 || m <= 0)
		return false;
	int i =  0, j = m - 1;
	while (i < n && j >= 0)
	{
		//�Ƚ����Ͻǵ�����
		if (arr[i][j] == num)
			return true;
		//���С��num,˵��num��������һ��
		else if (arr[i][j] < num)
			++i;
		//�������num��˵��num��������һ��
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
		std::cout << "����";
	else
		std::cout << "������";
}
