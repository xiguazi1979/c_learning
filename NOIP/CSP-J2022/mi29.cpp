#include <cstdio>
using namespace std;
int main()
{
    int num[5];
    int n = 0;
    int number = 0;
    scanf("%d", &n);
    for (int i  = 0; i < 5; i++){
        if(n == 0) break;
        else 
        {
            num[i] = n % 10;
            n = n / 10;
            number++;
        }
    }
    printf("%d\n", number);
    for (int i = number - 1; i >= 0; i--){
        if (i != 0){
            printf("%d ", num[i]);
        }
        else {
            printf("%d\n", num[i]);
        }
    }
    for (int i = 0; i < number; i++){
        printf("%d", num[i]);
    }
    printf("\n");
    return 0;


}