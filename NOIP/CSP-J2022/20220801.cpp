#include <queue>
#include <cstdio>

using namespace std;

const int INF = 100000000;

typedef pair<int, int> P;

const int N = 10, M = 10;
char maze[N][M +1] = {
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

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void display()
{
    static int cnt = 0;
    printf("\n====\nRound %d:\n", cnt++);

    for (int j = 0; j < N; j++) {
        printf("\n");
        for (int i = 0; i < M; i++) {
            if (d[i][j] != INF) {
                printf("%2d", d[i][j]);
            }
            else {
                printf("%2c", maze[j][i]);
            }
        }
    }
    printf("\n");
}
int bfs()
{
    queue<P> queue;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            d[i][j] = INF;
        }
    }

    queue.push(P(sx, sy));
    d[sx][sy] = 0;

    while (queue.size()) {
        P p = queue.front();
        queue.pop();

        if(p.first == gx && p.second == gy) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i], ny = p.second + dy[i];

            if(0 <= nx && nx < M && 0 <= ny && ny < N && maze[ny][nx] != '#' && d[nx][ny] == INF) {
                queue.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
                display();
            }
        }
    }

    return d[gx][gy];
}

void solve()
{
    int result = 0;\
    result = bfs();

    printf("Result: %d.\n", result);
    display();
}

int main()
{
    solve();
    return 0;
}