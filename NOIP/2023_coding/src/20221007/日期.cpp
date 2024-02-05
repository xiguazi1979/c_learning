#include <stdio.h>
using namespace std;
char a[5];
int ans, m, d;
int main()
{
	for (int i = 0; i < 5; i++) {
		scanf("%c", &a[i]);
	}
	m = (a[0] - 48) * 10 + a[1] - 48;
	d = (a[3] - 48) * 10 + a[4] - 48;
	if (a[0] > '1' ) {
		ans++;
		if (a[1] != '2' && a[1] !='0') {
			a[0] = '0';
		}
		else if (a[1] == '0') {
			a[0] = '1' ;
		}
		else if (d > 28) {
			a[0] = '1';
		}
		else {
			a[0] = '0';
		}
	}
	else if (a[0] =='1' && a[1] >'2') {
		ans++;
		a[1] = '2';
	}
	else if (d > 31) {
		ans++;
		a[3] = '1';
	}
	else if ((m==11||m==4||m==6||m==9) && d > 30) {
		ans++;
		a[3] = '1';
	}
	else if (a[1] == '2' && d > 28) {
		ans++;
		a[3] = '1';
	}
	
	
	
	
	
	printf("%d", ans);
}
