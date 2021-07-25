// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1071

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, g, mw;
    cin >> t;
    while (t--) {
        vector<int> P, W, MW, maxValuePerW;
        cin >> n;
        P.assign(n, 0);
        W.assign(n, 0);
        for (int i = 0; i < n; ++i)
            cin >> P[i] >> W[i];

        cin >> g;
        MW.assign(g, 0);
        int _max = 0;
        for (int i = 0; i < g; ++i) {
            cin >> MW[i];
            _max = max(_max,MW[i]);
        }
        maxValuePerW.assign(_max + 1, 0);
        for (int i = 0; i < n; ++i)
            for (int j = _max; j >= W[i]; --j)
                maxValuePerW[j] = max(maxValuePerW[j], maxValuePerW[j - W[i]] + P[i]);

        int res = 0;

        for (int i = 0; i < g; ++i)
            res += maxValuePerW[MW[i]];
        cout << res << endl;
    }
    return 0;
}