#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

struct node {
public:
	node(char x) :value(x), dic(26, nullptr),isLeave(false) { }
	~node() {
		for (auto d : dic)
			if (d)
				delete d;
	}
	char value;
	bool isLeave;
	vector<node*> dic;
};

class TrilTree {
public:
	TrilTree() :root(new node(-1)),count(0) { }
	void addString(const string& s) {
		if (s.size() <= 0)
			return;
		cout << s.size()<<"  ";
		//if (false == addNote(s, root))
		bool flag(false);
		int a= addNote(s, root, flag);
		if (!flag&&a>0)
			count += s.size()+1;
		else
			count += a;
		cout << " cout: " << count << " a: " << a << endl;
	}
	int count; //½ÚµãÊý
private:
	int addNote(const string& s, node *father,bool& flag) {
		int i = s.size() - 1;
		int a = s[i] - 'a';
		int c(0);
		if (!father->dic[a])
		{
			father->dic[a] = new node(a);
			if (i == 0)
				father->dic[a]->isLeave = true;
			++c;

		}
		else if (father->dic[a]->isLeave)
			flag = true;
		if(i>0)
			c += addNote(s.substr(0, i), father->dic[a], flag);
		return c;
		
	}
	node *root;
	
};

class TrilNode {
public:
	TrilNode *children[26];
	int count;
	TrilNode() {
		for (int i = 0; i < 26; ++i)
			children[i] = nullptr;
		count = 0;
	}
	TrilNode *get(char c) {
		if (!children[c - 'a'])
		{
			children[c - 'a'] = new TrilNode();
			++count;
		}
		return children[c - 'a'];
	}
}; 
int minimumLengthEncoding(vector<string>& words)
{
	TrilNode *t = new TrilNode();
	unordered_map<TrilNode*, int> mp;
	for (int i = 0; i < words.size();++i) {
		TrilNode *cur = t;
		for (int j = words[i].size() - 1; j >= 0; --j) {
			cur = cur->get(words[i][j]);
		}
		mp[cur] = i;
	}
	int res(0);
	for (auto a: mp) {
		auto n = a.first;
		auto num = a.second;
		if (n->count == 0)
			res += words[num].size();
	}
	return res;
}
/*int main() {
	vector<string> s{ "time", "me", "bell" };
	int a=minimumLengthEncoding(s);
	//root.addString("addcd");
	cout <<a  << endl;
	getchar();
	return 0;
}*/