#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	int rank;
	int index;
};
node a[10001];

int n;
bool comp1(node x, node y){
	return x.data < y.data;
}
bool comp2(node x, node y){
	return x.index < y.index;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].data);
		a[i].index = i;
	}
	sort(a + 1, a + 1 + n, comp1);
	for (int i = 1; i <= n; i++) {
		a[i].rank = i;
	}
	sort(a + 1, a + 1 + n, comp2);
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i].rank);
	}
	return 0;
}
