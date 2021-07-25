// https://www.spoj.com/problems/PARTY/

#include <bits/stdc++.h>
using namespace std;

vector <int> weights, profit;
vector< int > dp;

int knapsack (int N, int W) {
    dp.assign(W + 1, 0);

    for (int i = 0; i < N; ++i) {
        for (int j = W; j >= weights[i]; j--) {
            if (dp[j] < dp[j - weights[i]] + profit[i])
                dp[j] = dp[j - weights[i]] + profit[i];
        }
    }
    return dp[W];
}

void trace (int N, int W) {
    int i = W;
    while (true) {
        if (dp[i] == dp[i-1])
            i--;
        else
            break;
    }
    cout << i << " " << dp[i] << endl;

}

int main() {
    int n, w;
    while (true) {
        cin >> w >> n;
        if (w == 0 && n == 0) break;
        weights.assign(n, 0);
        profit.assign(n, 0);
        dp.clear();
        for (int i = 0; i < n; i++) {
            cin >> weights[i] >> profit[i];
        }
        knapsack(n, w);
        trace(n, w);
        string space;
        cin.ignore();
        getline(cin, space);
    }

    return 0;
}