#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;
const int N = 10, M = 10;
typedef pair<int, int> P;

char maze[N][M+1] = {
"#S######.#",
"......#..#",
".#.##.##.#",
".#........",
"##.##.####",
"....#....#",
".#######.#",
"....#.....",
".####.###.",
"....#...G#",
};
int sx = 1, sy = 0;
int gx = 8, gy = 9;
int d[N][M];
int dx[4] = {1,0,-1,0};
int dy[4] = {1,0,-1,0};
int cnt;

void display()
{
	printf("\n======\nRound %d:",cnt++);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (d[j][i] != INF) {
				printf("%2d", d[j][i]);
			}
			else{
				printf("%2c", maze[i][j]);
			}
		}
	}
	printf("\n");
}
int bfs()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			d[i][j] = INF;
		}
	}
	queue<P> queue;
	queue.push(P(sx,sy));
	d[sx][sy] = 0;
	while (queue.size()) {
		P p = queue.front();
		queue.pop();
		if (p.first == gx && p.second == gy) {
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + p.first, ny = dy[i] + p.second;
			if(nx >= 0 && ny >= 0 && nx < M && ny < N && maze[ny][nx] != '#' && d[nx][ny] == INF) {
				d[nx][ny] = d[p.first][p.second] + 1;
				queue.push(P(nx, ny));
				display();
			}
		}
	}
	return d[gx][gy];
}
int main()
{
	int result = 0;
	
	result = bfs();
	if(result == INF) {
		printf("×ß²»µ½"); 
	}
	else {
		printf("%d", result);
	}
	
	
	
	return 0;
}
