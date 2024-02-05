#include <cstdio>
using namespace std;
int main(){
    char str[200];
    scanf("%[^\n]s",str);
    int letter = 0,number = 0,blank = 0,others = 0;
    for (int i = 0; i <= 199 && str[i] != 0; i++){
        if((str[i] >= 'A' && str[i] <='Z') || (str[i] >= 'a' && str[i] <= 'z')){
            letter++;
        }
        else if( str[i] >= '0' && str[i] <= '9') 
            number++;
        else if(str[i] == ' ')                    
            blank++;
        else                                          
            others++;
        
    }
    printf("%d %d %d %d\n",letter,number,blank,others);
    return 0;
}