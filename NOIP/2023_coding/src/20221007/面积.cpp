#include <stdio.h>
using namespace std;
long long a, b, c;
int main()
{
	//freopen("���.in", "r", stdin);
	//freopen("���.out", "w", stdout);	
	scanf("%d%d%d", &a, &b, &c);
	if (a * a > b * c) {
		printf("Alice");
	}
	else {
		printf("Bob");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
