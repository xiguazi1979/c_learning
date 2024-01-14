#include <bits/stdc++.h>
using namespace std;

int N, M;//M列N行 
//array[x][y] = ptr[y*(M+1)+x] x列y行 
int ans;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char *ptr;

void init_array2(int m, int n)
{
	ptr = (char*) malloc((m + 1) *n * sizeof(char)); // got array[x][y]
}

char *get_array2(int m, int n); // declare func

void set_array2(int m, int n, char val) // stub func
{
	*get_array2(m, n) = val;
}

char *get_array2(int m, int n)
{
	return &ptr[n * (M + 1) + m];
}

bool is_pos_valid(int x, int y)
{
	if(x >= 0 && x < M && y >= 0 && y < N)
		return true;
	else
		return false;
}
bool is_valid(int x, int y)
{
	if(is_pos_valid(x, y) && *get_array2(x, y) != '0') {
		return true;
	}
	else {
		return false;
	}
}
void bfs(int x, int y)//x列y行 
{
	set_array2(x, y, '0');
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
 		if(is_valid(nx, ny)) {
 			bfs(nx, ny);
		}
	}
}

void solve()
{
	scanf("%d%d", &N, &M);

	init_array2(M, N);

	for (int i = 0; i < N; i++) {
		scanf("%s", get_array2(0, i)); 
	}

	for (int i = 0;i < N; i++) {
		for (int j = 0; j < M; j++) {//i行j列 
			if (*get_array2(j, i) != '0') {
				bfs(j, i);
				ans += 1;
			}
		}
	}
}
 
int main()
{
	solve();
	printf("%d", ans);
	return 0;
}
