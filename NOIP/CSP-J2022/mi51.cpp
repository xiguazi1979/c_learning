#include <iostream>
 
using namespace std;
 
int main ()
{
    int  var1;
    int var2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr1 = &var1;
    cout <<"var1的地址是 ";
    cout << &var1 << endl;
    cout << "var2[0]的地址是";
    cout << var2[0] << endl;
    cout << &var2[0] << endl;
    cout << var2 << endl;
    cout << var2+3 << endl;
    cout << *(var2 + 3) << endl;
    cout << ptr1 << endl;


    return 0;
}