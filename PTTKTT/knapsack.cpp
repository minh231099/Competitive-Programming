// A30080 Tran Binh Minh

#include <bits/stdc++.h>

using namespace std;

vector<int> dp;
vector<int> weights, profits;
int knapsack (int N, int W) {
    dp.assign(W + 1, 0);

    for (int i = 0; i < N; ++i)
        for (int j = W; j >= weights[i]; j--)
            dp[j] = max(dp[j], dp[j - weights[i]] + profits[i]);
    return dp[W];
}

int main () {
    profits = {30, 20, 16, 9};
    weights = {6, 3, 3, 2};
    int W = 6, N = 4;

    cout << knapsack(N, W) << endl;

    return 0;
}