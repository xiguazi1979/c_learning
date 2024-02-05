#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;
#define ha 233333

struct zip
{
	vector <int> w[ha + 5];
	void ins(int x)
	{
		w[x%ha].push_back(x);
	}
	void ask(int x)
	{
		for (vector<int>::iterator i = w[x % ha].begin(); i != w[x % ha].end(); i++) {
			if (*i == x) goto done;
		}
		puts("NO");
		return;
		
		done:
		puts("Yes");
	}
};
zip B;

int main()
{
	B.ask(5);
	B.ins(5);
	B.ask(5);
	
	B.ask(ha + 5);
	B.ins(ha + 5);
	B.ask(ha + 5);
	return 0;	
}
