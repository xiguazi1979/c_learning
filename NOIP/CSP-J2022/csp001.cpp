#include <cstdio>
#include <cstring>
using namespace std;
char st[100];
int main() {
    printf("Please input a string and press ENTER:");
    scanf("%s", st);
    int n = strlen(st);
    for (int i = 1; i <= n; ++i ) {
        if (n % i == 0) {
            char c = st[i - 1];
            if (c >= 'a'){
                st[i - 1] = c- 'a' + 'A';
            }

        }
    }
    printf("%s", st);
    return 0;
}