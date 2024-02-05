#ifndef XUANMEI_H
typedef struct ZILIAO_T {
    char    name[15];
    int     score;
} ZILIAO;
typedef void HOUMEN_FUNC(int, int);
void xuanmei(int num, int *addition, ZILIAO *database, ZILIAO *caipan, HOUMEN_FUNC);
#define XUANMEI_H
#endif /* XUANMEI_H */