// A30080 Tran Binh Minh
#include <bits/stdc++.h>
using namespace std;

int diff (char x, char y) {
    return x != y ? 1 : 0;
}

int main() {
    vector<vector<int> > E;
    string x = "exponential", y = "polynomial";
    E.assign(x.size() + 1, vector<int>(y.size() + 1, 0));
    for (int i = 0; i < x.size() + 1; i++)
        E[0][i] = i;
    for (int j = 0; j < y.size() + 1; j++)
        E[j][0] = j;

    for (int i = 1; i < x.size() + 1; i++) {
        for (int j = 1; j < y.size() + 1; j++) {
            E[i][j] = min(E[i-1][j] + 1, min(E[i][j-1] + 1, E[i-1][j-1] + diff(x[i - 1], y[j - 1])));
        }
    }
    cout << E[x.size()][y.size()] << endl;
    return 0;
}