// https://oj.vnoi.info/problem/lis
#include <bits/stdc++.h>
using namespace std;

int LIS(vector<long long int> &A, vector<long long int> &dp) {
    int n = A.size();
    vector<long long int> lis;

    dp.assign(n, 1);
    long long int j;
    for (int i = 0; i < n; ++i) {
        j = upper_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
        dp[i] = j + 1;
        if (j == 0 || A[i] > lis[j - 1])
            if (j == lis.size())
                lis.push_back(A[i]);
            else
                lis[j] = A[i];
    }
    return lis.size();
}

int main() {
    int n;
    cin >> n;
    vector <long long int> A, dp;
    A.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    cout << LIS(A, dp) << endl;
    return 0;
}