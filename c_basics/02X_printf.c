#include "stdio.h"
#include "string.h"

#define MAC "ab:8b:cd:a8:40:bc"

int main(void)
{
    int i,j;
    char tmp[64];
    char hex_str[128];
    memset(tmp, 0, sizeof(tmp));
    snprintf(tmp, sizeof(MAC), MAC);
    for(i = 0, j = 0; i < strlen(tmp)/2; i++) {
     if(tmp[i] == ':')
        continue;
     snprintf(hex_str+j, sizeof(hex_str)-j, "%02X", tmp[i]);
     j += 2;
    }

    printf("tmp: %s", tmp);
    return 0;
}
