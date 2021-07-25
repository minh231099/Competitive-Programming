// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1605

#include <bits/stdc++.h>
using namespace std;

vector <int> weights, profit;
vector <int> dp;

int knapsack (int N, int W) {
    dp.assign(W + 1, 0);

    for (int i = 0; i < N; ++i)
        for (int j = W; j >= weights[i]; j--)
            dp[j] = max(dp[j], dp[j - weights[i]] + profit[i]);
    return dp[W];
}

int main() {
    int t, n, w;
    cin >> t;
    cin.ignore();
    while (t--) {
        w = 0;
        weights.clear();
        profit.clear();
        
        string s;
        getline(cin, s);
        stringstream ss(s);
        string snum;
        while (ss >> snum) {
            int inum = stoi(snum);
            weights.push_back(inum);
            profit.push_back(inum);
            w += inum;
        }

        if (w % 2 == 0 && knapsack(weights.size(), w/2) == w/2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}