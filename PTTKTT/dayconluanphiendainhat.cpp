// A30080 Tran Binh Minh

#include <bits/stdc++.h>
using namespace std;

int LAS(vector<int> &A, int s, int n, bool EvenIndex, int prev) {
    int rs = 0;

    for (int i = s; i <= n; ++i) {
        if (!EvenIndex && prev < A[i])
            rs = max(rs, 1 + LAS(A, i + 1, n, !EvenIndex, A[i]));
        else if (EvenIndex && prev > A[i])
            rs = max(rs, 1 + LAS(A, i + 1, n, !EvenIndex, A[i]));
        else
            rs = max(rs, LAS(A, i + 1, n, EvenIndex, prev));
    }

    return rs;
}

int main() {
    vector<int> A = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 7};
    int n = A.size();
    cout << 2 + LAS(A, 2, n - 1, false, A[1]) << endl;
    return 0;
}