#include<iostream>
#include<string>
#include<vector>
using namespace  std;

class Trie {
	class Node;
public:
	/** Initialize your data structure here. */

	//root =new Node();
	Trie() {
		root = new Node(0);
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		insertWord(root, word);
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		return searchWord(root, word);
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		return startsWith(root, prefix);
	}
private:
	class Node {
	public:
		Node(int i) :cout(i),isLeaf(false), child(26, NULL) { }
		int  cout;
		bool isLeaf;
		vector<Node *> child;
	};
	void insertWord(Node *root, const string&word) {
		if (root == NULL )
			return;
		if (word.size() == 0)
		{
			root->isLeaf = true;
			return;
		}
		int a = word[0] - 'a';
		//cout << " a: " << a << endl;
		if (root->child[a] == NULL)
		{
			//root->isLeaf = false;
			root->child[a] = new Node(1);
			//root->child[a]->isLeaf = true;
		}
		else
			++(root->child[a]->cout);
		insertWord(root->child[a], word.substr(1));
	}
	bool searchWord(Node *root, const string & word) {
		if (word.size() == 0 && root->isLeaf == true)
			return true;
		else if (word.size() == 0 )
			return false;
		int a = word[0] - 'a';
		if (root->child[a] != NULL && root->child[a]->cout > 0)
			return searchWord(root->child[a], word.substr(1));
		return false;
	}
	bool startsWith(Node *root, const string &prefix) {
		if (prefix.size() <= 0)
			return true;
		//if (root->isLeaf == true)
			//return false;
		int a = prefix[0] - 'a';
		if (root->child[a] != NULL && root->child[a]->cout > 0)
			return startsWith(root->child[a], prefix.substr(1));
		return false;
	}

	Node* root;

};

void trieTest() {
	Trie t;
	t.insert("ab");
	t.insert("abc");
	//cout << t.search("app");
	//cout << t.search("apple");
	cout << t.startsWith("abc")<<endl;
	//t.insert("app");
	cout << t.search("abc")<<endl;
}