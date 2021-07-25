#include <bits/stdc++.h>
using namespace std;

int lcs(vector<int> &a, vector<int> &b) {
    vector<vector<int> > res;
    res.assign(a.size() + 1, vector<int>(b.size() + 1, 0));

    if (a[0] == b[0])
        res[1][1]++;

    for (int i = 2; i <= a.size(); i++)
        for (int j = 2; j <= b.size(); j++)
            if ((a[i - 1] == b[j - 1] && res[i-1][j] == res[i - 2][j]))
                res[i][j] = res[i-1][j-1] + 1;
            else
                res[i][j] = max(res[i-1][j], res[i][j-1]);

    return res[a.size()][b.size()];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    a.assign(n, 0);
    b.assign(m, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    cout << lcs(a, b) << endl;
    return 0;
}