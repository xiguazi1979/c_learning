#include <bits/stdc++.h>
using namespace std;

int n, putin;
int ans = 1;
#define MAX_N 50
typedef struct ant{
    int num;
    bool way;//way = false左
}ant;
bool comparsion(ant x, ant y) {
    return x.num < y.num;
}
ant a[MAX_N];
int main()
{
    scanf("%d", &n);
    int first, newfirstpos;
    for (int i = 0; i < n; i++) {
        scanf("%d", &putin);
        if (putin > 0) {
            a[i].num = putin;
            a[i].way = true;
        }
        else {
            a[i].num = putin / -1;
            a[i].way = false;
        }
    }
    first = a[0].num;
    sort(a, a + n, comparsion);
    for (int i = 0; i < n; i++) {
        if (a[i].num == first) {
            newfirstpos = i;
            break;
        }
    }
    if ((newfirstpos == 0 && !a[0].way)|| (newfirstpos == n&&a[0].way)) {
        printf("%d", 1);
    }
    else {
        for (int i = 0; i < newfirstpos; i++) {
            if (a[i].way) {
                ans++;
            }
            
        }
        if (ans == 1 && !a[newfirstpos].way) {
            printf("%d", 1);
             return 0;
        }
        for (int i = newfirstpos + 1; i < n; i++) {
            if(!a[i].way) {
                ans++;
            }
        }
        //此时若蚂蚁右侧没有一只相反方向且蚂蚁向右就完蛋了
        printf("%d", ans);
    }
    
    return 0;
}