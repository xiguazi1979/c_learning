#include <cstdio>
int grade = 0;
char classA = 'E';
int main()
{
    scanf("%d", &grade);
    
    grade /= 10;
    switch(grade) {
        case 10:
            /* fall through */
        case 9:
            classA = 'A';
            break;
        case 8:
            classA = 'B';
            break;
        case 7:
            classA = 'C';
            break;
        case 6:
            classA = 'D';
            break;
        default:
            classA = 'E';
            break;
    }


    printf("%c\n", classA);
    return 0;
}