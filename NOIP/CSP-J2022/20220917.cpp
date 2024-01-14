#include <stdio.h>
#include <string.h>
char base[64];
char table[256];
char str[256];
char ans[256];
void init()
{
    for (int i = 0; i < 26; i++) base[i] = 'A' + i;
    for (int i = 0; i < 26; i++) base[26 + i] = 'a' + i;
    for (int i = 0; i < 10; i++) base[52 + i] = '0' + i;
    base[62] = '+', base[63] = '/';
    for (int i = 0; i < 256; i++) table[i] = 0xff;
    for (int i = 0; i < 64; i++) table[base[i]] = i;
    table['='] = 0;
}
void decode(char *str)
{
    char *ret = ans;
    int i, len = strlen(str);
    for (i = 0; i < len; i += 4) {
        (*ret++) = table[str[i]] << 2 | table[str[i + 1]] >> 4;
        if (str[i + 2] != '=')
            (*ret++) = (table[str[i + 1]] & 0x0f) << 4 | table[str[i + 2]] >> 2;
        if (str[i + 3] != '=')
            (*ret++) = table[str[i + 2]] << 6 | table[str[i + 3]];
    }
}
int main()
{
    init();
    printf("%d\n",(int)table[0]);
    scanf("%s",str);
    decode(str);
    printf("%s\n",ans);
    return 0;
}