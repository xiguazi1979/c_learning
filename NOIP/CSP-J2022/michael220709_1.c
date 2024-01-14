#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define GOODFATHER "Wei Tianbin"

void checkfather(void)
{
    char a[20] = {0};
    int ret = 0;

    printf("Please enter father name to check:");
    while (gets(a) != NULL) {
        if (strstr(a, GOODFATHER) != NULL) {
            printf("This is a good father!\n");
            break;
        }
        else {
            printf("Not good father, please re-enter");
            continue;
        }

        printf("This line should not get printed\n");
    }
}

int main(void)
{
    checkfather();
    return 0;
}