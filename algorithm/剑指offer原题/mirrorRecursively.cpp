#include<iostream>
#include <deque>
struct BTreeNode {
	int value;
	BTreeNode * left;
	BTreeNode *right;
};
#define leave -10000

//通过先序遍历序列来构造二叉树，用-10000表示是叶子节点
static BTreeNode * createTree(int * num,int *time,int n ) {
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
	root->left = createTree(num,time,n);
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
static void printBTreeFromTopToBottom(BTreeNode *t) {
	std::deque<BTreeNode *>treeQueue;
	if (t == NULL)
		return;
	int toBePrint = 1, nextLevel = 0;
	treeQueue.push_back(t);
	while (!treeQueue.empty()) {
		auto a=treeQueue.front();
		treeQueue.pop_front();
		std::cout << a->value << "  ";
		--toBePrint;
		if (a->left)
		{
			treeQueue.push_back(a->left);
			++nextLevel;
		}
		if (a->right)
		{
			treeQueue.push_back(a->right);
			++nextLevel;
		}
		if (toBePrint == 0)
		{
			std::cout << std::endl;
			toBePrint = nextLevel;
		}
	}
}
static void printBTreeMid(BTreeNode *t)
{
	if (t == NULL)
		return;
	printBTreeMid(t->left);
	std::cout << t->value << "  ";
	printBTreeMid(t->right);

}
BTreeNode * mirrorRecursively(BTreeNode *head) {
	if (head == NULL)
		return NULL;
	BTreeNode *temp;
	temp = head->left;
	head->left = head->right;
	head->right = temp;
	mirrorRecursively(head->left);
	mirrorRecursively(head->right);
	return head;
}


void mirrorRecursivelyTest() {
	int num[15] = { 8,6,5,leave,leave,7,leave,leave,10,9,leave,leave,11,leave,leave }, n = 15;
	int time=0;
	int num1[1] = { leave };
	BTreeNode *head=createTree(num,&time,n);
	BTreeNode *p = head;
	
	printBTreeFront(head);
	std::cout << std::endl;
	printBTreeMid(head);
	std::cout << std::endl;
	printBTreeFromTopToBottom(head);
	/*
	mirrorRecursively(head);
	std::cout << std::endl;
	printBTreeFront(head);
	std::cout << std::endl;
	printBTreeMid(head);
	*/

}