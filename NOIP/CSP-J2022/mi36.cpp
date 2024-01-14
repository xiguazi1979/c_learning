#include <cstdio>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    int count = 0;
    for (int i = 2; i < N; i++){
        bool isPrimary = true;
        
        for (int j = 2; j < i; j++){
            if(i % j == 0){
                isPrimary = false;
                break;    
            }            
        }

        if(isPrimary == true) {
            printf("%d\n", i);
            count++;
        }
        
    }
    printf("%d\n", count);
    return 0;
}