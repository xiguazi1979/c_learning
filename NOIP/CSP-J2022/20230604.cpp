#include <bits/stdc++.h>
using namespace std;
long long str[1000];
int i;
int main()
{
	char op;
	long long now = 0;
	while ((op = getchar()) != '@') {
		if (op >= '0' && op <= '9') {
			now *= 10;
			now += op - '0';
		}
		else if(op == '.') {
			str[++i] = now;
			now = 0;
		}
		else if(op == '+') {
			str[i-1] = str[i-1] + str[i];
			str[i] = 0;
			i--;
		}
		else if(op == '-') {
			str[i-1] = str[i-1] - str[i];
			str[i] = 0;
			i--;
		}
		else if(op == '*') {
			str[i-1] = str[i-1] * str[i];
			str[i] = 0;
			i--;
		}
		else if(op == '/') {
			str[i-1] = str[i-1] / str[i];
			str[i] = 0;
			i--;
		}
	}
	printf("%d", str[1]);
	return 0;
} 
