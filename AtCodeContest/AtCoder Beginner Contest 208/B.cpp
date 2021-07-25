//https://atcoder.jp/contests/abc208/tasks/abc208_b

#include <bits/stdc++.h>
using namespace std;

int factor (int n) {
    int f = 1;
    for (int i = 1; i <= n; ++i)
        f*=i;
    return f;
}

int main() {
    vector <int> factors;
    for (int i = 1; i <= 10; ++i)
        factors.push_back(factor(i));

    int coins = 0, P;
    cin >> P;
    for (int i = factors.size() - 1; i >= 0; --i) {
        int t = P/factors[i];
        coins += t;
        P -= t*factors[i];
    }
    cout << coins << endl;
    return 0;
}