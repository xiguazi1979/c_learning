#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct student {
    char name[64];
    int chinese, math;
    int total;
};
student a[110];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", &a[i].name);
        scanf("%d%d", &a[i].chinese, &a[i].math);
        a[i].total = a[i].chinese + a[i].math;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            if (a[j].total > a[j + 1].total) {
                swap (a[j], a[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s %d %d %d\n", a[i].name, a[i].chinese, a[i].math, a[i].total);
    }
    return 0;
}
