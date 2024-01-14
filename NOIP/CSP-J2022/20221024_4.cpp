#include <bits/stdc++.h>
using namespace std;
int n;
char A[67108864];
int main()
{
	scanf("%d", &n);
	//A[1] = 'A'
	for (int i = 1; i <= n; i++) {
		int x = pow(2,i - 1);
		A[x] = 'A' + i - 1;
		for (int j = 1; j <= pow(2,i - 1) - 1; j++) {
			A[(int)pow(2,i - 1) + j] = A[j];
		}
	}
	for (int i = 1; i <= pow(2,n) - 1; i++) {
		printf("%c", A[i]);
	}
	printf("\n");
	return 0;
}
