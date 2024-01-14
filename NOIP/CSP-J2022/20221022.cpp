#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAX_NAME_LEN 128
#define MAX_N 10000
typedef struct city
{
    char name[MAX_NAME_LEN];
    double fir;
    double sec;
    double thi;
    double all;
    double part;

}city;

bool comparsion(city a, city b)
{
    return a.all > b.all;
}
city array[MAX_N];
int main()
{   
    int n;
    char *partmax = NULL;
    freopen("timu1.in", "r", stdin);
	freopen("timu1.out", "w", stdout);

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%s%f%f%f", array[i].name, &array[i].fir, &array[i].sec, &array[i].thi);
        array[i].all = array[i].fir + array[i].sec + array[i].thi;
        array[i].part = array[i].thi / array[i].all;
    }
    sort(array, array + n, comparsion);//arrray.begin要加括号要不然出错
    printf("%s ", array[0].name);
    partmax = array[0].name;
    for (int i = 0; i < 2; i++) {
        if (array[i].part < array[i + 1].part) {
            partmax = array[i + 1].name;
        }
    }
    printf("%s", partmax);
	fclose(stdin);
	fclose(stdout);
    return 0;
}