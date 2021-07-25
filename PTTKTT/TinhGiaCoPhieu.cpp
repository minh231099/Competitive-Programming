#include <bits/stdc++.h>

using namespace std;

int findMax(vector<int> A, int left, int right) {
    if (left == right)
        return left;
    int mid = left + (right - left)/2;
    int maxLeft = findMax(A, left, mid);
    int maxRight = findMax(A, mid + 1, right);
    return A[maxLeft] > A[maxRight] ? maxLeft : maxRight;
}

int TinhGiaCoPhieu(vector<int> A, int &buy, int &sell) {
    int _max = 0;
    buy = 0, sell = A.size() - 1;
    for (int i = 0; i < A.size() - 1; i++) {
        int m = findMax(A, i+1, A.size() - 1);
        if (A[m] - A[i] > _max) {
            _max = A[m] - A[i];
            buy = i;
            sell = m;
        }
    }
    return _max;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    int buy, sell;
    int m = TinhGiaCoPhieu(A, buy, sell);
    cout << buy + 1 << " " << sell + 1 << endl;
    return 0;
}