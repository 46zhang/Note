#include<iostream>
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
bool isSymmetrical(BTreeNode *p, BTreeNode *q);
bool isSymmetrical(BTreeNode *head) {
	return isSymmetrical(head, head);
}
bool isSymmetrical(BTreeNode *p, BTreeNode *q) {
	if (p == nullptr&&q == nullptr)
		return true;
	else if (q==nullptr || p==nullptr)
		return false;
	if (q->value != p->value)
		return false;
	return isSymmetrical(p->left, q->right)&&isSymmetrical(p->right,q->left);
}
void isSymmetricalTest() {
	int num[15] = { 8,6,5,leave,leave,7,leave,leave,6,7,leave,leave,5,leave,leave }, n = 15;
	int time = 0;
	
	BTreeNode *head = createTree(num, &time, n);
	BTreeNode *p = head;

	printBTreeFront(head);
	std::cout << std::endl;
	printBTreeMid(head);
	std::cout << std::endl;
	if (true == isSymmetrical(head))
		std::cout << "是对称的" << std::endl;
	else
		std::cout << "不是对称的" << std::endl;
}