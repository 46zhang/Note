#include <iostream>
/*
�㷨���ƣ�		�����������ĺ����������
�㷨��Դ��		��ָOffer ������33
�㷨˼�룺		�������ĺ���������о���ͨ��ÿ���ж�����������ֵ����������ֵ����ڵ�ıȽϣ��涨������
					����С�ڸ��ڵ㣬������������ڸ��ڵ㣬ͨ�����ݹ�����֤��һ�Ŷ���������

�㷨ע�⣺		1.�߽���
				2.�ݹ鴫��ʱע�������ѡ�񣬲�Ҫ�ظ���ҪԽ��
�㷨Ч�ʷ���:	ʱ�临�Ӷ�O(nlogn)
�㷨ʵ��ʱ��:	�㷨1 ���˰��Сʱʵ���㷨��

*/

bool verifySquenceOfBST(int *num,int length) {
	if (num == NULL||length<=0)
		return false;
	if (length == 1)
		return true;
	int leftIndex = length - 1, root = num[length - 1];

	while (leftIndex >= 0) {
		if (num[leftIndex] < root)
			break;
		--leftIndex;
	}
	
	//�ж��������Ƿ���ڴ��ڸ��ڵ��ֵ
	for (int i = 0;  i <= leftIndex; ++i)
		if (num[i] >= root)
			return false;
	//С��0˵��������������
	if (leftIndex < 0) {
		verifySquenceOfBST(num , length - 1);
	}
	else {
		//˵������������
		if (num[0] < num[length - 1])
			verifySquenceOfBST(num, leftIndex + 1);
		if (length >= 2 && num[length - 2] > num[length - 1])
			verifySquenceOfBST(num + leftIndex, length - 1 - leftIndex);
	}
	
	return true;
	
}


void verifySquenceOfBSTTest() {
	int num[7] = { 13 }, n = 1;
	if (verifySquenceOfBST(num, n))
		std::cout << "�Ƕ����������ĺ����������" << std::endl;
	else
		std::cout << "����" << std::endl;
}