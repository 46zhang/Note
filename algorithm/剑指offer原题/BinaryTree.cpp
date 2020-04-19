#include<iostream>
#include <vector>

/*
算法名称：		求二叉树的深度以及判断一棵树是否是二叉平衡术
算法来源：		剑指Offer 面试题55
算法思想：		

算法注意：		1.边界检查
				2.循环终止条件
算法效率分析:	算法时间复杂度O(logn)，空间复杂度O(1)

算法实现时间:	花了30min实现算法1，花了30min实现算法2,花了15Min实现算法3

*/

//定义节点类型，定义叶子节点
typedef int nodeType;
const int leave = -255;

struct BinaryTreeNode {
	int value;
	BinaryTreeNode *leftChild;
	BinaryTreeNode *rightChild;
};

//创建二叉树
static BinaryTreeNode *createBinaryTree(std::vector<nodeType>data,int& index) {
	if (data.size()<= 0 || index > data.size()||data[index]==leave)
		return nullptr;
	BinaryTreeNode *root = new BinaryTreeNode();
	root->value = data[index];
	root->leftChild = createBinaryTree(data, ++index);
	root->rightChild = createBinaryTree(data, ++index);
	return root;
}
static void preorderTraval(BinaryTreeNode *root) {
	if (root == NULL)
		return;
	std::cout << " " << root->value;
	preorderTraval(root->leftChild);
	preorderTraval(root->rightChild);
}

static void inorderTraval(BinaryTreeNode *root) {
	if (root == NULL)
		return;
	inorderTraval(root->leftChild);
	std::cout << " " << root->value;
	inorderTraval(root->rightChild);
}

int binaryTreeDepth(BinaryTreeNode *root) {
	int l,r;
	if(root==nullptr)
		return 0;
	r = binaryTreeDepth(root->leftChild) + 1;
	l = binaryTreeDepth(root->rightChild) + 1;
	return r > l ? r : l;
}
bool isBlanced(BinaryTreeNode* root, int &depth) {
	if (root == nullptr) {
		depth = 0;
		return true;
	}
	int left(0), right(0);
	if (isBlanced(root->leftChild, left) && isBlanced(root->rightChild, right)) {
		int distance = left - right;
		depth = left > right ? left : right;
		if (distance <= 1 && distance >= -1)
			return true;

		return false;
	}
	return false;
}

bool isAVLTree(BinaryTreeNode *left, BinaryTreeNode *right) {
	if (left == nullptr)
		return binaryTreeDepth(right) <= 1;
	else if (right == nullptr)
		return binaryTreeDepth(left) <= 1;
	else
	{
		bool l = isAVLTree(left->leftChild, left->rightChild);
		bool r = isAVLTree(right->leftChild, right->rightChild);
		return l&&r;
	}
}
//判断是否是二叉平衡树
bool isAVLTreeTest(BinaryTreeNode *root) {
	if (root == nullptr)
		return false;
	int depth = 0;
	//return isAVLTree(root->leftChild, root->rightChild);
	return isBlanced(root, depth);
}


void binaryTreeDepthTest() {
	std::vector<nodeType>data{ 1,2,4,leave,leave,5,7,leave,leave,leave,3,leave,6,leave,leave };
	//std::vector<nodeType>data{ 1,2,4,5,6,leave,leave,leave,leave,leave,leave };
	int index = 0;
	BinaryTreeNode* root=createBinaryTree(data, index);
	preorderTraval(root);
	std::cout << std::endl;
	inorderTraval(root);
	int depth = binaryTreeDepth(root);
	std::cout <<std::endl<<"深度是： "<< depth<<std::endl;
	if(true==isAVLTreeTest(root))
		std::cout << "是二叉平衡树" << std::endl;
	else
		std::cout << "不是二叉平衡树" << std::endl;
}
