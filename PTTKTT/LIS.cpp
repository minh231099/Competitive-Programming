// Tran Binh Minh - A30080

#include <bits/stdc++.h>

using namespace std;


int LIS(vector<int> A, int i, int n, int prev) {
    if (n - i == 0) return 0;

    int m = LIS(A, i + 1, n, prev);
    if (A[i] > prev || prev == -1)
        m = max(m, 1 + LIS(A, i + 1, n, A[i]));
    return m;
}

int main() {
    vector<int> A = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 3, 2, 3, 8, 4, 6, 2, 7};
    int n = A.size();
    cout << LIS(A, 0, n, -1) << endl;
    return 0;
}