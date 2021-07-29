// https://atcoder.jp/contests/arc124/tasks/arc124_a

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int mult(int a, int b, int m) {
    if (b == 0) return 0;
    int res = mult(a, b/2, m);
    res = (res + res) % m;
    if (b % 2 == 1)
        res = (res + a) % m;
    return res; 
}

int main() {
    int N, K;

    cin >> N >> K;
    vector<pair<char, int> > restric;
    for (int i = 0; i < K; ++i) {
        char c; int k;
        cin >> c >> k;
        restric.push_back(make_pair(c, k));
    }
    int rs = 1, temp = 1;
    for (int i = 0; i < N; ++i) {
        int ways = K, nottake = K - 1;
        for (int j = 0; j < K; ++j) {
            if (restric[j].first == 'L' && i < restric[j].second) {
                ways -= 1;
                nottake -=1;
            }
            if (restric[j].first == 'R' && i > restric[j].second)  {
                ways -= 1;
                nottake = 1;
            }
            if (i == restric[j].second) {
                ways = 1;
                nottake = 1;
                break;
            }
        }
        rs = mult(rs, ways, MOD);
        temp = mult(temp, nottake, MOD);
    }
    cout << rs - temp << endl;
    return 0;
}