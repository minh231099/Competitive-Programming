// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&category=0&problem=565&mosmsg=Submission+received+with+ID+26403437
#include <bits/stdc++.h>
using namespace std;

vector <int> weights, profit;
vector<vector<int> > dp;

int knapsack (int N, int W) {
    dp.assign(N + 1, vector<int> (W + 1, 0));
    for (int j = 0; j <= W; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weights[i - 1] && dp[i][j] < dp[i - 1][j - weights[i - 1]] + profit[i - 1]) {
                dp[i][j] = dp[i - 1][j - weights[i - 1]] + profit[i - 1];
            }
        }
    }

    return dp[N][W];
}

void trace(int N, int W) {
    int totalWeight = 0, totalProfit = 0;
    vector<int> ans;
    while (N > 0 && W > 0) {
        if (weights[N - 1] <= W && dp[N][W] == dp[N - 1][W - weights[N - 1]] + profit[N - 1]) {
            ans.push_back(profit[N - 1]);
            totalWeight += weights[N - 1];
            totalProfit += profit[N - 1];
            W -= weights[N - 1];
        }
        N--;
    }
    for (int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] << " ";
    cout << "sum:" << totalProfit << endl;
}

int main() {
    int n, w;
    while (cin >> w) {
        cin >> n;
        weights.assign(n, 0);
        profit.assign(n, 0);
        dp.clear();
        for (int i = 0; i < n; i++) {
            cin >> weights[i];
            profit[i] = weights[i];
        }
        knapsack(n, w);
        trace(n, w);
    }
    return 0;
}