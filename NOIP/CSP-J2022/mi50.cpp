#include <iostream>                                              
using namespace std;
int main(){
    string ch;
    int a[200];
    int b[200];
    int n,i,t,res;
    cin>>ch;
    n=ch.length();
    for (i = 0; i<200;i++) {
        b[i] = 0;
    }
    for (i = 1; i<=n;i++){
        a[i] = ch[i-1]-'0';
        b[i]=b[i-1] + a[i];
    }
    res = b[n];
    t = 0;
    for (i = n;i>0;i--){
        if(a[i]==0){
            t++;
        }
        if(b[i-1]+t<res){
            res = b[i-1] + t;
        }
    }
    cout<<res<<endl;
    return 0;
}