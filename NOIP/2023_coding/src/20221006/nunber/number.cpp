#include <bits/stdc++.h>
using namespace std;

#define INF 10001
int n, m, num, p, MAXans;
int ans[1000000];
int dx[2] = {1, 0};
int dy[3] = {1, 0, -1};
int maze[1000][1000];
int memory_maze[1000][1000];
void display()
{
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < m; j++) {
            
            printf("%4d", maze[i][j]);
            
        }
    }
    printf("\n");
}
void dfs(int x, int y)
{
	ans[p] += maze[x][y];
	maze[x][y] = INF;
	//display();
	if (x == n - 1 && y == m - 1) {
		p++;
		ans[p] = ans[p - 1] - memory_maze[x][y];
		maze[x][y] = memory_maze[x][y];
		return;
	}
	if (maze[x][y + 1] == INF && maze[x][y - 1] == INF && maze[x + 1][y] == INF) {
		p++;
		ans[p] = ans[p - 1] - memory_maze[x][y];
		ans[p - 1] = INF;
		maze[x][y] = memory_maze[x][y];
		return;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++){
			if ((i == 0 && j == 0) || (i == 0 && j == 2) ||(i == 1 && j == 1)){
				continue;
			}
			int ny = y + dx[i];
			int nx = x + dy[j];
			if (nx >= 0 && nx <= m && ny >= 0 && ny <= n && maze[ny][ny] != INF) {								
				dfs(nx, ny);
			}
			
		}
	}
	maze[x][y] = memory_maze[x][y];
	return;
}
int main()
{
	//freopen("number.in","r", stdin);
	//freopen("number.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i <1000; i++) {
		for (int j = 0; j < 1000; j++) {
		maze[i][j] = INF;
		memory_maze[i][j] = INF;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			scanf("%d", &num);
			maze[i][j] = num;
			memory_maze[i][j] = num;
		}
	}
	dfs(0, 0);
	for (int i = 0; i < p - 1; i++) {
		if (ans[i] != INF) {
			MAXans = max(MAXans, ans[i]);
		}
		
	} 
	printf("%d", MAXans);
	//fclose(stdin);
	//fclose(stdout);
	
} 
