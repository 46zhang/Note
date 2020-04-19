#include <iostream>



/*
�㷨���ݣ�		�ڳ���Ϊn���ҵ������ҵ���һ���ظ�������(���ַ�Χ0~n-1)
�㷨��Դ��		��ָOffer������3
�㷨˼�룺		�ж��ֽⷨ
				1.����������:��,�����㷨ʱ�临�Ӷ�Ϊ(nlogn)
				2.��ϣ��;�죬ռ�ڴ棬�ռ临�Ӷ�Ϊ(n)
				3.ʹ�ý����жϷ�������������ظ��Ļ�����ô����i���ڵ�λ���Ƕ�Ӧ�±�i��ָ�Ŀռ�
					���Խ���ÿ�����֣����䴦�ڶ�Ӧ��λ�ã������ظ����֣����������轻���Ŀռ�
					�������Լ�ֵ��ȵ�����
				4.������ֲ��ҵ�˼�룬����������ظ������֣�����n=8,��m=n/2=4����ô0~3Ӧ�ó���4�Σ�4~8Ӧ�ó���4��
�㷨ע�⣺		1.������ַ�Χ����Ч��
				2.�ж������Ƿ�ά��
�㷨Ч�ʷ���:	ÿ���������ֻ��Ҫ�������ξ����ҵ��Լ���λ�ã�����ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�O(1)
�㷨ʵ��ʱ��:	�㷨3 ����39min
				�㷨4�����ϵ�ʵ������Ϊ�������⣬������0�����߽�strat��Ϊ0ʱ��������
				�Լ����õݹ�ʵ���㷨4���˿�90min,�ݹ���ĺܿӣ���ʽ�����൱�����㣬�ҷ���

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
			std::cout << "���ַ�Χ����" << std::endl;
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
		//����������ظ��Ļ������ź���ʱ���±�i��Ӧ����arr[i]��ֵ
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
					//����
					int temp = arr[i];
					arr[i] = arr[arr[i]];
					arr[temp] = temp;
					std::cout << " i��ֵ "<<i<< " j��ֵ" << j<<std::endl;
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
	//˵�� 0-mid���ظ�����
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

//�ö��ֲ��ҵ�˼����ʵ���ҵ��ظ�����
bool findReaptedNumByBinaryFine(int arr[], int n, int *num)
{
	if (arr == NULL || n <= 0)
		return false;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i]<0 || arr[i]>n)
		{
			std::cout << "���ַ�Χ����" << std::endl;
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
		std::cout << " �ظ��������� " << num << std::endl;
	}
	else {
		std::cout << " ���ִ������  " << "\n";
	}*/
	//num=getDuplication(arr,n);
	//std::cout << " �ظ��������� " << num << std::endl;
	
	if (true == findReaptedNumByBinaryFine(arr, n, &num))
	{
		std::cout << " �ظ��������� " << num << std::endl;
	}
	else {
		std::cout << " ���ִ������  " << "\n";
	}

}