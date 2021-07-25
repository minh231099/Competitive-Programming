//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2092

#include <bits/stdc++.h>
using namespace std;

int LongestPalindrome(string &a,string &b) {
    vector<vector<int> > res;
    res.assign(a.size() + 1, vector<int>(b.size() + 1, 0));

    for (int i = 1; i <= a.size(); i++)
        for (int j = 1; j <= b.size(); j++)
            if (a[i - 1] == b[j - 1])
                res[i][j] = res[i-1][j-1] + 1;
            else
                res[i][j] = max(res[i-1][j], res[i][j-1]);

    return res[a.size()][b.size()];
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string a, b;
        getline(cin, a);
        if (a.size() == 0) {
            cout << 0 << endl;
            continue;
        }
        b = a;
        reverse(a.begin(), a.end());
        cout << LongestPalindrome(a,b) << endl;
        //cout << b << endl;
    }
    return 0;
}