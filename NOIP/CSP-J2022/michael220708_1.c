#include <stdio.h>
#include <stdbool.h>
#include <string.h> 

#define XUANFEI

typedef enum BADGE_T{
    BADGE_NOBODY = 0,
    BADGE_QUEEN,
    BADGE_TAIFEI,
    BADGE_MEINV,
    BADGE_YATOU,
    BADGE_TOTAL = BADGE_YATOU,
} BADGE;
#define GOODGIRL "Rachael"
#define QUEEN   "Mary"
#define TAIFEI  "Lucy"
#define YATOU   "Susan"
#ifdef XUANFEI

BADGE name_to_num(char *name)
{
    BADGE ret = BADGE_NOBODY;
    enum BADGE_T ret2 = BADGE_QUEEN;

    if (strstr(name, QUEEN) != NULL) {
        ret = BADGE_QUEEN;
    }
    else if (strstr(name, TAIFEI) != NULL) {
        ret = BADGE_TAIFEI;
    }
    else if (strstr(name, YATOU) != NULL) {
        ret = BADGE_YATOU;
    }
    else {
        ret = BADGE_NOBODY;
    }

    return ret;
}
#endif
/**
 * a test function
 */
void checkgirl(void)
{
    char a[20] = {0};
    int ret = 0;

    printf("Please enter girl name to check:");
#ifdef CHECKGIRL //宏编译选项
    while (gets(a) != NULL) {
        if (strstr(a, GOODGIRL) != NULL) {
            printf("This is a good girl!\n");
            break;
        }
        else {
            printf("Not good girl, please re-enter:");
            continue;
        }

        printf("This line should not get printed\n");
    }
#endif

#ifdef XUANFEI
    while (gets(a) != NULL) {
        switch (name_to_num(a)) {
        case BADGE_QUEEN:
            printf("%s is QUEEN.\n", a);
            break;
        case BADGE_TAIFEI:
            printf("%s is TAIFEI.\n", a);
            break;
        case BADGE_YATOU:
            printf("%s is YATOU.\n", a);
            break;
        default:
            printf("%s is NOBODY.\n", a);
            break;
        }
        printf("Please enter another girl name to check:");
    }
#endif

}

int main(void)
{
    checkgirl();
    return 0;
}