#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 6;
char S[N + 1] = "ACDBCB";

void solve()
{
    int a = 0, b = N -1;

    while (a <= b) {
        bool left = false;

        for (int i = 0; a + i <= b; i++) {
            if (S[a + i] < S[b - i]) {
                left = true;
                break;
            }
            else if (S[a + i] > S[b - i]) {
                left = false;
                break;
            }            
        }

        if (left) {
            printf("%c", S[a++]);
        }
        else {
            printf("%c", S[b--]);
        }
    }

    printf("\n");
}

int main()
{
    solve();
    return 0;
}