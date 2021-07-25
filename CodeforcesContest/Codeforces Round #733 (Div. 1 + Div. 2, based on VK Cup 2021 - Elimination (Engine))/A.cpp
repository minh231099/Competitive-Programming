// https://codeforces.com/contest/1530/problem/0

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;

    cin >> t;
    while (t--) {
        cin >> n;
        int rs = 0;
        while (n) {
            rs = max(rs, n%10);
            n/=10;
        }

        cout << rs << endl;
    }

    return 0;
}