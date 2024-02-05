#include <queue>
#include <cstdio>
using namespace std;

int main()
{
    priority_queue<int> mQueue;

    mQueue.push(3);
    mQueue.push(5);
    mQueue.push(1);

    while (!mQueue.empty()) {
        printf("%d\n", mQueue.top());
        mQueue.pop();
    }

    return 0;
}