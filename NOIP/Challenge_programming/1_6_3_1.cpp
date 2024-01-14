#include <stdio.h>
//#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 3;
int n = 3;  // num of cards
//int m = 10; // sum target
//int k[MAX_N] = {3,1,5};
int kk[MAX_N * MAX_N];

extern void solve();
extern void solve1();
extern void solve2();

bool binary_search(int x)
{
    int k[MAX_N] = {3,1,5};
    int left = 0, right = n;
    
    sort(k, k+n);
    while (right - 1 >= left) {
        int i = (left + right) / 2;
        if (k[i] == x) {
            return true;
        }
        else if (k[i] < x) {
            left = i + 1;
        }
        else {
            right = i - 1; 
        }
    }
    
    return false;
}

bool binary_search2(int x)
{
    int left = 0;
    int right = n * n;

    while (right - 1 >= left) {
        int i = (left + right) / 2;
        if (kk[i] == x) {
            return true;
        }
        else if (kk[i] < x) {
            left = i + 1;
        }
        else {
            right = i;
        }
    }

    return false;
}

void solve()
{
    int k[MAX_N] = {3,1,5};
    int m = 10; // sum target
    int counter = 0;
    int x;
    bool f = false;
    int a,b,c,d;
    for (a = 0; a < n; a++) {
        for (b = 0; b < n; b++) {
            for (c = 0; c < n; c++) {
                for (d = 0; d < n; d++) {
                    x = k[a] + k[b] + k[c] + k[d];
                    if (m == k[a] + k[b] + k[c] + k[d]) {
                        f = true;
                        printf("It's doable: %d, %d, %d, %d\n", k[a], k[b], k[c], k[d]);
                        counter++; // counter = counter + 1;  counter += 1;
                    }
                }
            }
        }
    }

    if (!f) {
        printf("Its impossible!");
    }

    printf("Counter: %d\n", counter);
}

void solve1()
{
    int k[MAX_N] = {3,1,5};
    int m = 10; // sum target
    int a,b,c,d;
	sort(k, k + n);
	bool f = false;
    for (a = 0; a < n; a++) {
        for (b = 0; b < n; b++) {
            for (c = 0; c < n; c++) {
				if (binary_search(m - k[a] - k[b] - k[c])) {
                    d = m - k[a] - k[b] - k[c];
					f = true;
                    printf("It's doable: %d, %d, %d, %d\n", k[a], k[b], k[c], d);
				}
            }
        }
    }

    if (!f) {
        printf("Its impossible!");
    }	
}


#if 0
void solve2()
{
    int k[MAX_N] = {3,1,5};
    int m = 10; // sum target
    bool f = false;

    int a,b,c,d;
    for (c = 0; c < n; c++) {
        for (d = 0; d < n; d++) {
            kk[c * n + d] = k[c] + k[d];
        }
    }

    sort(kk, kk + n * n);

    for (a = 0; a < n; a++) {
        for (b = 0; b < n; b++) {
            if (binary_search2(m - k[a] - k[b])) {
                f = true;
                printf("It's doable: %d, %d, X, Y\n", k[a], k[b]);
            }
        }
    }

    if (!f) {
        printf("It's impossible!");
    }
}

#endif

int main()
{
	solve2();
    return 0;
}

void solve2()
{
    int k[MAX_N] = {3,1,5};
    int m = 10;
    bool f = false;

    int a,b,c,d;
    for (c = 0; c < n; c++) {
        for (d = 0; d < n; d++) {
            kk[c * n + d] = k[c] + k[d];
        }
    }
    sort(kk, kk + n * n);

    for (a = 0; a < n; a++) {
        for (b = 0; b < n; b++ ) {
            if (binary_search2(m - k[a]- k[b])) {
                f = true;
                printf("its doable: %d, %d, X, Y\n", k[a], k[b]);

            }
        }
    }

    if (!f) {
        printf("it's impossible!");
    }
}
