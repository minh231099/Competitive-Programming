// A30080 Tran Binh Minh

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > dp;

int lcs(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();
    dp.assign(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            if (a[i-1] == b[j - 1])
                dp[i][j] = dp[i-1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main() {
    vector<int> a = {1, 4, 2, 3, 4, 6, 5, 6, 10, 7, 8, 11, 9, 24};
    vector<int> b = {2, 24, 4, 6, 7, 8, 10, 12, 11};
    cout << lcs(a, b) << endl;
}