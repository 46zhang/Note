#include <iostream>
/*
�㷨���ƣ�		���������ֵ
�㷨��Դ��		��ָOffer ������47
�㷨˼�룺		һ��ʼ�뵽�ľ����û��ݷ������ǵݹ���ڴ������ظ�����
				���ö�̬�滮�ķ������ܶ�

�㷨ע�⣺		1.�߽���
				2.�ݹ���ֹ����
�㷨Ч�ʷ���:	�㷨1ʱ�临�Ӷ� 0(nm*nm)
				�㷨2ʱ�临�Ӷ�O(nm)
�㷨ʵ��ʱ��:	����20minʵ���㷨2,����17minʵ���㷨2

*/

int maxValue(int *matrix,int n,int m) {
	if (matrix == nullptr || m <= 0 || n <= 0)
		return 0;
	int * value = new int[n*m];
	value[0] = matrix[0];
	for (int i = 1; i < n*m; ++i) {
		//��һ���޷������һ�е�����
		if (i < m) 
			value[i] = matrix[i]+value[i-1];
		else {
			if (i%m != 0 && matrix[i] + value[i - 1] > matrix[i] + value[i - m])
				value[i] = matrix[i] + value[i - 1];
			else
				value[i] = matrix[i] + value[i - m];

		}
		std::cout << "i: " << i <<"  vaule: "<< value[i] << "  ";
		if (i%m == 1)
			std::cout << std::endl;
	}
	return value[n*m - 1];
}
int maxVauleSolution2(int *matrix, int n, int m,int index) {
	if (matrix == nullptr || m <= 0 || n <= 0||index>=n*m||index<0)
		return 0;
	int value = matrix[index],left=0,down=0;
	//����
	if ((index+1)%m != 0)
		left = maxVauleSolution2(matrix, n, m, index + 1);
	if (index < n*m)
		down = maxVauleSolution2(matrix, n, m, index + m);
	if (down > left)
		value += down;
	else
		value += left;
	return value;
}
void maxValueTest() {
	int num[16] = { 1,10,3,8,12,2,9,6,5,7,4,11,3,7,16,5 }, n = 4, m = 4;
	//int num[4] = { 1,10,3,8 }, n = 1, m = 4;
	//int num[1], n = 0, m = 0;
	//int a = maxValue(num,n,m);
	int b=maxVauleSolution2(num, n, m,0);
	//std::cout << "���ֵ�� " << a<< std::endl;
	std::cout << "���ֵ�� " << b << std::endl;
}