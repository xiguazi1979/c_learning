#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(char a,char b){
    return a>b;
}
int stringToint(char *n){
    return (n[3]-'0')+(n[2]-'0')*10+(n[1]-'0')*100+(n[0]-'0')*1000;
}
void inttoString(int n,char *s){
    s[3] = n%10+'0';
    s[2] = (n/10)%10+'0';
    s[1] = (n/100)%10+'0';
    s[0] = (n/1000)%10+'0';
}
int main(){
    char n[4];
    cin>>n;
    int cnt=0;
    while(1){
        sort(n,n+4,cmp);
        int num1 = stringToint(n);
        sort(n,n+4);
        int num2 = stringToint(n);
        int num3 = num1 - num2;
        cnt++;
        if(num3==6174){
            cout<<cnt;
            break;
        }
        inttoString(num3,n);
    }
    return 0;
}
