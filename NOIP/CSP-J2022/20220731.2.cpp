#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10, M = 12;
char field[N][M+1] = {
"W........WW.",
".WWW.....WWW",
"....WW...WW.",
"..WW.....WW.",
"..W..W...W..",
"..W......W..",
".W.W.....WW.",
"W.W.W.....W.",
".W.W......W.",
"..W.......W.",
};

void dfs(int x, int y)
{
    field[x][y] = '.';
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && field[nx][ny] == 'W') {
                dfs(nx, ny);
            }
        }
    }
}
void solve()
{
    int result = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] == 'W') {
                dfs(i, j);
                result++;
            }
        }
    }
    printf("Result is %d", result);
}

int main ()
{
    solve();
    return 0;
}

