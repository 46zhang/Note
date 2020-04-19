/*
班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。

给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。

示例 1:

输入:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。
示例 2:

输入:
[[1,1,0],
 [1,1,1],
 [0,1,1]]
输出: 1
说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/friend-circles
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;
/*
解法1 广度优先搜索
对每个区域进行搜索

*/
int findCircleNum(vector<vector<int>>& M) {
	int len = M.size(), count(0);
	vector<bool> visit(len, false);
	queue<int> q;
	for (int i = 0; i < len; ++i) {
		if (visit[i] == true)
			continue;
		++count;
		q.push(i);
		visit[i] = true;
		while (!q.empty()) {
			int a = q.front();
			q.pop();
			for (int i = 0; i < len; ++i) {
				if (M[a][i] == 1 && visit[i] == false)
				{
					q.push(i);
					visit[i] = true;
				}
			}
		}
	}

	return count;
}

/*
解法二 并查集
通过并查集归纳相同朋友圈的集合
时间复杂度相比起广度搜索较差
*/
class Solution {
public:
	class UnionFindSet {
	public:
		unordered_map<int, int> rangeMap;
		unordered_map<int, int> friendMap;
		UnionFindSet(int N) {
			for (int i = 0; i < N; ++i)
			{
				rangeMap[i] = 1;
				friendMap[i] = i;
			}
		}
		int findFriend(int f) {
			stack<int> s;
			while (friendMap[f] != f) {
				s.push(f);
				f = friendMap[f];

			}
			while (!s.empty())
			{
				int a = s.top();
				s.pop();
				friendMap[a] = f;
			}
			return f;
		}
		void unionSet(int a, int b) {
			int af = findFriend(a);
			int bf = findFriend(b);
			if (af != bf) {
				int big = af >= bf ? af : bf;
				int small = af == big ? bf : af;
				friendMap[small] = big;
				rangeMap[big] += rangeMap[small];
				rangeMap.erase(rangeMap.find(small));
			}
		}
	};

	int findCircleNum(vector<vector<int>>& M) {
		int len = M.size();
		if (len <= 0)
			return 0;
		UnionFindSet sets(len);
		for (int i = 0; i < len; ++i) {
			for (int j = i + 1; j < len; ++j) {
				if (M[i][j] == 1)
					sets.unionSet(i, j);
			}
		}
		return sets.rangeMap.size();
	}
};