#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
#define MAX_NAME_LEN 128
int n;
typedef struct city
{
    char name[MAX_NAME_LEN];
    double fir;
    double sec;
    double thi;
    double all;
    double part;

}city;
int main()
{
    char *array;
    int *intarray;
    city *cityarray;
    //char array1[];
//	freopen("timu1.in", "r", stdin);
//	freopen("timu1.out", "w", stdout);
	scanf("%d", &n);

    array = (char *)malloc(n);
    intarray = (int*)malloc(n * sizeof(int));
    cityarray = (city*)malloc(n * sizeof(city));
#if 0
    for (int i = 0; i < n; i++) {
        array[i] = i;
    }
#endif

    memset(array, 1, n);
    memset(intarray, 0, n * sizeof(int));

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("i: %d\n", array[i]);
    }

    printf("\nintarray:\n");

    for (int i = 0; i < n; i++) {
        printf("i: %d\n", intarray[i]);
    }

    for (int i = 0; i < n; i++) {
        cityarray[i].all = i + 0.1;
    }

    printf("\ncityarray:\n");
    for (int i = 0; i < n; i++) {
        printf("i: %5f\n", cityarray[i].all);
    }    
    free(array);
    free(intarray);
    free(cityarray);
//	fclose(stdin);
//	fclose(stdout);
	return 0;	
}