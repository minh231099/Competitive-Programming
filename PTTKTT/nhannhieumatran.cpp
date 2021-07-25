// A30080 Tran Binh Minh

#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
vector<vector<int> > C;

int NhanNhieuMaTran (vector<int> m, int n) {
    C.assign(n, vector<int> (n, INF));
    for (int i = 1; i < n; i++)
        C[i][i] = 0;

    for (int s = 2; s < n; ++s) {
        for (int i = 1; i < n - s + 1; ++i) {
            int j = i + s - 1;
            C[i][j] = INF;
            for (int k = i; k <= j - 1; ++k) {
                int q = C[i][k] + C[k + 1][j] + m[i - 1]*m[k]*m[j];
                if (q < C[i][j])
                    C[i][j] = q;
            }
        }
    }
    return C[1][n - 1];
}

int main() {
    vector<int> m = {1, 2, 3, 4};
    cout << NhanNhieuMaTran(m, 4) << endl;
    return 0;
}