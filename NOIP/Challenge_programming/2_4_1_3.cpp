#include <queue>
#include <cstdio>

using namespace std;

const int MAX_N = 4;
int N = MAX_N;

int A[MAX_N + 1] = {10, 14, 20, 21};
int B[MAX_N + 1] = {10, 5, 2, 4};

int P = 10;
int L = 25;

void solve()
{
    A[MAX_N] = L;
    B[MAX_N] = 0;
    N++;

    priority_queue<int> mQueue;

    int answer = 0, pos = 0, tank = P;

    for (int i = 0; i < N; i++) {
        int delta = A[i] - pos;

        while (tank - delta < 0) {
            if (mQueue.empty()) {
                answer = -1;
                printf("No answer.\n");
                return;
            }
            tank += mQueue.top();
            mQueue.pop();
            answer++;
        }

        tank -= delta;
        pos = A[i];
        mQueue.push(B[i]);
    }

    printf("Answer is %d.\n", answer);
}

int main()
{
    solve();
    return 0;
}