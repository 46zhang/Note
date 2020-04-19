#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct dis {
public:
	int x, y, step;
	dis(int a, int b, int c) { x = a, y = b, step = c; }
};
int xDistance[4] = { -1,1,0,0 };
int yDistance[4] = { 0,0,1,-1 };
int rows, clos;
bool visit[100][100];

int findNearLand(vector<vector<int>>& grid, int x, int y) {
	queue<dis> q;
	q.push(dis(x, y, 0));
	visit[x][y] = true;
	cout << x << "  " << y << endl;
	while (!q.empty()) {
		dis temp = q.front();
		q.pop();
		cout << temp.x << "  " << temp.y << endl;
		for (int i = 0; i < 4; ++i) {
			temp.x += xDistance[i];
			temp.y += yDistance[i];
			if (temp.x < 0 || temp.x >= rows || temp.y < 0 || temp.y >= clos || visit[temp.x][temp.y])
				continue;
			if (grid[temp.x][temp.y])
				return temp.step + 1;
			else
			{
				q.push(dis(temp.x, temp.y, temp.step + 1));
				visit[temp.x][temp.y]=true;
			}
		}
	}
	return -1;
}
int maxDistance(vector<vector<int>>& grid) {
	if (grid.size() <= 0)
		return 0;
	rows = grid.size(), clos = grid[0].size();
	int res(0);

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < clos; ++j) {
			if (!grid[i][j])
				res = max(res, findNearLand(grid, i, j));

		}
	}
	return  res;
}

/*int main() {
	vector<vector<int>> g{ {1,0,0},{0,0,0 }, { 0,0,0 }};
	cout << maxDistance(g) << endl;
}*/