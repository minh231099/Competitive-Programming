// https://codeforces.com/contest/1530/problem/C

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> m(n, 0);
        vector<int> ilya(n, 0);

        for (int i = 0; i < n; ++i)
            cin >> m[i];
        for (int i = 0; i < n; ++i)
            cin >> ilya[i];

        sort(m.begin(), m.end());
        sort(ilya.begin(), ilya.end());

        int sumM = 0, sumIlya = 0;
        for (int i = n/4; i < n; ++i) {
            sumM += m[i];
            sumIlya += ilya[i];
        }
        int i = n - n/4, j = n/4 - 1, k = 0, addition = 0;
        while (sumM < sumIlya) {
            sumM += 100;
            if (j >= 0) {
                sumIlya += ilya[j];
                j--;
            }
            addition++;
            if ((n + addition) % 4 == 0) {
                if (n/4 + k < n) {
                    sumM -= m[n/4 + k];
                    k++;
                }
                else
                    addition++;
            }
        }
        cout << addition << endl;
    }
}