#include <iostream>
/*
�㷨���ƣ���������
�㷨��Դ��
�㷨˼�룺		�ж��ֽⷨ
				1.ʹ�õݹ鹹�취��ͨ���۲�����������������飬����ÿ����������ĵ�һ��ֵ���������ĸ��ڵ㣬���ڲ������ظ���ֵ
					�����ҵ���ֵ�����������е�λ��x������������ֵ��x���Ϊ�����������ұߵ�Ϊ������
					�㷨���裺
					(1). ��ȡ��ǰ�������һ��ֵ
					(2). �ҳ���������ĸ�ֵ��λ��x
					(3). �Ը�ֵ�����ڵ㣬Ϊ�������ĸ��ڵ�
					(4). �ж�x����Ƿ���ֵ,�еĻ������еݹ鹹��������
					(5). �ж�x�ұ��Ƿ���ֵ,�еĻ������еݹ鹹��������

�㷨ע�⣺		1.�߽���
				2.�ݹ鴫��ʱע�������ѡ�񣬲�Ҫ�ظ���ҪԽ��
�㷨Ч�ʷ���:	1.�����£���Ҫ����n�У����ֲ���ʱ�临�Ӷ�ΪO(logn),�������ʱ�临�Ӷ�O(nlogn),�ռ临�Ӷ�O(1)
				2.ʱ�临�Ӷ�O(n),���Ƚ�n�����Ͻǵ�Ԫ�ؾͿ����ҵ��Ƿ�����ظ���������
�㷨ʵ��ʱ��:	

*/

//ѡ���м�Ƚ���Ŧ
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

//��������
bool quickSort(int *num,int begin,int end)
{
	if (num == NULL||begin>=end)
		return false;
	int mid = (end + begin) / 2;
	//��������ѡ��ѡ����ʵıȽ�����
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
		std::cout <<" ������" <<std::endl;
	}
	int min = (a > b ? b : a);
	//�����н�����ֵ
	num[mid] = num[min];
	num[min] = temp;
	for (int i = 0; i < end; ++i)     
	{
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;
	//һ���������
	quickSort(num, begin, min);
	quickSort(num, min+1, end);
	return true;
}

//��������
bool quickSortII(int *num, int begin, int end)
{
	if (num == NULL || begin >= end)
		return false;
	int mid = (end + begin) / 2;
	//��������ѡ��ѡ����ʵıȽ�����
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
	//�����н�����ֵ
	num[mid] = num[min];
	num[min] = temp;
	for (int i = 0; i < end; ++i)
	{
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;
	//һ���������
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
		std::cout << "����ʧ��";
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
		std::cout << "����ʧ��";
	else
	{
		for (int i = 0; i < n; ++i)
		{
			std::cout << num[i] << " ";
		}
		std::cout << std::endl;
	}*/
	
}