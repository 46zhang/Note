#include<iostream>
#include <string>

/*
�㷨���ƣ�		1-n�����г���1�ĸ���
�㷨��Դ��		��ָOffer ������43
�㷨˼�룺		�Ƚ�ֱ�ӵ��뷨���Ǳ���1��n��ÿ������Ȼ���ۼ�
				���и����Ľⷨ��Ϊ���ͨ���۲����ֵĹ����ҳ�һЩ�µĽⷨ
					��23456Ϊ���ӣ����������λ��1�ĸ��� Ϊ  10000-19999 ��10000�����������Ϊ123456
					��ô���λ���ֵ�����Ϊ  10000-13456 �� 3457������,�������λ��1�ĸ���Ϊ 
						if ���λ���� >1  ����=pow(10,��λ��-1)��else ����=ʣ�����ִ�С+1
					��������λ�����Ҫ��ʣ�µģ���Ҫ�ҳ� 23456����ʣ��4��λ������1�ĸ��ʣ���23456�ֳ�������
					3456-13455��13456-23456���������ֵ�����ÿλ���ֶ��г���0-9��10�����ֵĿ���,��������Ϲ�ʽ��֪
						����=2(��Ϊ����Ϊ������)*4(����λ��-1)*10^3��ÿλ���ֶ���10�ֿ��ܣ�
					���������ּ���������3456~23456�ĸ���
					Ȼ���ٵݹ���(3456)�ĸ���

�㷨ע�⣺		1.�߽���
				2.�ݹ���ֹ����
�㷨Ч�ʷ���:	�㷨1ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(1)
				�㷨2ʱ�临�Ӷ�O(logn)���ռ临�Ӷ�O(1)
�㷨ʵ��ʱ��:	����1��Сʱ20min˼��ʵ���㷨��ǰ�ڵĹ�˼���˺ܶ�ʱ�䣬����д�����ʱ��һ�����û��bug

*/

int numOfOne(int n) {
	if (n <= 0)
		return 0;
	else if (n < 10)
		return 1;
	std::string numStr = std::to_string(n);
	int len = numStr.size(), time = 0;
	std::string nextStr(numStr.substr(1, len));
	int nextNum = 0;
	//�������Ϊ1���ֵĸ���
	nextNum=stoi(nextStr);
	nextStr = numStr.substr(1, len);
	std::cout << numStr <<"  "<< nextStr<<std::endl;
	if (numStr[0] > '1')
		time = pow(10, len - 1);
	else  
		time += nextNum+1;
	int high = numStr[0] - '0';
	std::cout << "���������λtime:" << time<<std::endl;
	time += high * (len - 1)*pow(10, len - 2);
	std::cout << "������ʣ��nλtime:" << time << std::endl;
	time += numOfOne(nextNum);
	std::cout << "������ʣ��һ������time:" << time << std::endl;
	return time;
	
		
}

void numOfOneTest() {
	int n = 10;
	int a = (numOfOne(n));
}