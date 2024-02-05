#include <stdio.h>
#include <stdlib.h>

#define MIN_NUM 27
#define MAX_NUM 31

char *name[] =
{
    [MIN_NUM]   "Cai Yawen",
    [28]        "Chen Qimeng",
    [29]        "Dai Tongfei",
    [30]        "Ding Yiyue",
    [MAX_NUM]   "Ji Xiaodou"
};

int score[] =
{
    [MIN_NUM]   60,
    [28]        95,
    [29]        70,
    [30]        60,
    [MAX_NUM]   95
};

int main(int argc, char *argv[])
{
    int num = 1;

    if (argc != 2) {
        printf("not two parameters.\n");
        return -2;
    }

    num = atoi(argv[1]);

    if (num > MAX_NUM || num < MIN_NUM) {
        printf("Invalid number.\n");
        return -1;
    }

    printf("Num[%d], Name[%s], Score[%d]", num, name[num], score[num]);

    return 0;
}