#include <iostream>
#include <vector>
/*
�㷨���ƣ�		��ΪS������
�㷨��Դ��		��ָOffer ������57
�㷨˼�룺		�����㷨��
				1: ��Ϊs����������
					�����ǵ������У����Կ���ͨ������ָ������ɣ�һ��ͷָ��һ��βָ�롣����֮�ʹ���s����ݼ�βָ��
					����֮��С��S�����ͷָ��
				2: ��Ϊs�������������У�
					���֮�ͱ����������ģ����Թ۲쵽�������ص�
						(1). ��ӵ�������������
						(2). ������ӵ����ֲ��ᳬ��(num+1)/2Ҳ����˵ 7�����ӵ�����4�Ϳ����ж��Ƿ������
					��1�ⷨ���ƣ�������ָ�뷨ȥ����һ��ʼһǰһ���ۼӺͣ��������ʱ������±�û���� (num+1)/2
						�������βָ���������ʱ�ʹ���s������ͷָ�룬ֱ��ͷβָ���ཻ�����Ǵ���ĳ��ָ���±�Խ��(num+1)/2
					�ڶ���һ��ʼ���ö�̬�滮���ߵݹ����������Ƿ�����Ҫ���������ģ����Ժ��ѣ�����˵  9=f(5)+f(4)
						Ȼ�������f(5)��������У�������������ȡ����Ϊ��һ����2��3�������������Ҿ�����2��3Ҳ�޷���֤��4����
						����f(15)=f(7)+f(8),��ͺ���ȥ�ж�f(7)�ݹ�ĵõ�����ϸ�f(8)�õ�����������

�㷨ע�⣺		1.ץס�����������������ؼ���
				2.�߽���
�㷨Ч�ʷ���:	�㷨1ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
				�㷨2ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
�㷨ʵ��ʱ��:	����1��Сʱʵ���㷨1��2

*/

bool twoNumSum(std::vector<int> data,int &num1,int &num2,int s) {
	if (data.size() <= 0)
		return false;
	for (int i = 0, j = data.size() - 1; i < j; ) {
		if (data[i] + data[j] == s) {
			num1 = data[i];
			num2 = data[j];
			return true;
		}
		else if (data[i] + data[j] > s)
			--j;
		else
			++i;
	}
	return false;
}

void twoNumSumisSTest() {
	std::vector<int> num{ 1,2,4,7,11,15 };
	int num1, num2,s=30;
	if (twoNumSum(num, num1, num2, s)) {
		std::cout << "��һ������" << num1 << "�ڶ�����: " << num2 << std::endl;
	}
	else
		std::cout << "�Ҳ���������������" << std::endl;
}

void continueNumSumIsSTest(int s) {
	if (s < 3 )
		return;
	int *num = new int[(s+1)/2+1];
	for (int i = 0; i < (s + 1) / 2 + 1; ++i)
		num[i] = i;
	int tempSum = num[1];
	for (int i = 1, j = 2; i < (s + 1) / 2 + 1&& i < (s + 1) / 2 + 1;) {
		if (tempSum + num[j] < s) {
			tempSum += num[j];
			j++;
		}
		else if (tempSum + num[j] == s) {
			tempSum += num[j];
			std::cout << i << " ~ " << j << std::endl;
			++j;
		}
		else {
			if (i < j) {
				tempSum -= num[i];
				++i;
			}
			else
				break;
		}
	}
}

void sumIsSTest() {
	//twoNumSumisSTest();
	continueNumSumIsSTest(4);
}