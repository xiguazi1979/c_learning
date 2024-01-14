#include <bits/stdc++.h>
using namespace std;

int n, m;
int last[27];
int in[601];
int in1[601];
int ans[27];
stack<int> s;

struct edge {
	int from;
	int to;
	int next;
};
edge e[601];
char mem[601][4];
void insertedge(int a, int b, int i)
{
	
	e[i].from = a;
	e[i].to = b;
	e[i].next = last[a];
	last[a] = i;
	in[b]++;
}

//返回-1 一个0没有有环 0：多个0条件不全 >0:找到那个要入栈的 
int findin0()
{
	int count = -1;
	int tmp = 0; 
	for (int i = 1; i <= n; i++) {
		if (in1[i] == 0) {
			count++;
			tmp = i;
		}
	}
	if (count > 0) {
		return 0;
	}
	else if(count == -1) {
		return -1;
	}
	return tmp;
}
void pushstack(int p)
{
	in1[p] = -1;
	if (last[p] == 0) {
		s.push(p);
		return;
	}
	s.push(p); 
	int cur = last[p];
	while (cur > 0) {
		in1[e[cur].to]--;
		cur = e[cur].next;
	}

}
int toposort()//-1有环； 0无法确认； 
{
	int num = 0;
	int ret = 0; 
	for (int i = 1; i <= m; i++) {
		in1[i] = in[i];
	}
	ret = findin0();
	while (ret > 0) {
		pushstack(ret);
 		ans[num++] = s.top();
 		if (num == n) {
 			return num;
		}
		ret = findin0();
		if (ret == -1) {
			if (!s.empty()) {
				s.pop();
			}
			return -1;
		} 
		if (ret == 0) {
			if (!s.empty()) {
				s.pop();
			}
			return 0;
		} 
		s.pop();
	}
	if (!s.empty()) {
		s.pop();
	}
	return num; 
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%s", mem[i]);
		int a = mem[i][0] - 'A' + 1;
		int b = mem[i][2] - 'A' + 1;
		if (a == b) {
			printf("Inconsistency found after %d relations.", i);
			return 0;
		}
		insertedge(a, b, i);
		int t = toposort();
		if (t == -1) {
			printf("Inconsistency found after %d relations.", i);
			return 0;
		}
		if (t == n) {
			printf("Sorted sequence determined after %d relations: ", i);
			for (int i = 0; i < n; i++) {
				printf("%c", ans[i] + 'A' - 1);
			} 
			printf(".");
			return 0;
		}
			

	}
	printf("Sorted sequence cannot be determined.");
	
	
	return 0;
}
