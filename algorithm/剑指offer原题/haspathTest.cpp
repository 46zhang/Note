#include <iostream>

/*
�㷨���ƣ�		�����е�·��
�㷨��Դ��		��ָOffer ������12
�㷨˼�룺		ʹ�û��ݷ�����ʵ�֣���������һ��������ʵ�ֵ��㷨
					(1). ÿ���������������ĸ�ѡ��ֱ��ÿ�����м������ж��Ƿ�����Լ������
					(2). ������ѡ����������һ���裬�ж��Ƿ�����Լ������
					(2). �������Լ����������ʼѡ����һ�ڵ㣬ͬ�����ĸ�ѡ����򷵻�ȥ��һ��
					(3). ��Լ��������������ʱ��ѭ������
				ʹ�õݹ�����ɻ��ݷ��Ƚϼ򵥷���
�㷨ע�⣺		1.�߽���
				2.�ݹ鴫��ʱע�������ѡ�񣬲�Ҫ�ظ���ҪԽ��
�㷨Ч�ʷ���:	1. ʹ���˵ݹ飬�㷨Ч���Ӧ����O(logn)
�㷨ʵ��ʱ��:	��������13һ�����˿�3��Сʱʵ�֣������һ��Сʱ���Ҿ�ʵ����

*/


bool findString(char *matrix, int rows, int cols, int index,char* str,bool * hasCome)
{
	//�߽���
	if (matrix == NULL || rows <= 0 || cols <= 0 || hasCome==NULL||index>=rows*cols)
		return false;
	hasCome[index] = true;
	std::cout << " index ��ֵ: " << index<<std::endl;
	//˵���ַ���ȫ��ƥ����
	if (str==NULL||str[0] == '\0')
		return true;
	bool status = false;
	//��index���������Ҳ����Ƿ�������Լ��������
	
	if (false==status && index - cols >= 0 && matrix[index - cols] == str[0] && hasCome[index - cols] != true)
		status = findString(matrix, rows, cols, index - cols, str + 1, hasCome);
	if (false == status && index + cols < rows*cols && matrix[index+cols] == str[0] && hasCome[index + cols] != true)
		status = findString(matrix, rows, cols, index + cols, str + 1, hasCome);
	if (false == status && (index) % cols != 0 && matrix[index - 1] == str[0] && hasCome[index - 1] != true)
		status = findString(matrix, rows, cols, index - 1, str + 1, hasCome);
	if (false == status && (index + 1) % cols != 0 && matrix[index + 1] == str[0] && hasCome[index + 1] != true)
		status = findString(matrix, rows, cols, index + 1, str + 1, hasCome);
	if (status == false)
	{
		hasCome[index] = false;
		return false;
	}
	
	else
		return status;

}

bool hasPath(char *matrix, int rows, int cols, char* str)
{
	if (matrix == NULL || rows <= 0 || cols <= 0 || str == NULL)
		return false;
	bool * hasCome = new bool[rows*cols];
	bool status = false;
	memset(hasCome, false, rows*cols);
	/*for (int i = 0; i <= rows * cols; ++i)
		hasCome[i] = false;*/
	for (int i = 0; i < rows*cols; ++i)
	{
		if (matrix[i] == str[0])
		{
			/*if (str + 1 != NULL)
				status = findString(matrix, rows, cols, i, str + 1, hasCome);
			else
				return true;
			if (status == true)
				return true;*/
			if (findString(matrix, rows, cols, i, str + 1, hasCome))
				return true;
			
		}
	}
	delete hasCome;
	return status;
}


void hasPathTest()
{
	char m[41] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS",str[30]="SLHECCEIDEJFGGFIE";
	int rows = 5, cols = 8;
	bool s=hasPath(m, rows, cols,str);
	if (true == s)
		std::cout << "����·��" << std::endl;
	else
		std::cout << "������·��" << std::endl;
}