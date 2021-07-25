// Tran Binh Minh - A30080

#include <bits/stdc++.h>
using namespace std;

bool SubsetSum(vector<int> A, int i, int T) {
    if (T == 0) return true;
    if (T < 0 || i < 0) return false;
    bool with = SubsetSum(A, i - 1, T - A[i]);
    bool without = SubsetSum(A, i - 1, T);
    return with || without;
}

int main() {
    int n, t;
    vector<int> A;
    cin >> n;
    A.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cin >> t;
    string rs = SubsetSum(A, n - 1, t)? "Can":"Can't";

    cout << rs << endl;
    return 0;
}