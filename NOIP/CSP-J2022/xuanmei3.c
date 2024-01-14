#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MIN_NUM 27
#define MAX_NUM 31

typedef struct ZILIAO_T {
    char    name[64];
    int     score;
} ZILIAO;

ZILIAO laopo = {"MEIMEI", 99};

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

int main(int argc, char *argv[])
{
    int num = 1;
    int addition = 0;
    int ch;
    char *optstr = "n:a:hp";

    while ((ch = getopt(argc, argv, optstr)) != -1) {
        switch (ch) {
        case 'h':
            printf("-h fpr help, -p for pee, -n number for xuehao, -a for jiafen.\n");
            return 0;
        case 'p':
            printf("PuPuPu.\n");
            return 0;
        case 'n':
            num = atoi(optarg);
            break
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
    printf("NUM:%d, NAME:%s, SCORE:%d\n", num, database[num].name, database[num].score + addition);

    return 0;
}