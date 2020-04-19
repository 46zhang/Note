#include <iostream>

struct BTreeNode {
	int value;
	BTreeNode * left;
	BTreeNode *right;
};
#define leave -10000

//通过先序遍历序列来构造二叉树，用-10000表示是叶子节点
static BTreeNode * createTree(int * num, int *time, int n) {
	//std::cout << "time: " << *time << std::endl;
	if (num == nullptr || *time == n) {
		//std::cout << " 返回NULL"<<std::endl;
		return NULL;
	}

	if (num[*time] == leave) {
		++(*time);
		return NULL;
	}
	BTreeNode *root = new BTreeNode();
	root->right = root->right = NULL;
	root->value = num[*time];
	//std::cout << "  " << root->value << "  " << num[*time];
	++(*time);
	root->left = createTree(num, time, n);
	//std::cout << "time: " << *time << std::endl;
	root->right = createTree(num, time, n);
	return root;
}
//先序打印输出
static void printBTreeFront(BTreeNode *t)
{
	if (t == NULL)
		return;
	std::cout << t->value << "  ";
	printBTreeFront(t->left);
	printBTreeFront(t->right);
}

static void printBTreeMid(BTreeNode *t)
{
	if (t == NULL)
		return;
	printBTreeMid(t->left);
	std::cout << t->value << "  ";
	printBTreeMid(t->right);

}

void covertNode(BTreeNode *pNode,BTreeNode ** pLastNodeInList) {
	if (pNode == nullptr)
		return;
	if (pNode->left != nullptr)
		covertNode(pNode->left, pLastNodeInList);
	//如果左子树最大的不为空，则其右边的是pNode
	if (pLastNodeInList != nullptr&&*pLastNodeInList!=nullptr)
		(*pLastNodeInList)->right = pNode;
	//链接一下
	pNode->left = *pLastNodeInList;
	*pLastNodeInList = pNode;
	if (pNode->right != nullptr)
		covertNode(pNode->right, pLastNodeInList);
}

BTreeNode *covert(BTreeNode * root) {
	BTreeNode * head;
	if (root==nullptr)
		return NULL;
	BTreeNode *pLastNodeInList = nullptr;
	covertNode(root, &pLastNodeInList);
	head = pLastNodeInList;
	while (head->left) {
		head = head->left;
	}
	return head;
}

//二叉树的转换
void convertTest() {
	//int num[15] = { 10,6,4,leave,leave,8,leave,leave,14,12,leave,leave,16,leave,leave }, n = 15;
	int num[15] = { 10,leave,14,12,leave,leave,16,leave,leave }, n = 9;
	int time = 0;
	BTreeNode *tree = createTree(num, &time, n);
	printBTreeMid(tree);
	std::cout << std::endl;
	printBTreeFront(tree);
	BTreeNode *p=covert(tree);
	std::cout <<"反转后 "<< std::endl;
	while (p) {
		std::cout << p->value << "  ";
		p = p->right;
	}
}