#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b; 

    int *pa = &a;
    int *pb = &b;

    if (a >= b) {
        *pb *= 2;
    } else {
        *pa *= 2;
    }

    *pa ^= *pb;
    *pb ^= *pa;
    *pa ^= *pb;

    cout << a << ' ' << b << endl;

    return 0;
}
