// A30080 - Tran Binh Minh
#include <bits/stdc++.h>

using namespace std;

int MedianOfFive(int a, int b, int c, int d, int e) {
    return ceil((a+b+c+d+e)/5.0);
}

int Partition(vector<int> A, int mom) {
    int n = A.size() - 1;
    swap(A[mom], A[n]);
    int l = 0;
    for (int i = 0; i <= n - 1; ++i) {
        if (A[i] < A[n]) {
            l++;
            swap(A[l], A[i]);
        }
    }
    swap(A[l + 1], A[n]);
    return l + 1;
}

int MomSelection(vector<int> A, int k, int left, int right) {
    int n = right - left + 1, total = 0;
    if (n == 1)
        return A[right];

    if (n <= 25) {
        vector<int> check;
        for (int i = 0; i < n; i++)
            total += A[i];
        total /= n;

        int Median = 0, minDist = abs(A[0] - total);
        for (int i = 0; i < n; i++)
            if (abs(A[i] - total < minDist)) {
                Median = i;
                minDist = abs(A[i] - total);
            }

        return Median;
    }
    else {
        int m = ceil(n/5.0);
        vector <int> M;
        for (int i = 1; i <= m; ++i) {
            M.push_back(MedianOfFive(A[5*i - 5], A[5*i - 4], A[5*i - 3], A[5*i - 2], A[5*i - 1]));
        }
        int mom = MomSelection(M, ceil(m/2.0), 0, m - 1);
        int r = Partition(A, mom);
        if (k < r)
            return MomSelection(A, k, 0, r-1);
        else if (k > r)
            return MomSelection(A, k - r, r + 1, n-1);
        else
            return mom;
    }
}

int main() {
    vector<int> A = {7, 4, 5, 1, 3, 6, 7, 4, 5, 1, 3, 6, 7, 4, 5, 1, 3, 6, 7, 4, 5, 1, 3, 6, 7, 4, 5, 1, 3, 6};
    cout << A[MomSelection(A, 6, 0, A.size() - 1)] << endl;
    return 0;
}