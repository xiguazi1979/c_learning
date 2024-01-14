#include <cstdio>
#include <set>
using namespace std;

int main()
{
    set<int> s;

    s.insert(1);
    s.insert(3);
    s.insert(5);

    set<int>:: iterator ite;

    ite = s.find(1);
    if(ite == s.end()) {
        puts("not found");
    }
    else {
        puts("found");
    }

    s.erase(3);
    if (s.count(3) != 0) {
        puts("found");
    } 
    else {
        puts("not found");
    } 
    for (ite = s.begin(); ite != s.end(); ite++) {
        printf("%d\n", *ite);
    }

    return 0;
}