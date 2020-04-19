#include <iostream>

int const leave = -100000;
struct BinarySearchTreeNode {
	int value;
	BinarySearchTreeNode * left;
	BinarySearchTreeNode * right;
};

//先序打印输出
static void printBTreeFront(BinarySearchTreeNode *t)
{
	if (t == NULL)
		return;
	std::cout << t->value << "  ";
	printBTreeFront(t->left);
	printBTreeFront(t->right);
}

static void printBTreeMid(BinarySearchTreeNode *t)
{
	if (t == NULL)
		return;
	printBTreeMid(t->left);
	std::cout << t->value << "  ";
	printBTreeMid(t->right);

}

static BinarySearchTreeNode* createTree(int *num,int &len,int &index) {
	if (num == NULL || len <= 0||num[index]==leave)
		return nullptr;
	BinarySearchTreeNode * root = new BinarySearchTreeNode();
	root->left = root->right = nullptr;
	root->value = num[index];
	std::cout << root->value << std::endl;
	root->left = createTree(num, len, ++index);
	root->right = createTree(num, len, ++index);
	return root;
} 

BinarySearchTreeNode * kThNodeInBinarySearchTree(BinarySearchTreeNode *root,int& k) {
	if (root == nullptr)
		return nullptr;
	BinarySearchTreeNode *target=nullptr,*left,*right;
	if (root->left) {
		target = kThNodeInBinarySearchTree(root->left, k);
	}
	if (--k == 0)
		target= root;
	if (root->right&&target==nullptr) {
		target =kThNodeInBinarySearchTree(root->right, k);
	}
	return target;
}

void kThNodeInBinarySearchTreeTest() {
	int num[15] = { 5,3,2,leave,leave,4,leave,leave,7,6,leave,leave,8,leave,leave },n=15;
	int index = 0;
	BinarySearchTreeNode *  root = createTree(num,n,index);
	printBTreeFront(root);
	std::cout << std::endl;
	printBTreeMid(root);
	std::cout << std::endl;
	int k = 1;
	BinarySearchTreeNode * result=kThNodeInBinarySearchTree(root, k);
	if (result)
		std::cout << "结果是: " << result->value << std::endl;
	else
		std::cout << "找不到" << std::endl;
}