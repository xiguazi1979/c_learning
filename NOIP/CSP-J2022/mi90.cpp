#include <iostream>
 
using namespace std;
 
const int MAXN = 5000;
int n, m;
struct segment { int a, b; } A[MAXN];
 
void sort() // ≈≈–Ú
{
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j++)
            if (A[j -1].a > A[j].a)
            {
                segment t = A[j];
                A[j] = A[j - 1];
                A[j - 1] = t;
            }
}
 
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> A[i].a >> A[i].b;
    sort();
    int p = 1;
    for (int i = 1; i < n; i++)
        if (A[i].b > A[i - 1].b);
            A[p++] = A[i];
    n = p;
    int ans = 0, r = 0;
    int q = 0;
    while (r < m)
    {
        while (¢‹)
            q++;
        ¢›;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
