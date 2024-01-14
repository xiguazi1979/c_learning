#include <stdio.h>



extern void solve();
extern int max(int, int);
extern int max1(int, int, int);

#define MAX_N 5
//const int MAX_N = 5;
//int n, a[MAX_N];

int n = 5;
//int a[MAX_N] = {1, 2, 3, 4, 5};
int a[MAX_N] = {5,1,9,6,7};

int main()
{
    solve();
    return 0;
}

int max(int x, int y)
{
    int z;
    if (x > y) {
        z = x;
    }
    else {
        z = y;
    }
    return z;
}

int max1(int x, int y, int z)
{
    int a;
    a = x;
    if (x < y) {
        a = max(y, z);
    }
    else {
        a = max(x, z);
    }
    return a;
}



void solve()
{
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			for(int k = j + 1; k < n; k++) {
				int len = a[i] + a[j] + a[k];
				int longest = max1(a[i], a[j], a[k]);
				int rest = len - longest;

				if( rest > longest) {
					ans = max(ans, len);
				}
			}
		}
	}
	
	printf("Answer is %d.\n", ans);
}

