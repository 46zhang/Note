#include <iostream>
#include <vector>
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

void findPath(BTreeNode * t, int expSum, std::vector<int> & path, int currSum) {
	if (t == NULL)
		return;
	currSum += t->value;
	path.push_back(t->value);
	bool isLeaf = nullptr == t->left&&nullptr == t->right;
	if (isLeaf&&currSum == expSum) {
		for (auto i = path.begin(); i != path.end(); ++i) {
			std::cout << " " << *i;
		}
	}
	if (t->left)
		findPath(t->left, expSum, path, currSum);
	if (t->right)
		findPath(t->right, expSum, path, currSum);
	path.pop_back();
}

void findPath(BTreeNode *t,int expSum) {
	if (t == NULL)
		return;
	std::vector<int> path;
	int currSum = 0;
	findPath(t, expSum, path, currSum);
}

void findPathTest() {
	int num[11] = { 10,5,4,leave,leave,7,leave,leave,12,leave,leave },n=11,expSum=22;
	int time = 0;
	BTreeNode *tree = createTree(num,&time,n);
	printBTreeMid(tree);
	std::cout << std::endl;
	printBTreeFront(tree);
	std::cout << std::endl;
	findPath(tree, expSum);
}