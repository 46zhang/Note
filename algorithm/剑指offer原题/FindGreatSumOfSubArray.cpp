#include <iostream>

/*
�㷨���ƣ�		��������������ֵ
�㷨��Դ��		��ָOffer ������42
�㷨˼�룺		3�ֽⷨ
				1. ֱ������������O(n*n)��ʱ�临�Ӷ�
				2. �۲�������ص㣬�������֮��С��ԭ��������ʱ��˵����ǰ�涼�Ǹ�����ֱ�Ӷ���ǰ���������ĺ�
					�������num[i]С��ԭ���������ֵʱ���ȱ����¸�ֵ��Ȼ���ټ������
				3. ʹ�ö�̬�滮��sum[i]��ʾ�±�Ϊi�����������ĺͣ���sum[i-1]<0ʱ��sum[i]=num[i]
					��sum[i-1]>0ʱ��sum[i]=sum[i-1]+sum[i]
�㷨ע�⣺		1.�߽���
				2.��βNULLָ�������
�㷨Ч�ʷ���:	1. ʱ�临�Ӷ�O(n*n)���ռ临�Ӷ�O(1)
				2. ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
				3. ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)		
�㷨ʵ��ʱ��:	���˰��Сʱʵ���㷨1
				���˰��Сʱʵ���㷨2
				����20minʵ���㷨3

*/


//����ϵ����������⣬���������ǲ�������
int findGreatSumOfSubArrayError(int *pNum,int len,int index,int *result,int *max) {
	if (pNum == NULL || len <= 0||index>=len)
		return 0;
	for (int i = index; i < len; ++i) {
		std::cout <<  "��֮ǰ result: " << *result << std::endl;
		*result = *result + pNum[i];
		std::cout << " index: " << index << " i " << i << " pnum[i] " << pNum[i] << " result: " << *result << std::endl;
		if (*result > *max)
			*max = *result;
		findGreatSumOfSubArrayError(pNum, len, i + 1, result, max);
		*result =*result- pNum[i];
		std::cout << " index: " << index << " i " << i << " pnum[i] " << pNum[i] << " result: " << *result << std::endl;
	}
	return *max;
}

//�ö�̬�滮��˼��ʵ��
int findGreatSumOfSubArrayII(int *pNum, int len) {
	if (pNum == nullptr || len <= 0)
		return 0;
	int *sum = new int[len],result=0;
	sum[0] = pNum[0];
	for (int i = 1; i < len; ++i) {
		if (sum[i - 1] < 0)
			sum[i] = pNum[i];
		else
			sum[i] = sum[i-1]+pNum[i];
		if (sum[i] > result)
			result = sum[i];
	}
	
	delete[] sum;
	return result;
}


int findGreatSumOfSubArray(int *pNum,int len) {
	if (pNum == nullptr || len <= 0)
		return 0;
	int temp = 0, result = 0;
	for (int i = 0; i < len; ++i) {
		if (pNum[i] + temp < pNum[i])
			temp = pNum[i];
		else if (pNum[i] + temp < temp) {
			if (result < temp)
				result = temp;
			temp += pNum[i];
		}
		else
			temp += pNum[i];
	}
	if (result < temp)
		result = temp;
	return result;
}
void findGreatSumOfSubArrayTest() {
	int num[8] = { 1,-2,3,10,-4,7,2,-5 }, n = 8;
	//int num[4] = { 1,-4,7,-2}, n = 4;
	int result = 0,max=0;
	//int a = findGreatSumOfSubArrayError(num,n,0,&result,&max);
	//int a = findGreatSumOfSubArray(num, n);
	int a = findGreatSumOfSubArrayII(num, n);
	std::cout << a << std::endl;
}