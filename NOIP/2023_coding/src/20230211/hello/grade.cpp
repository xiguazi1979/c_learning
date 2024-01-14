#include <bits/stdc++.h>
using namespace std;
int main()
{
	int ans;
	scanf("%d", &ans);
	if(ans >= 90) {
		printf("A");
	}
	else if( ans >= 80) {
		printf("B");
	}
	else if(ans >= 70) {
		printf("C");
	}
	else if(ans >= 60) {
		printf("D");
	}
	else{
		printf("E");
	}
	return 0;
}
