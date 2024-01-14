#include <bits/stdc++.h>
using namespace std;

#define INF 1000000
int N, K; 
int dx[3] = {1,-1,2};
int d[200001];

int bfs()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < 200001; i++) {
		d[i] = INF;
	}
	queue<int> queue;
	queue.push(N);
	d[N] = 0;
	while(queue.size()) {
		int p = queue.front();
		queue.pop();
		if (p == K) {
			break;
		}
		for (int i = 0; i < 3; i++) {
			int nx;
			if (i == 2) {
				nx = p * dx[2];
			}
			else{
				nx = p + dx[i];
			}
			if (0 <= nx && nx <= 200000&& d[nx] == INF) {
				queue.push(nx);
				d[nx] = d[p] + 1;
			}
		}
	}
	return d[K];
}
int main()
{
	int result = bfs();
	printf("%d", result);
	return 0; 
}
