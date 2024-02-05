#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int compare(const void *a, const void *b)
{
    int *p1 = (int *)a;
    int *p2 = (int *)b;
    if(*p1 > *p2){
        return -1;
    }
    else{
        return 1;
    }
}

int main(){
    int a[10] = {5, 6, 4, 3, 7, 0 ,8, 9, 2, 1};
    qsort(a, 10, sizeof(int), compare);
    for (int i = 0; i < 10; i++){
        printf("%d ", a[i]);
    }
    return 0;
}