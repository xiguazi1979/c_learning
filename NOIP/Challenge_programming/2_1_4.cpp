#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 4;
int n = 5;  // num of candidate elements
int k = 13; // sum target
int a[MAX_N] = {1, 2, 4, 7, 6};

bool dfs(int i, int sum)
{
    if (i == n) {
        if (sum == k) {
            printf("\nFOUND:");
            return true;
        }
        else {
            return false;
        }
    }

    if (dfs(i + 1, sum)) {
        return true;
    }

    if (dfs(i + 1, sum + a[i])) {
        printf(" %d,", a[i]);
        return true;
    }

    return false;
}

int main()
{
	if (dfs(0, 0)) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
}