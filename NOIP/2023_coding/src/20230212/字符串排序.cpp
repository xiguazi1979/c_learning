#include <bits/stdc++.h>
using namespace std;
char a[200], b[200], c[200];
char x[3];
int main()
{
	scanf("%s", a);
	scanf("%s", b);
	scanf("%s", c);
	if(strcmp(a,b) > 0 && strcmp(a,c) > 0) {
		x[2] = 'a';
		if(strcmp(b,c) > 0) {
			x[1] = 'b';
			x[0] = 'c';
		}
		else{
			x[1] = 'c';
			x[0] = 'b';
		}	
	}
	else if(strcmp(b,a) > 0 && strcmp(b,c) > 0) {
		x[2] = 'b';
		if(strcmp(a,c) > 0) {
			x[1] = 'a';
			x[0] = 'c';
		}
		else{
			x[1] = 'c';
			x[0] = 'a';
		}	
	}
	else{
		x[2] = 'c';
		if(strcmp(b,a) > 0) {
			x[1] = 'b';
			x[0] = 'a';
		}
		else{
			x[1] = 'a';
			x[0] = 'b';
		}			
	}
	for (int i = 0; i < 3; i++) {
		if(x[i] == 'a') {
			printf("%s\n", a);
		}
		if(x[i] == 'b') {
			printf("%s\n", b);
		}
		if(x[i] == 'c') {
			printf("%s\n", c);
		}
	}
	return  0;
}
