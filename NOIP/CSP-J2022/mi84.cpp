#include <iostream>
using namespace std;
int main()
{
    int i,length1, length2;
    string s1, s2;
    s1 = "I have a dream.";
    s2 = "I Have A Dream.";
    length1 = s1.size();
    length2 = s2.size();
    for (i = 0; i < length1; i++)
        if (s1[i] >= 'a' && s1[i] <= 'z')
            s1[i] -= 'a'-'A';
    for (i = 0; i < length2; i++)
        if (s2[i] >= 'a' && s2[i] <= 'z')
            s2[i] -= 'a'-'A';
    if (s1 == s2) {
		cout << "=" << endl;
	}
    else if (s1 > s2) {
		cout << ">" << endl;
	}
    else {
		cout << "<" << endl;
	}
    return 0;
}
