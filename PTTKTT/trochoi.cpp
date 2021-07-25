// Tran Binh Minh - A30080

#include <bits/stdc++.h>
using namespace std;

int n;
bool TroChoi(vector<int> P0, vector<int> P1) {
    bool flag = true;
    for (int i = 0; i < n; ++i)
        if (P0[i] != n + 1) { flag = false; break; }
    if (flag) return true;

    flag = true;
    for (int i = 0; i < n; ++i)
        if (P1[i] != n + 1) { flag = false; break; }
    if (flag) return false;

    for (int i = 0; i < n; ++i) {
        int steps = 0;
        if (P0[i] != n + 1) {
            if (P0[i] == n) steps = 1;
            else if (P0[i] == n - 1) { 
                if (P1[P0[i]] == i + 1) steps = 2;
                else steps = 1;
            }
            else { 
                if (P1[P0[i]] == i + 1 && P1[P0[i] + 1] == i + 1) continue;
                else if (P1[P0[i]] == i + 1) steps = 2;
                else steps = 1;
            }
            P0[i] += steps;
            if (!TroChoi(P1, P0)) return true;
        }
        P0[i] -= steps;
    }
    return false;
}

int main() {
    cin >> n;
    vector<int> P0(n, 0), P1(n, 0);
    for (int i = 0; i < n; ++i) cin >> P0[i];
    for (int i = 0; i < n; ++i) cin >> P1[i];
    string rs = TroChoi(P0, P1) ? "Good" : "Bad";
    cout << rs << endl;
    return 0;
}