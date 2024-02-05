#include <cstdio>
using namespace std;

int a[1000000];

int main()
{
    int N;

    int count = 0;
    int ans = 0;

    scanf("%d", &N);

    for (int j = 1; j <= N; j++) {

        count = 0;
        ans = 0;

        for (int i = 1; i < j; i++) {
            if (j % i == 0){
                a[count] = i;
                count = count + 1;
            }
        }

        for (int i = 0; i < count; i++) {
            ans += a[i];
        }

        if (ans == j) {
            printf("%d its factors are", j);
            for (int i = 0; i < count; i++) {
                printf(" %d", a[i]);
            }
            printf("\n");
        }

    }

    return 0;
}
