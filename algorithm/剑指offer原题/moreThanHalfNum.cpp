#include<iostream>

//8.30pm begin
/*
�㷨���ƣ�		���ҳ������鳤��һ�������
�㷨��Դ��		��ָOffer ������39
�㷨˼�룺		�ⷨ1.���������ٲ��ң���������ظ����ֳ�������һ������֣���ô�����ź���ʱ��num[n/2]�϶���������Ҫ�ҵ�����
					�����㷨��ʱ�临�Ӷ�O(nlogn),���ԸĽ��������򣬽�ʱ�临�ӶȽ�ΪO(n)�������ص��±���n/2�򷵻ظ�����
					�����ص��±���ڻ���С��n/2������С��Χ�����²���
					1. ����Ƿ�Ϊ�Ϸ�����
					2. ��num[0]Ϊ�ڵ㿪ʼ������������±�jΪn/2������num[j]
					3. ����ʼ����
				�ⷨ2��������һ��ʼ�����뵽�ģ��ù�ϣ���ÿ�����ֵĸ�����Ȼ�󷵻س��ִ�������n/2��
				�ⷨ3����ָOffer�����ᵽ���㷨�����㷨2�ĸĽ���������ֳ���n/2��˵������ִ������
					1.����һ��timeֵ����ʼ��Ϊ0����time=0ʱ�����������ֱ��浽result
					2.���������������result��С��ȣ�time+=1,����time-=1,��timeΪ0,��ת��1
					3. �������յ�result

�㷨ע�⣺		1.������
				2.��βNULLָ�������
�㷨Ч�ʷ���:	�㷨1ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
				�㷨2ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
				�㷨3ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
�㷨ʵ��ʱ��:	����25minСʱʵ���㷨������15mindebug,���Ļ��ǱȽ���Ϥ��

*/

int partition(int *pNum,int begin,int end,int len) {
	if (pNum == NULL ||begin >=end)
		return 0;
	int temp, change = pNum[begin],i=begin,j=end;
	int time = 0;
	while (i < j) {
		while (i<end&&pNum[++i] <= change);
		while (j>begin&pNum[--j] > change);
		if (i >= j  )
			break;
		temp = pNum[i];
		pNum[i] = pNum[j];
		pNum[j] = temp;
		++time;
	}
	temp = pNum[j];
	pNum[j] = pNum[begin];
	pNum[begin] = pNum[j];
	std::cout << "j:  "<<j<<" num[j]: "<<pNum[j] << "    "<<pNum[begin]<< "  "<<time <<std::endl;
	if (len / 2 == j)
		return pNum[j];
	else if (j < len / 2)
		return partition(pNum, j+1, end, len);
	else
		return partition(pNum, begin, j, len);
}

int moreThanHalfNum(int *pNum,int len) {
	if (pNum == nullptr || len <= 0)
		return 0;
	else if (len == 1)
		return pNum[0];
	return partition(pNum, 0, len, len);
}

void moreThanHalfNumTest() {
	//int num[9] = { 1,2,3,2,2,2,5,4,2 }, n = 9;
	int num[11] = { 1,2,3,2,2,2,5,4,2,7,2 }, n = 11;
	int a = moreThanHalfNum(num, n);
	std::cout << a << std::endl;
}