#include<iostream>
#include <vector>

/*
�㷨���ƣ�		�������������Լ��ж�һ�����Ƿ��Ƕ���ƽ����
�㷨��Դ��		��ָOffer ������55
�㷨˼�룺		

�㷨ע�⣺		1.�߽���
				2.ѭ����ֹ����
�㷨Ч�ʷ���:	�㷨ʱ�临�Ӷ�O(logn)���ռ临�Ӷ�O(1)

�㷨ʵ��ʱ��:	����30minʵ���㷨1������30minʵ���㷨2,����15Minʵ���㷨3

*/

//����ڵ����ͣ�����Ҷ�ӽڵ�
typedef int nodeType;
const int leave = -255;

struct BinaryTreeNode {
	int value;
	BinaryTreeNode *leftChild;
	BinaryTreeNode *rightChild;
};

//����������
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
//�ж��Ƿ��Ƕ���ƽ����
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
	std::cout <<std::endl<<"����ǣ� "<< depth<<std::endl;
	if(true==isAVLTreeTest(root))
		std::cout << "�Ƕ���ƽ����" << std::endl;
	else
		std::cout << "���Ƕ���ƽ����" << std::endl;
}
