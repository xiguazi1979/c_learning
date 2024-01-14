/**
 * @file xuanmei4.c
 * @author your name (you@domain.com)
 * @brief 理解回调函数
 * @version 0.1
 * @date 2022-07-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "xuanmei.h"

#define MIN_NUM 27
#define MAX_NUM 31

ZILIAO caipan = {"DASHI", 99};

ZILIAO database[] =
{
    [MIN_NUM]   {"Cai Yawen", 60},
    [28]        {"Chen Qimeng", 95},
    [29]        {"Dai Tongfei", 70},
    [30]        {"Ding Yiyue", 60},
    [MAX_NUM]   {"Ji Xiaodou", 95}
};
char *name[] = 
{
    [MIN_NUM]   "Cai Yawen",
    [28]        "Chen Qimeng",
    [29]        "Dai Tongfei",
    [30]        "Ding Yiyue",
    [MAX_NUM]   "Ji Xiaodou",
};

int score[] =
{
    [MIN_NUM]   60,
    [28]        95,
    [29]        70,
    [30]        60,
    [MAX_NUM]   95
};

void houmen27(int x, int y)
{
    snprintf(database[27].name, sizeof(database[27].name), "%s", "CAI YILIN 123456789");
    return;
}

void houmen31(int x, int y)
{
    if (x < 30)
    {
        printf("JIA QIAN TAISHAO!");
        return;
    }
    database[31].score += 30;
    return;
}


int main(int argc, char *argv[])
{
    int num = 1;
    int addition = 0;
    int ch;
    char *optstr = "n:a:hp";

    while ((ch = getopt(argc, argv, optstr)) != -1) {
        switch (ch) {
        case 'h':
            printf("-h for help, -p for pee, -n number for xuehao, -a for jiafen.\n");
            return 0;
        case 'p':
            printf("PuPuPu.\n");
            return 0;
        case 'n':
            num = atoi(optarg);
            break;
        case 'a':
            addition = atoi(optarg);
            break;
        default:
            printf("invalid input %c.\n", ch);
            return -1;
        }
    }

    if (num > MAX_NUM || num < MIN_NUM) {
        printf("Invalid number.\n");
        return -1;
    }

    //printf("Num[%d], Name[%s], Score[%d]", num, name[num], score[num] + addition);

    //printf("NUM:%d, NAME:%s, SCORE:%d\n", num, database[num].name, database[num].score + addition);

    if (num == MIN_NUM)
    {
        xuanmei(num, &addition, database, &caipan, houmen27);
    }
    else if (num == MAX_NUM)
    {
        xuanmei(num, &addition, database, &caipan, houmen31);
    }
    else
    {
        xuanmei(num, &addition, database, &caipan, NULL);
    }
    return 0;
}

// void (*hook)(int, int)
void xuanmei(int num, int *addition, ZILIAO *database, ZILIAO *caipan, HOUMEN_FUNC hook)
{
    printf("CAIPAN: %s", caipan->name);
    switch (num)
    {
    case MIN_NUM:
        hook(0, 0);
        break;
    case MAX_NUM:
        hook(50, 0);
        break;
    default:
        break;
    }
    printf("NUM:%d, NAME:%s, SCORE:%d\n", num, database[num].name, database[num].score + *addition);
}