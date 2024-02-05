#include <iostream>
using namespace std;
int main(){
    int t[256];
    string s;
    int i;
    cin>>s;
    for (i = 0;i<256;i++){
        t[i]=0;
    }
    for (i = 0;i<s.length();i++){
        t[s[i]]++;
    }
    for (i = 0;i<s.length();i++){
        if(t[s[i]]==1){
            cout<<s[i]<<endl;
            return 0;
        }
    }
        cout<<"no"<<endl;
        return 0;
}