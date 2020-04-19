#include<iostream>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode *left_ptr;
	BinaryTreeNode *right_ptr;
	BinaryTreeNode *father;
};


/*
创建b树
*/
static BinaryTreeNode *createBinaryTree(int mid[], int m_begin, int m_end, int front[], int f_begin, int f_end)
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
		p->left_ptr = createBinaryTree(mid, m_begin, i, front, f_begin + 1, f_begin + 1 + i - m_begin);
	//开始创建右子树节点，只有在其小于m_end的时候才需要创建
	if (i < m_end)
	{
		p->right_ptr = createBinaryTree(mid, i + 1, m_end, front, f_end - (m_end - i - 1), f_end);
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
static  void printBinaryTreeFront(BinaryTreeNode *t)
{
	if (t == NULL)
		return;
	std::cout << t->m_nValue << "  ";
	printBinaryTreeFront(t->left_ptr);
	printBinaryTreeFront(t->right_ptr);
}
static void printBinaryTreeMid(BinaryTreeNode *t)
{
	if (t == NULL)
		return;
	printBinaryTreeMid(t->left_ptr);
	std::cout << t->m_nValue << "  ";
	printBinaryTreeMid(t->right_ptr);

}
bool hasSubTree() {

}
void hasSubTreeTest() {
	int treeMid[7] = { 9,8,4,2,7,8,7 },midEnd=6;
	int treeFront[7] = { 8,8,9,2,4,7,7 },frontEnd=6;
	BinaryTreeNode *tree = createBinaryTree(treeMid, 0, midEnd, treeFront, 0, frontEnd);
	printBinaryTreeMid(tree);
	std::cout << std::endl;
	printBinaryTreeFront(tree);

}