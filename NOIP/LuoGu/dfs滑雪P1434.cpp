#include <bits/stdc++.h>
using namespace std;

int a[101][101];
int b[101][101];
int m, n, ans;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool check(int xx, int yy)
{
	if (xx > 0 && yy > 0 && xx <= m && yy <= n) {
		return true;
	}
	return false;
}

int dfs(int x, int y)
{
	if (b[x][y] != 0) {
		return b[x][y];
	}
	b[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (check(xx, yy) && a[xx][yy] < a[x][y]) {
			b[x][y] = max(b[x][y], dfs(xx, yy) + 1);
		}
	}
	return b[x][y];
}

int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			ans = max(ans, dfs(i, j));
		}
	}
	printf("%d", ans);
	return 0;
}
