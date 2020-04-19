#include <iostream>
/*
算法名称：		二叉搜索树的后序遍历序列
算法来源：		剑指Offer 面试题33
算法思想：		二叉树的后序遍历序列就是通过每次判断其左子树的值与右子树的值与根节点的比较，规定左子树
					必须小于根节点，右子树必须大于根节点，通过层层递归来保证是一颗二叉搜索树

算法注意：		1.边界检查
				2.递归传递时注意参数的选择，不要重复不要越界
算法效率分析:	时间复杂度O(nlogn)
算法实现时间:	算法1 花了半个小时实现算法，

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
	
	//判断左子树是否存在大于根节点的值
	for (int i = 0;  i <= leftIndex; ++i)
		if (num[i] >= root)
			return false;
	//小于0说明不存在右子树
	if (leftIndex < 0) {
		verifySquenceOfBST(num , length - 1);
	}
	else {
		//说明存在左子树
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
		std::cout << "是二叉搜索树的后序遍历序列" << std::endl;
	else
		std::cout << "不是" << std::endl;
}