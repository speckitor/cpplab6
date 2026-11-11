#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int *z = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> z[i];
    }

    bool skip;
    int zero_count = 0;
    for (int i = 0; i < n - 1; i += 2) {
        skip = false;
        if (z[i] == 0) {
            zero_count += 1; 
            skip = true;
        }
        if (z[i+1] == 0) {
            zero_count += 1; 
            skip = true;
        }
        if (skip) continue;

        if ((z[i] < 0 && z[i+1] < 0) || (z[i] > 0 && z[i+1] > 0)) {
            z[i] ^= z[i+1];
            z[i+1] ^= z[i];
            z[i] ^= z[i+1];
        } else {
            z[i] *= 2;
            z[i+1] *= 2;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << z[i] << ' ';
    }
    cout << endl;
    cout << zero_count << endl;

    delete[] z;
    return 0;
}
