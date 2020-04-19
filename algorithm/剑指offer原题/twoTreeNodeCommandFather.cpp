#include<iostream>
#include<list>
#include<vector>
using namespace std;

const char leave = -255;

template<typename T> struct TreeNode {
	T value;
	vector<TreeNode *>child;
};


template<typename T>  TreeNode<T> * createTree(const vector<T> &data,int & index ) {
	if (data.size() <= 0 || index < 0 || index >= data.size() || data[index] == leave)
		return nullptr;
	TreeNode<T> *root = new TreeNode<T>,*p;
	root->value = data[index];
	p = createTree(data,++index);
	while (p) {
		root->child.push_back(p);
		p = createTree(data, ++index);
	}
	return root;
}

template<typename T>  void printTree(TreeNode<T>* root) {
	if (root == NULL)
		return;
	std::cout << root->value<<"   ";
	auto iter = root->child.begin();
	while (iter!=root->child.end()) {
		printTree(*iter);
		iter++;
	}
	
}
template<typename T> bool getPath(TreeNode<T> *root, TreeNode<T> * node,list<TreeNode<T> *>&path) {
	if (root == NULL || node == NULL)
		return false;
	path.push_back(root);
	if (root == node)
		return true;
	auto iter = root->child.begin();
	bool found=false;
	
	while (iter != root->child.end()) {
		found=getPath(*iter,node,path);
		if (found)
			return true;
		++iter;
	}
	
	path.pop_back();
	return false;
}

template<typename T> TreeNode<T> * findCommand(list<TreeNode<T> *> path1, list<TreeNode<T> *> path2) {
	auto iter1 = path1.begin();
	auto iter2 = path2.begin();
	TreeNode<T> * father=nullptr;
	while (iter1 != path1.end() && iter2 != path2.end()) {
		if (*iter1 == *iter2)
			father= *iter1;
		++iter1;
		++iter2;
	}
	return father;
}

template<typename T> bool findCommandFather(TreeNode<T> * root,TreeNode<T>* node,TreeNode<T> *another) {
	list<TreeNode<T> *> nodePath;
	list<TreeNode<T> *> anotherPath;
	getPath(root,node,nodePath);
	getPath(root, another, anotherPath);
	TreeNode<T> * father = findCommand(nodePath, anotherPath);
	if (father) {
		std::cout << std::endl << " 最小公共父节点为： " << father->value << std::endl;
		return true;
	}
	return false;
}
template<typename T> TreeNode<T> * findNodeByValue(TreeNode<T> * root,T value) {
	if (root == NULL)
		return nullptr;
	else if (root->value == value)
		return root;
	//std::cout << root->value << "   ";
	auto iter = root->child.begin();
	TreeNode<T> * p;
	while (iter != root->child.end()) {
		p = findNodeByValue(*iter,value);
		if (p)
			return p;
		iter++;
	}
}
void twoTreeNodeCommandFahterTest() {
	vector<char> num = { 'A','B','D','F',leave,'G',leave,leave,'E','H',leave,'I',leave,'J',leave,leave,leave,'C',leave,leave };
	int index = 0;
	TreeNode<char> *root=createTree(num, index);
	//printTree(root);
	TreeNode<char> * node1 = findNodeByValue(root,'G');
	TreeNode<char> * node2 = findNodeByValue(root, 'C');
	//std::cout <<"  " <<node1->value<<"  "<<node2->value<<std::endl;
	findCommandFather(root, node1, node2);
}