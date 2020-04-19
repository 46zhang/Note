#include <iostream>

/*
�㷨���ƣ��û��ݷ���������˵��˶���Χ
�㷨��Դ����ָOffer ������13
�㷨˼�룺		�ж��ֽⷨ
				1.ʹ�û��ݷ������ж�
�㷨ע�⣺		1.�߽���
				2.�ݹ鴫��ʱע�������ѡ�񣬲�Ҫ�ظ���ҪԽ��
�㷨Ч�ʷ���:	1. ʹ���˵ݹ飬�㷨Ч���Ӧ����O(logn)
�㷨ʵ��ʱ��:	��������12һ�����˿�3��Сʱʵ�֣�ƽ��Ӧ��һ�����1�����ӣ������д��ʱ�䳤��ԭ��
					���������ж��ѣ����������ҿ����ˣ���������Ŀ������һֱ�޷�ac

*/

bool smallerThanK(int rows, int cols,int index,int k)
{
	int  x = index % cols;
	int y = index / cols;
	
	return (x/10+x%10 + y/10+y%10  <= k);
}
int robotMove(int index,int k,int rows,int cols,bool *visit)
{
	visit[index] = true;
	std::cout << index << " ";
	int result = 0;
	//�������������ƶ�
	if (index - cols >= 0 && !visit[index - cols]&&true == smallerThanK( rows, cols, index - cols, k))
		result += 1+robotMove(index - cols, k, rows, cols, visit);
	if(index + cols < rows*cols && !visit[index + cols] && true==smallerThanK( rows, cols, index + cols, k))
		result += 1 + robotMove(index + cols, k, rows, cols, visit);
	if (index % cols != 0 && !visit[index -1] && true == smallerThanK(rows, cols, index - 1, k))
		result += 1 + robotMove(index - 1,k, rows, cols, visit);
	if ((index + 1) % cols!=0 && !visit[index + 1] && true == smallerThanK(rows,cols,index + 1,k))
		result += 1 + robotMove(index + 1, k, rows, cols, visit);
	return result;
}

int movingCount(int threshold, int rows, int cols)
{
	if (threshold <= 0 || rows <= 0 || cols <= 0)
		return 0;
	bool *visit = new bool[rows*cols];
	memset(visit, false, rows*cols);
	int result = 1;
	visit[0] == true;
	result+= robotMove(0,threshold, rows, cols, visit);
	delete []visit;
	return result;
	
}



int movingCountII(int threshold, int rows, int cols) {
	int m = rows;
	int n = cols;
	int k = threshold;

	if (k > m * n) {
		return m * n;
	}

	if (k >= m) {
		return m * (k - m + 1) + (k + 1 <= n ? (m + 1) * m / 2 : (m + k - n + 2) * (m - k + n - 1) / 2);
	}
	else {
		return k + 1 <= n ? (k + 1) * (k + 2) / 2 : (2 * k - n + 3) * n / 2;
	}
}

void robotMoveTest()
{
	int rows = 10, cols = 10,k=5;
	int cout=movingCount(k, rows, cols);
	int cou1=movingCountII(k, rows, cols);
	std::cout << "����ĸ��Ӹ���Ϊ :"<<cou1 << std::endl;
}