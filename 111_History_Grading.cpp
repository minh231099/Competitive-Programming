// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=47

#include <bits/stdc++.h>

using namespace std;

int LCS(vector<int> &a, vector<int> &b) {
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
    int temp = 0;
    bool flag = true;
    cin >> temp;
    cin.ignore();
    while (flag) {
        int n = temp;
        vector<int> c, r;
        c.assign(n, 0);
        r.assign(n, 0);
        int order;
        for (int i = 0; i < n; ++i) {
            cin >> order;
            order--;
            c[order] = i;
        }
        cin.ignore();
        string s;

        while (flag) {
            getline(cin , s);
            if (s.length() == 0) {
                flag = false;
                break;
            }
            if (s.length() == 1 || s.length() == 2) {
                temp = stoi(s);
                break;
            }
            stringstream ss(s);
            string snum;
            int i = 0;
            while (ss >> snum)
            {
                order = stoi(snum);
                order--;
                r[order] = i++;
            }
            cout << LCS(c, r) << endl;
        }
    }

    return 0;
}