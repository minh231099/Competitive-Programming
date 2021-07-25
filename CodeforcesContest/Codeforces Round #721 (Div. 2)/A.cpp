// https://codeforces.com/contest/1527/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, a, k;
    cin >> t;
    while (t--) {
        cin >> a;
        int i = 0;
        while (pow(2, i) <= a) {
            k = pow(2, i);
            i++;
        }
        cout << k - 1 << endl;
    }
    return 0;
}