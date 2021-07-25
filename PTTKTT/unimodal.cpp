// A30080 Trần Bình Minh
#include <bits/stdc++.h>

using namespace std;

int Unimodal (vector<long long int> &A, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left)/2;
        if (A[mid] > A[mid + 1] && A[mid] > A[mid - 1])
            return mid;
        else if (A[mid] > A[mid + 1] && A[mid] < A[mid - 1])
            return Unimodal(A, left, mid - 1);
        else
            return Unimodal(A, mid + 1, right);
    }
    return -1;
}

int main () {
    int n;
    vector<long long int> A;
    cin >> n;
    A.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    cout << Unimodal(A, 0, A.size() - 1) + 1 << endl;
    return 0;
}