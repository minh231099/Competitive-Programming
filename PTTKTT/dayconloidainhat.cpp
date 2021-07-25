// A30080 Tran Binh Minh

#include <bits/stdc++.h>
using namespace std;

int LConvexS (vector<int> A, int s, int n, int prev1, int prev2) {
    int rs = 0;
    for (int i = s; i < n; ++i) {
        if (A[i] - prev1 > prev1 - prev2)
            rs = max(rs, 1 + LConvexS(A, i + 1, n, A[i], prev1));
        else
            rs = max(rs, LConvexS(A, i + 1, n, prev1, prev2));
    }

    return rs;
}

int main() {
    vector<int> A = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 7};
    int n = A.size();
    cout << 2 + LConvexS(A, 2, n, A[1], A[0]) << endl;
    return 0;
}