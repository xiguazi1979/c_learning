#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<int, const char*> m;
    m.insert (make_pair(1, "one"));
    m.insert (make_pair(10, "ten"));
    m[100] = "hundred";

    map<int, const char*>::iterator ite;
    ite = m.find(1);
    puts(ite->second);

    ite = m.find(2);
    if(ite == m.end()) {
        puts("not found");
    }
    else {
        puts(ite->second);
    }

    puts(m[10]);

    m.erase(10);

    for (ite = m.begin(); ite != m.end(); ite++) {
        printf("%d:%s\n", ite->first, ite->second);

    }

    return 0;
}