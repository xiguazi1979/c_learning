#include "stdio.h"
#include "unistd.h"

#define FILE_DIR "/tmp/"
#define FILE_NAME "1.txt"
int main(void)
{
    FILE *fp;
    int ret;

    for (int i = 0; i < 100; i++)
    {
        printf("\nround %d\n", i);
        if (i % 2 == 1)
        {
            ret = remove(FILE_DIR FILE_NAME);
            printf("%s deletion ret%d", FILE_DIR FILE_NAME, ret);
        }
        else
        {
            fp = fopen(FILE_DIR FILE_NAME, "w+");
            printf("%s creation ret%p", FILE_DIR FILE_NAME, fp);
            if(fp != NULL)
            {
                fclose(fp);
            }
        }
        sleep(10);
    }
    return 0;
}
