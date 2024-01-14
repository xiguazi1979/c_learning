#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<int, const char*> m;

    m.insert(make_pair(1, "ONE"));
    m.insert(make_pair(10, "TEN"));
    m[100] = "HUNDRED";

    map<int, const char*>::iterator it;
    it = m.find(1);
    printf("Find 1st %s\n", it->second);

    it = m.find(2);
    if (it == m.end()) {
        printf("not found\n");
    }
    else {
        printf("Find 2nd %s\n", it->second);
    }

    printf("Another trial %s", m[10]);

    m.erase(10);

    for (it = m.begin(); it != m.end(); it++) {
        printf("%d: %s\n", it->first, it->second);
    }

    return 0;
}