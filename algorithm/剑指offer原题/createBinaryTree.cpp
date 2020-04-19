#include <iostream>


/*
�㷨���ƣ�ͨ�����������������������õ�������ȥ���������
�㷨��Դ����ָOffer ������7
�㷨˼�룺		�ж��ֽⷨ
				1.ʹ�õݹ鹹�취��ͨ���۲�����������������飬����ÿ����������ĵ�һ��ֵ���������ĸ��ڵ㣬���ڲ������ظ���ֵ
					�����ҵ���ֵ�����������е�λ��x������������ֵ��x���Ϊ�����������ұߵ�Ϊ������
					�㷨���裺
					(1). ��ȡ��ǰ�������һ��ֵ
					(2). �ҳ���������ĸ�ֵ��λ��x
					(3). �Ը�ֵ�����ڵ㣬Ϊ�������ĸ��ڵ�
					(4). �ж�x����Ƿ���ֵ,�еĻ������еݹ鹹��������
					(5). �ж�x�ұ��Ƿ���ֵ,�еĻ������еݹ鹹��������
				
�㷨ע�⣺		1.�߽���
				2.�ݹ鴫��ʱע�������ѡ�񣬲�Ҫ�ظ���ҪԽ��
�㷨Ч�ʷ���:	1.�����£���Ҫ����n�У����ֲ���ʱ�临�Ӷ�ΪO(logn),�������ʱ�临�Ӷ�O(nlogn),�ռ临�Ӷ�O(1)
				2.ʱ�临�Ӷ�O(n),���Ƚ�n�����Ͻǵ�Ԫ�ؾͿ����ҵ��Ƿ�����ظ���������
�㷨ʵ��ʱ��:	�㷨1 ���˰��Сʱʵ���㷨������1��Сʱdebug��̫���ˣ����ڱ������ʱ�Ѻ�������ʹ�ô��ˣ�������һֱ���ò��ԣ�
					������һϵ�е��޸ģ��װ��˷��˺ö�ʱ��
				
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
		p->left_ptr = createBinaryTree(mid, m_begin, i, front, f_begin + 1, f_begin+1+i-m_begin);
	//��ʼ�����������ڵ㣬ֻ������С��m_end��ʱ�����Ҫ����
	if (i < m_end)
	{
		p->right_ptr = createBinaryTree(mid, i+1, m_end, front, f_end-(m_end-i-1), f_end);
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
//�������������˳���ҳ���һ�ڵ�
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
		std::cout << "�ýڵ����һ�����";
	else
		std::cout <<"  "<< a->m_nValue<< " �����������һλ�� ��"<<t->m_nValue;
}