#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int fastMultipl(long long int a, long long int b, long long int m) {
    int res = 0;
    a %= m;
    b %= m;
    while (b > 0) {
        if (b & 1) res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}

int main() {
    int N;
    vector<long long int> C;
    cin >> N;
    C.assign(N, 0);
    for (int i = 0; i < N; ++i) cin >> C[i];
    sort(C.begin(), C.end());
    long long int rs = 1;
    for (int i = 0; i < N; ++i) {
        rs = fastMultipl(rs, C[i] - i, mod);
    }
    
    cout << rs << endl;

    return 0;
}