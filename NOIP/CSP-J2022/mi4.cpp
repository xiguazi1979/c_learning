#include <queue>
#include <cstdio>

using namespace std;
const int INF = 100000000;

typedef struct {
    int x;
    int y;
} POSITION;

typedef pair<int, int> P; // (vertical position, horizontal position)
const int N = 10, M= 10; // N: maze array vertical position
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

int d[N][M]; //d[horizontal position][vertical position]

int dx[4] = {1, 0, -1, 0},dy[4] = {0, 1, 0, -1}; //dx: delta for vertical position  dy: delta for horizontal position
void display()
{
    static int cnt = 0;
    printf("\n");
    for (int j = 0; j < M; j++) {
        printf("\n");
        for (int i = 0; i < N; i++){
            if(d[i][j] != INF){
                printf("%2d",d[i][j]);
            }
            else {
                printf("%2c", maze[j][i]);
            }
        }
    }
    printf("\n");
}

char findMaze(int x, int y)
{
    if ( 0 <= x && x < N) {
        return maze[y][x];
    }
}
int bfs()
{
    queue<P> queue;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            d[i][j] = INF;
        }
    }

    POSITION pos;
    pos.x = sx;
    pos.y = sy;
    queue.push(pos);

    d[sx][sy] = 0;

    while (queue.size()) {
        POSITION pos = queue.front();
        queue.pop();

        if (pos.x == gx && pos.y == gy) {
            break;
        } 

        for (int i = 0; i < 4; i++) {

            nx = pos.x + dx[i];
            ny = pos.y + dy[i];

            //if (0 <= nx && nx < M && 0 <= ny && ny < N && maze[ny][nx] != '#' && d[nx][ny] == INF) {
                if (0 <= nx && nx < M && 0 <= ny && ny < N && findMaze(nx, ny) != '#' && d[nx][ny] == INF) { 
                d[nx][ny] = d[pos.x][pos.y] + 1;
                pos.x = nx;
                pos.y = ny;
                queue.push(pos);

                display();
            }
        }
    }

    return d[gx][gy];   
}

void solve()
{
    int result = 0 ;
    result = bfs();

    printf("Result:%d.\n",result);
    display();
}
int main()
{
    solve();
    return 0;
}


