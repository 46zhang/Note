#include <iostream>

/*

�㷨���ƣ�		����
�㷨��Դ��		��ָOffer ������49
�㷨˼�룺		�ÿռ任ʱ�䣬��Ϊ��ֻ�ܱ�2��3��53�������������������г��������������ı����������������г˾���

�㷨ע�⣺		1.�߽���
				2.�ݹ���ֹ����
�㷨Ч�ʷ���:	�㷨1ʱ�临�Ӷ�O(n)
�㷨ʵ��ʱ��:	����20minʵ���㷨��ǰ�ڵĹ�˼���˺ܶ�ʱ�䣬����д�����ʱ��һ�����û��bug

*/
int min(int num2, int num3, int num5) {
	int min = num2 < num3 ? num2 : num3;
	min = min < num5 ? min : num5;
	return min;
}
int uglyNumber(int index) {
	int *num = new int[index];
	num[0] = 1;
	int *numMutil2 = num, *numMutil3 = num, *numMutil5 = num, i = 1;
	while (i < index) {
		num[i] = min(*numMutil2 * 2, *numMutil3 * 3, *numMutil5 * 5);
		while (*numMutil2 * 2 <= num[i])
			++numMutil2;
		while (*numMutil3 * 3 <= num[i])
			++numMutil3;
		while (*numMutil5 * 5 <= num[i])
			++numMutil5;
		std::cout << "i��" << i << " num[i]: " << num[i]<<std::endl;
		++i;
	}
	int result = num[i - 1];
	delete[] num;
	return result;

}
void uglyNumberTest() {
	int i = 1500;
	int a=uglyNumber(i);
	std::cout << "�� " << i << " ��������: " << a << std::endl;
}