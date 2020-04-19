/*
�ڵ��ͨ·����������ͼ�����һ���㷨���ҳ������ڵ�֮���Ƿ����һ��·����

ʾ��1:

 ���룺n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
 �����true
ʾ��2:

 ���룺n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]], start = 0, target = 4
 ��� true

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/route-between-nodes-lcci
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
�ⷨ1����������ȱ����ķ���
ִ����ʱ��576 ms
�ڴ����ģ�74.5 MB
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
���ù�����ȵ��㷨
ִ����ʱ��508 ms
�ڴ����ģ�75 MB
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
