#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int z[n] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> z[i];
    }

    bool prog = false;

    int step = 0;
    int p_idx = 0, p_len = 0, t_idx = 0, t_len = 0;
    for (int i = 1; i < n; ++i) {
        if (step == 0)
            step = z[i] - z[i-1];

        if (step <= 0 || z[i] - z[i-1] != step) {
            if (t_len > 2 && t_len > p_len) {
                p_idx = t_idx;
                p_len = t_len;
                prog = true;
            }

            t_len = 0;
            t_idx = i;
            step = 0;
        } else if (t_len == 0) {
            t_len = 1;
        }
        t_len += 1;
    }

    if (t_len > 2 && t_len > p_len) {
        p_idx = t_idx;
        p_len = t_len;
        prog = true;
    }

    if (prog) {
        for (int i = p_idx; i < p_idx + p_len; ++i) {
            cout << z[i] << ' ';
        }
        cout << endl;
        cout << p_idx << ' ' << p_len << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
