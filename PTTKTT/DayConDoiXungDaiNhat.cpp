// A30080 Tran Binh Minh

#include <bits/stdc++.h>
using namespace std;

int LPS(vector<int> A, int s, int n) {
    if (s == n)
        return 1;
    if (A[s] == A[n] && s + 1 == n)
        return 2;
    if (A[s] == A[n])
        return LPS(A, s + 1, n - 1) + 2;
    return max(LPS(A, s + 1, n), LPS(A, s, n - 1));
}

int main() {
    vector<int> A = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, 2, 7};
    
    cout << LPS(A, 0, A.size() - 1) << endl;
    return 0;
}