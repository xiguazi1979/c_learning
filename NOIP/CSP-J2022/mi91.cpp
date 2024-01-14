#include <cstdio>
using namespace std;

int main()
{
	int a[100] = {0};
	int idx = 0;
	//a[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	for (int i = 2; i < 10000; i++){
		int tmp = i;
		for (int j = 2; j * j <= i; j++){
			if(tmp % j == 0){
				tmp /= j;
				break;
			}
		} 
		if (tmp == i){
			a[idx] = i;
			idx++;
			if(idx == 10){
				break;
			}
		}
	}
	
	for(int i = 0; i < 100; i++){
		if(a[i] != 0){
		printf("%d ", a[i]);
		}
	}
	return 0;
}
