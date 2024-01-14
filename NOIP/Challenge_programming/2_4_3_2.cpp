#include <cstdio>
#include <set>

using namespace std;

int main()
{
    set<int> s;

    s.insert(1);
    s.insert(5);
    s.insert(3);

    set<int>::iterator it;

    it = s.find(1);
    if (it == s.end()) {
        printf("not found\n");
    }
    else {
        printf("found\n");
    }

    it = s.find(2);
    if (it == s.end()) {
        printf("not found\n");
    }
    else {
        printf("found\n");
    }

    s.erase(3);
    if (s.count(3) != 0) {
        printf("found\n");
    }
    else {
        printf("not found\n");
    }

    for (it = s.begin(); it != s.end(); it++) {
        printf("%d. ", *it);
    }
    printf("\n");
    return 0;
}