// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=293

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5, w;
    vector<int> coins = {1, 5, 10, 25, 50};
    vector<long long int> dp;
    dp.assign(30000+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = coins[i - 1]; j <= 30000; j++) {
            dp[j] += dp[j - coins[i -1]];
        }
    }
    while (cin >> w) {
        if (dp[w] == 1)
            cout << "There is only 1 way to produce " << w << " cents change." << endl;
        else
            cout << "There are " << dp[w] << " ways to produce " << w << " cents change." << endl;
    }
    return 0;
}