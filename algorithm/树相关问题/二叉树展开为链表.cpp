#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

	1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
	3
	 \
	  4
	   \
		5
		 \
		  6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
const int null = -1008611;
 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
 template
<typename T>
static TreeNode * createTree(const vector<T> & num)
{
	if (num.size()<=0 )
		return NULL;
	queue<TreeNode *> q;
	TreeNode * root = new TreeNode(num[0]),*tree(root);
	q.push(root);
	int i = 1;
	while (i<num.size())
	{
		root = q.front();
		if (root == NULL)
		{
			q.pop();
			++i;
			continue;
		}
		if (num[i] != null) {
			root->left = new TreeNode(num[i]);
			q.push(root->left);
		}
		++i;
		if (i < num.size() && num[i] != null) {
			root->right = new TreeNode(num[i]);
			q.push(root->right);
		}
		++i;
		q.pop();
	}
	return tree;
}

 void travalTreeInonfer(TreeNode *root) {
	 if (root == NULL)
		 return;
	 travalTreeInonfer(root->left);
	 cout << root->val<<"  ";
	 travalTreeInonfer(root->right);
}

void travalTreePreorder(TreeNode *root) {
	if (root == NULL)
		return;
	cout << root->val << "  ";
	travalTreePreorder(root->left);
	travalTreePreorder(root->right);
	 
 }
void flatten(TreeNode* root) {
	if (root == NULL)
		return;
	flatten(root->right);
	flatten(root->left);
	TreeNode *p;
	TreeNode *temp = root->right;
	p = root->left;
	cout << root->val << " left: ";
	while (p) {
		cout << p->val << " ";
		p = p->right;
	}
	cout << " right:  ";

	p = root->right;
	while (p) {
		cout << p->val << " ";
		p = p->right;
	}
	
	if (root->left) {
		root->right = root->left;
		TreeNode *r = root->right;
		while (r->right)
			r = r->right;
		r->right = temp;
		
	}

	cout << " 合并后 ";
	p = root;
	while (p) {
		cout << p->val << " ";
		p = p->right;
	}
	cout << endl;

}

void flattenTest() {
	vector<int> num = { 1,2,5,3,4,null,6 };
	TreeNode *root=createTree(num);
	travalTreeInonfer(root);
	cout << endl;
	travalTreePreorder(root);
	cout << endl;
	cout << INT32_MIN << endl;
	flatten(root);
}