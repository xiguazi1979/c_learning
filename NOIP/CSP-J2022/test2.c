#include <stdio.h>



extern void solve();
extern int min(int, int);
extern int max(int, int);
extern int max1(int, int, int);

int L = 10;
int n = 5;
#define MAX_N 5



int x[MAX_N] = {2,3,4,6,9};

int main()
{
    solve();
    return 0;
}

void solve()
{
    int minT = 0;
    for (int i = 0; i < n; i++){
        minT = max(minT, min(x[i], L - x[i]));
    }

    int maxT = 0;
    for (int i = 0; i < n; i++){
        maxT = max(maxT, max(x[i], L - x[i]));
    }

    printf("Answer is max(%d),min(%d)\n", maxT, minT);
}

int min(int x, int y)
{
	int z;
	if (x > y) {
		z = y;
	}
	else {
		z = x;
	}
	return z;
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
                a = y;
		if (y < z) {
			a = z;
		}
        }
        else if (x < z){
                a = z;
        }
        return a;
}