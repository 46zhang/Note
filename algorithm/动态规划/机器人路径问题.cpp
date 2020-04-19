#include<iostream>
#include<vector>
using namespace std;

bool check(int x, int y, int k) {
	int sum = 0;
	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}
	while (y > 0) {
		sum += y % 10;
		y /= 10;
	}
	return sum <= k;
}
int traceBack(int x, int y, int m, int n, int k, vector<vector<bool>>& visit) {
	if (x < 0 || x >= m || y < 0 || y >= n || visit[x][y])
		return 0;
	int res(0);
	visit[x][y] = true;
	if (check(x, y, k) == true)
		res = 1;
	else
	    return 0;

	res += traceBack(x + 1, y, m, n, k, visit);
	res += traceBack(x - 1, y, m, n, k, visit);
	res += traceBack(x, y - 1, m, n, k, visit);
	res += traceBack(x, y + 1, m, n, k, visit);
	cout << x << "  " << y << res << "  " << endl;
	return res;
}
static int movingCount(int m, int n, int k) {
	vector<vector<bool>> visit(m, vector<bool>(n));
	return traceBack(0, 0, m, n, k, visit);
}
/*int main() {
	cout<<movingCount(3, 3, 1);
	
	getchar();
}*/