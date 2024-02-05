#include <cstdio>
#include <queue>

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
    int ans = 0;
    int pos = 0;
    int tank = P;
    priority_queue<int> mqueue;
    for (int i = 0; i < N; i++) {
        int delta = A[i] - pos;
        while (tank - delta < 0) {
            if (mqueue.empty()) {
                ans = -1;
                printf("No answer.");
                return;
            }
            tank += mqueue.top();
            mqueue.pop();
            ans++;
        }

        tank -= delta;
        pos = A[i];
        mqueue.push(A[i]);
    }
    printf("the answer is %d\n", ans);
}

int main()
{
    solve();
    return 0;
}