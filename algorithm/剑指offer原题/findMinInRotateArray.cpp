#include <iostream>

/*
�㷨���ƣ���ת�������С����
�㷨��Դ����ָOffer ������11
�㷨˼�룺		�ڲ����Ǵ����ظ����ֵ�����£����ö��ֲ��ҵ�˼·����ȥ��С�Ƚϵķ�Χ
					(1). �����м�ڵ��Ƿ�������һ���ڵ㣬����ת2������ת3(�ǵĻ�˵�������м�ڵ�������ת���з���˵�����ڵ�������)
					(2). end=mid
					(3). begin=mid
					(4). �ٴν��бȽϣ�beginλ�ڵ������е����һ���ڵ㣬endλ��ѡ�����еĵ�һ���ڵ�ʱ����ѭ��
					(5). ����end��end��������Ҫ����Сֵ
					(6). ��������ظ����֣���Ҫ�����м�ڵ�==���һ���ڵ���������ʱ�޷�ȷ����Сֵ�Ĵ�����Ҫ����˳�����
�㷨ע�⣺		1.������ת0�������
				2.���Ǵ����ظ����ֵ����{1,0,1,1,1,1},{1,1,1,0,1}�����
				3.�߽��⣬�ڴ��ж�
�㷨Ч�ʷ���:	1.
				2.
�㷨ʵ��ʱ��:	�㷨1 

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
	//˵����ת0������
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