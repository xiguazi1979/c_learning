#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main()
{
    int n, m, t;
    scanf( "%d", &n );
 
    char *a, *b;
    a    = (char *) malloc( n * sizeof(char) );
    b    = (char *) malloc( n * sizeof(char) );
    scanf( "%s", a );
    scanf( "%d", &m );
    t = n - m + 1;
 
 
    for ( int i = 0; i < t; i++ )
    {
        b[i] = a[m - 1]; m++;
    }
 
    printf( "%s", b );
    free(a);
    free(b);
    return(0);
}
