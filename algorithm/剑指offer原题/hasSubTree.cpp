#include<iostream>

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode *left_ptr;
	BinaryTreeNode *right_ptr;
	BinaryTreeNode *father;
};


/*
����b��
*/
static BinaryTreeNode *createBinaryTree(int mid[], int m_begin, int m_end, int front[], int f_begin, int f_end)
{
	if (m_begin == m_end || f_begin == f_end)
		return NULL;
	//���ҵ��м�ڵ�
	//ǰ������õ��ĵ�һ�������м�ڵ�
	BinaryTreeNode * p = new BinaryTreeNode();
	p->m_nValue = front[f_begin];
	int i = m_begin;
	//�ҵ�����������м�ڵ㣬�������Ϊ�������ڵ㣬�����ұ�Ϊ�������ڵ�
	while (i < m_end)
	{
		if (mid[i] == front[f_begin])
			break;
		++i;
	}
	//��������������м�ڵ���ͬһλ�ã�˵��û��������
	//�����ڲ�ͬλ�òſ�ʼ����ߵ��ӽڵ�
	if (i != m_begin)
		p->left_ptr = createBinaryTree(mid, m_begin, i, front, f_begin + 1, f_begin + 1 + i - m_begin);
	//��ʼ�����������ڵ㣬ֻ������С��m_end��ʱ�����Ҫ����
	if (i < m_end)
	{
		p->right_ptr = createBinaryTree(mid, i + 1, m_end, front, f_end - (m_end - i - 1), f_end);
	}
	//ָ�򸸽ڵ�
	if (p->left_ptr != NULL)
		p->left_ptr->father = p;
	if (p->right_ptr != NULL)
		p->right_ptr->father = p;
	p->father = NULL;
	return p;

}
//�����ӡ���
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