// https://codeforces.com/contest/1530/problem/B

#include <bits/stdc++.h>
using namespace std;
int X[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int Y[8] = {0, -1, 0, 1, -1, 1, -1, 1};
bool check(vector<vector<int> > & table, int i, int j, int h, int w) {
    if (i == 0 || j == 0 || i == h - 1 || j == w - 1) {
        for (int k = 0; k < 8; ++k) {
            int x = i + X[k], y = j + Y[k];
            if ((x >= 0 && x < h) && (y >= 0 && y < w) && table[x][y] == 1)
                return false;
        }
        return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int h, w;
        cin >> h >> w;
        vector<vector<int> > table(h, vector<int> (w, 0));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (check(table, i, j, h, w)) {
                    table[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j)
                cout << table[i][j];
            cout << endl;
        }

        if (t > 0) {
            cout << endl;
        }
    }
    return 0;
}