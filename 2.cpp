#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int input;
    int *z = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> input;
        *(z + i) = input;
    }

    int qn = 0;
    int *q = new int[n];
    for (int i = 0; i < n; ++i) {
        if (-3 <= *(z + i) && *(z + i) <= 7) {
            if (*(z + i) < 0) {
                *(z + n - 1) ^= *(z + i);
                *(z + i) ^= *(z + n - 1);
                *(z + n - 1) ^= *(z + i);
            }
            break;
        }
        *(q + i) = *(z + i);
        qn += 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << *(z + i) << ' ';
    }
    cout << endl;
    for (int i = 0; i < qn; ++i) {
        cout << *(q + i) << ' ';
    }
    cout << endl;

    delete[] z;
    delete[] q;
    return 0;
}

opa pohalko 2008 burmalda