#include <bits/stdc++.h>
using namespace std;

typedef struct city{
	double first;
	double second;
	double all;
	char name[20];
}city; 
int n;
double ans;
int main()
{
	
	scanf("%d", &n);
	city *cityarray;
	cityarray = (city*) malloc(n * sizeof(city));
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf%s", &cityarray[i].first, &cityarray[i].second, cityarray[i].name);
		cityarray[i].all = cityarray[i].first + cityarray[i].second;
	}
	for (int i = 0; i < n; i++) {
		ans += cityarray[i].all;
	}
	printf("%lf", ans);
	return 0;
}//3
//2.7 3.2 wuqibazao
//3.1 3.4 666
//2.4 3.7 888
