#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "util_list.h"
#define TEST_PART1		"/usr/bin/"
#define TEST_PASTED_PARTS TEST_PART1 "haha.py"
struct item {
    int id;
    struct item *prev, *next;
};
struct item *list = NULL;

int main(void)
{
    struct item *item, *tmp;
    item = malloc(sizeof(struct item));
    item->id = 1;
    DL_APPEND(list, item);
    item = malloc(sizeof(struct item));
    item->id = 2;
    DL_APPEND(list, item);
    DL_FOREACH(list, tmp) {
        if(tmp) {
            printf("ID: %d\n", tmp->id);
        }
    }

	printf("ALLEN:%sxxx\n", TEST_PASTED_PARTS);

    DL_FOREACH(list, tmp) {
        if(tmp) {
            DL_DELETE(list, tmp);
            free(tmp);
        }
    }

    DL_FOREACH(list, tmp) {
        if(tmp) {
            printf("ID: %d\n", tmp->id);
        }
    }

    printf("header pointer is now %p\n", list);
	return 0;
}
