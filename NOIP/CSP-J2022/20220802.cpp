#include <queue>
#include <cstdio>

using namespace std;

typedef pair<int, int> P;

const int INF = 100000000;
const int N = 10, M = 10;
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

int sx = 0, sy = 1;
int gx = 9, gy = 8;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int d[N][M];

void display ()
{
    for (int i = 0; i < N; i++) {
        printf("\n");
        for (int j = 0; j < M; j++){
            if(maze[i][j] == '#') {
                printf("%2c", '#');
            }
            else if (d[i][j] == INF)
            {
                printf("%2c", '.');
            }
            else {
                printf("%2d", d[i][j]);
            }
        }
    }
}

void bfs()
{
    queue<P> queue;

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++) {
            d[i][j] =INF;
        }
    }
    queue.push (P(sx, sy));
    d[sx][sy] = 0; 

    while (queue.size() > 0)
    {
        P p = queue.front();
        queue.pop();
        
        if (p.first == gx && p.second == gy) {
            printf("%d", d[p.first][p.second]);
            break;
        }

        for (int i = 0; i < 4; i++) {
            
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M &&
                    maze[nx][ny] != '#' && d[nx][ny] == INF)
            {
                queue.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
                display();
            }
        }

    }

}

int main ()
{
    bfs();
    return 0;
}
