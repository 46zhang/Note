#include <iostream>


/*
算法名称：通过中序遍历跟先序遍历产生得到的数组去构造二叉树
算法来源：剑指Offer 面试题7
算法思想：		有多种解法
				1.使用递归构造法，通过观察中序数组跟先序数组，发现每个先序数组的第一个值就是子树的根节点，由于不存在重复的值
					所以找到该值在中序数组中的位置x，中序数组中值在x左边为左子树，在右边的为右子树
					算法步骤：
					(1). 先取出前序数组的一个值
					(2). 找出中序数组的该值的位置x
					(3). 以该值创建节点，为该子树的根节点
					(4). 判断x左边是否有值,有的话，进行递归构造左子树
					(5). 判断x右边是否有值,有的话，进行递归构造右子树
				
算法注意：		1.边界检查
				2.递归传递时注意参数的选择，不要重复不要越界
算法效率分析:	1.最坏情况下，需要查找n列，二分查找时间复杂度为O(logn),所以最坏的时间复杂度O(nlogn),空间复杂度O(1)
				2.时间复杂度O(n),最多比较n个右上角的元素就可以找到是否存在重复的数字了
算法实现时间:	算法1 花了半个小时实现算法，花了1个小时debug，太坑了，我在遍历输出时把函数调用使用错了，导致我一直觉得不对，
					进行了一系列的修改，白白浪费了好多时间
				
*/

static struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode *left_ptr;
	BinaryTreeNode *right_ptr;
	BinaryTreeNode *father;
};



BinaryTreeNode *createBinaryTree(int mid[],int m_begin,int m_end,int front[],int f_begin,int f_end)
{
	if (m_begin == m_end || f_begin == f_end)
		return NULL;
	//先找到中间节点
	//前序遍历得到的第一个就是中间节点
	BinaryTreeNode * p = new BinaryTreeNode();
	p->m_nValue = front[f_begin];
	int i = m_begin;
	//找到中序遍历的中间节点，在其左边为左子树节点，在其右边为右子树节点
	while (i < m_end)
	{
		if (mid[i] == front[f_begin])
			break;
		++i;
	}
	//如果中序跟先序的中间节点在同一位置，说明没有左子树
	//所以在不同位置才开始找左边的子节点
	if (i != m_begin)
		p->left_ptr = createBinaryTree(mid, m_begin, i, front, f_begin + 1, f_begin+1+i-m_begin);
	//开始创建右子树节点，只有在其小于m_end的时候才需要创建
	if (i < m_end)
	{
		p->right_ptr = createBinaryTree(mid, i+1, m_end, front, f_end-(m_end-i-1), f_end);
	}
	//指向父节点
	if (p->left_ptr != NULL)
		p->left_ptr->father = p;
	if (p->right_ptr != NULL)
		p->right_ptr->father = p;
	p->father = NULL;
	return p;

}
//先序打印输出
void printBinaryTreeFront(BinaryTreeNode *t)
{
	if (t == NULL)
		return;
	std::cout << t->m_nValue<<"  ";
	printBinaryTreeFront(t->left_ptr);
	printBinaryTreeFront(t->right_ptr);
}
void printBinaryTreeMid(BinaryTreeNode *t)
{
	if (t == NULL)
		return;
	printBinaryTreeMid(t->left_ptr);
	std::cout << t->m_nValue << "  ";
	printBinaryTreeMid(t->right_ptr);
	
}
//按照中序遍历的顺序找出下一节点
BinaryTreeNode* findNextNodeInTree(BinaryTreeNode *node)
{
	BinaryTreeNode * p = node->father;
	if (node == NULL)
		return nullptr;
	if (p&&p->right_ptr != node&&node->left_ptr)
		return node->left_ptr;
	else if (p&&p->right_ptr!=node&&node->right_ptr)
		return node->right_ptr;
	else
	{
		BinaryTreeNode * p = node->father;
		
		if (p->left_ptr == node)
				return p;

	}
	return nullptr;
}
void createBinaryTreeTest()
{
	
	BinaryTreeNode *T;
	int front[8] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int mid[8] = { 4,7,2,1,5,3,8,6 };
	
	
	/*
	int front[8] = { 3, 5, 6, 8 };
	int mid[8] = { 5,3,8,6 };
	*/
	
	T=createBinaryTree(mid, 0, 8, front, 0, 8);
	//printBinaryTreeFront(T);
	std::cout << std::endl;
	printBinaryTreeMid(T);
	//BinaryTreeNode *a = T->right_ptr->right_ptr;
	BinaryTreeNode *a = T->left_ptr->left_ptr;
	BinaryTreeNode * t=findNextNodeInTree(a);
	if (t == nullptr)
		std::cout << "该节点最后一个输出";
	else
		std::cout <<"  "<< a->m_nValue<< " 中序遍历的下一位是 ："<<t->m_nValue;
}