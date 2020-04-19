/*
节点间通路。给定有向图，设计一个算法，找出两个节点之间是否存在一条路径。

示例1:

 输入：n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
 输出：true
示例2:

 输入：n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]], start = 0, target = 4
 输出 true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/route-between-nodes-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
bool dfs(vector<vector<int>>& mp, int start, const int& target, vector<bool>& visit) {
	if (visit[start] == true)
		return false;
	bool res = false;
	// cout<<"start "<<start<<" target "<<target<<endl;
	if (start == target)
		return true;
	for (int i = 1; i < mp[start].size(); ++i) {
		visit[start] = true;
		res = dfs(mp, mp[start][i], target, visit);
		if (res == true)
			return true;
	}
	return false;
}
/*
解法1采用深度优先遍历的方法
执行用时：576 ms
内存消耗：74.5 MB
*/
bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
	if (n <= 0)
		return false;
	vector<vector<int>> mp(n, vector<int>(1, -1));
	vector<bool> visit(n, false);
	for (int i = 0; i < graph.size(); ++i) {
		mp[graph[i][0]].push_back(graph[i][1]);
		
	}
	return dfs(mp, start, target, visit);
}

/*
采用广度优先的算法
执行用时：508 ms
内存消耗：75 MB
*/
bool findWhetherExistsPathII(int n, vector<vector<int>>& graph, int start, int target) {
	if (n <= 0)
		return false;
	vector<vector<int>> mp(n, vector<int>(1, -1));
	queue<int> q;
	vector<bool> visit(n, false);
	for (int i = 0; i < graph.size(); ++i) {
		mp[graph[i][0]].push_back(graph[i][1]);
		//cout<<graph[i][0]<<"  "<<graph[i][1]<<"  "<<mp[graph[i][0]][1]<<endl;
	}
	
	q.push(start);
	while (!q.empty()) {
		start = q.front();
		q.pop();
		
		if (visit[start] == true)
			continue;
		visit[start] = true;
		if (target == start)
			return true;
		for (int i = 1; i < mp[start].size(); ++i)
			if (visit[mp[start][i]] == false)
				q.push(mp[start][i]);
	}
	return false;
}
