// Tran Binh Minh - A30080

#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
void PlaceQueens(vector<int> Q, int r) {
    if (r == n) cnt++;
    else {
         for (int i = 0; i < n; ++i) {
            bool flag = true;
            for (int j = 0; j < r; ++j) {
                if (Q[j] == i || Q[j] == i + r - j || Q[j] == i - r + j) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                Q[r] = i;
                PlaceQueens(Q, r + 1);
            }
        }
    }
}

int main() {
    cin >> n;
    vector<int> Q;
    Q.assign(n, 0);
    PlaceQueens(Q, 0);
    cout << cnt << endl;
    return 0;
}