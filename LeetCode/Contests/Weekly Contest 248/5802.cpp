//https://leetcode.com/contest/weekly-contest-248/problems/count-good-numbers/

#include <bits/stdc++.h>
using namespace std;

long long int fastpow(long long int a, long long int b, long long int m) {
    if (b == 0)
        return 1;
    long long int res = fastpow(a, b/2, m);
    res = res * res % m;
    if (b % 2 == 1)
        res = res*a % m;
    return res;
}

int main() {
    long long int n;
    cin >> n;
    long long int mod = 1000000007;
    long long int a = n/2 + n%2, b = n/2;
    cout << fastpow(5, a, mod) * fastpow(4, b, mod) % mod;
    return 0;
}