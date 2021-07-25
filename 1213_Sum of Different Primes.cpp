// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3654

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<bool> isPrime;
    vector<int> primes;
    isPrime.assign(1121, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= 1120; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i*i; j <= 1120; j += i)
                isPrime[j] = false;
        }
    }

    while (true) {
        int n, k;
        cin >> n >> k;
        if (n == 0 && k == 0) break;
        vector<vector<long long int> > dp;
        dp.assign(n + 1, vector<long long int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < primes.size(); ++i)
            for (int j = n; j >= primes[i]; --j)
                for (int x = k; x >= 1; --x)
                    dp[j][x] += dp[j - primes[i]][x - 1];
        
        cout << dp[n][k] << endl;
    }
    return 0;
}