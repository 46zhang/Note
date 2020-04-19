#include <iostream>

/*
算法名称：		矩阵中的路径
算法来源：		剑指Offer 面试题12
算法思想：		使用回溯法进行实现，适用于由一个个步骤实现的算法
					(1). 每个都有上下左右四个选项，分别对每个进行检索，判断是否满足约束条件
					(2). 例如先选择了向下这一步骤，判断是否满足约束条件
					(2). 如果满足约束条件，开始选择下一节点，同样有四个选项，否则返回去上一层
					(3). 当约束条件不再满足时，循环结束
				使用递归来完成回溯法比较简单方便
算法注意：		1.边界检查
				2.递归传递时注意参数的选择，不要重复不要越界
算法效率分析:	1. 使用了递归，算法效率最坏应该是O(logn)
算法实现时间:	与面试题13一共花了快3个小时实现，大概是一个小时左右就实现了

*/


bool findString(char *matrix, int rows, int cols, int index,char* str,bool * hasCome)
{
	//边界检测
	if (matrix == NULL || rows <= 0 || cols <= 0 || hasCome==NULL||index>=rows*cols)
		return false;
	hasCome[index] = true;
	std::cout << " index 的值: " << index<<std::endl;
	//说明字符串全都匹配了
	if (str==NULL||str[0] == '\0')
		return true;
	bool status = false;
	//在index的上下左右查找是否有满足约束条件的
	
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
		std::cout << "存在路径" << std::endl;
	else
		std::cout << "不存在路径" << std::endl;
}