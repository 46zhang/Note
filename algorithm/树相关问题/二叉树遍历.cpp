#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
const int leave = -255;
template
<typename T>
static TreeNode * createTree(const vector<T> & num,int &index)
{
	if (num.size() == index || num[index] == leave)
	{
		++index;
		return NULL;
	}
	TreeNode * root = new TreeNode(num[index++]);
	root->left = createTree(num, index);
	root->right = createTree(num, index);
	return root;
}

void travalTreeInOrder(TreeNode *root) {
	if (root == NULL)
		return;
	travalTreeInOrder(root->left);
	cout << root->val << "  ";
	travalTreeInOrder(root->right);
}

/*void travalTreeInOrderByMorris(TreeNode *root) {
	TreeNode *cur(root), *mostRight(NULL);
	while (cur) {
		mostRight = cur->left;
		if (mostRight) {
			while(mostRight->right!=NULL&&mostRight->right!=cur)
				mostRight = mostRight->right;
			if (mostRight->right == NULL)
			{
				mostRight->right = cur;
				cur = cur->left;
				continue;
			}
			else {
				mostRight->right = NULL;
				//第二次访问到有左子树的节点
				cout <<cur->val << "  ";
				cur = cur->right;
			}
		}
		else {
			cout <<cur->val<<"  ";
			cur = cur->right;
		}
	}
}*/
void travalTreeInOrderByMorris(TreeNode *root) {
	if (root == NULL)
		return;
	TreeNode *mostRight, *cur(root);
	while (cur) {
		if (cur->left) {
			mostRight = cur->left;
			while (mostRight->right!=NULL && mostRight->right!=cur)
				mostRight = mostRight->right;
			if (mostRight->right==NULL) {
				mostRight->right = cur;
				cur = cur->left;
			}
			else if(mostRight->right==cur) {
				mostRight->right = NULL;
				cout << cur->val << "  ";
				cur = cur->right;
			}
		}
		else {
			cout << cur->val << "  ";
			cur = cur->right;
		}
	}
}

void travalTreePreOrder(TreeNode *root) {
	if (root == NULL)
		return;
	cout << root->val << "  ";
	travalTreePreOrder(root->left);
	travalTreePreOrder(root->right);

}

void travalTreePreOrderByMorris(TreeNode * root) {
	if (root == NULL)
		return;
	TreeNode *cur(root), *mostRight(NULL);
	while (cur) {
		mostRight = cur->left;
		if (mostRight) {
			while (mostRight->right != NULL && mostRight->right != cur)
				mostRight = mostRight->right;
			if (mostRight->right == NULL)
			{
				//cout << "most right: " << mostRight->val<<"  cur: "<<cur->val << endl;
				mostRight->right = cur;
				cout << cur->val << "  ";
				cur = cur->left;
				
				continue;
			}
			else {
				mostRight->right = NULL;
				cur = cur->right;
			}
		}
		else {
			cout << cur->val<<"  ";
			cur = cur->right;
		}
	}
}

TreeNode* reverse(TreeNode *root) {
	if (!root)
		return NULL;
	TreeNode *p(root->right), *pnext, *q(root), *qnext(root);
	q->right = NULL;
	while (p) {
		pnext = p->right;
		p->right = qnext;
		qnext = p;
		p = pnext;
	}
	return qnext;
}

void printEdge(TreeNode *root) {
	TreeNode *p = reverse(root),*q(p);
	while (p) {
		cout << p->val<<"  ";
		p = p->right;
	}
	reverse(q);
}

void travalBakcOrdrMorris(TreeNode *root) {
	if (root == NULL)
		return;
	TreeNode *cur(root), *mostRight(NULL);
	while (cur) {
		mostRight = cur->left;
		if (mostRight) {
			while (mostRight->right != cur && mostRight->right != NULL)
				mostRight = mostRight->right;
			if (mostRight->right == NULL)
			{
				mostRight->right = cur;
				cur = cur->left;
				continue;
			}
			else {
				//cout << " mostRight: " << mostRight->val << " cur: " << cur->val << endl;
				mostRight->right = NULL;
				printEdge(cur->left);
				cur = cur->right;
			}
		}
		else {
			cur = cur->right;
		}
	}
	printEdge(root);
}

void travalBakcOrdrByStack(TreeNode *root) {
	stack<TreeNode*> s;
	TreeNode *cur = root, *pre = NULL;
	s.push(root);
	while (!s.empty()) {
		cur = s.top();
		//判断上一个节点是不是cur的左孩子或者是右孩子
		//如果不是，则入栈
		if (cur->left!=NULL && cur->left != pre && cur->right!=pre) {
			s.push(cur->left);
		}
		//如果不是，让右孩子入栈
		else if (cur->right!=NULL && cur->right != pre )
			s.push(cur->right);
		//否则说明其左右孩子都已经访问
		else
		{
			s.pop();
			cout << cur->val << "  ";
			pre = cur;
		}
	}
}
/*int main() {
	vector<int> data{ 4,2,1,leave,leave,3,leave,leave,6,5,leave,leave,7,leave,leave };
	int index = 0;
	TreeNode *root;
	root=createTree(data,index);
	travalTreeInOrder(root);
	cout << endl;
	travalTreeInOrderByMorris(root);
	cout << endl;
	travalTreePreOrder(root);
	cout << endl;
	travalTreePreOrderByMorris(root);
	cout << endl;
	travalBakcOrdrMorris(root);
	cout << endl;
	travalBakcOrdrByStack(root);
	cout << endl;
	getchar();
	return 0;
}*/