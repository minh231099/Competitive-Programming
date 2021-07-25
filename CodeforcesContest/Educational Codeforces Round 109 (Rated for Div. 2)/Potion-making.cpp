// https://codeforces.com/contest/1525/problem/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int k, e, w;
        cin >> k;
        w = 100 - k;

        while (w*k) {
            if (w > k)
                w %= k;
            else
                k %= w;
        }
        cout << 100/(w+k) << endl;
    }
}