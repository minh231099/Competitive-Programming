// A30080 - Tran Binh Minh
#include <bits/stdc++.h>

using namespace std;

int Partition(vector<int> &A, int left, int right) {
    int p = A[right];
    int l = left - 1;
    for (int i = left; i <= right - 1; ++i) {
        if (A[i] < p) {
            l++;
            swap(A[l], A[i]);
        }
    }
    swap(A[l + 1], A[right]);
    return l + 1;
}

void QuickSort(vector<int> &A, int left, int right)
{
    if (left < right) {
        int r = Partition(A, left, right);
        QuickSort(A, left, r - 1);
        QuickSort(A, r + 1, right);
    }
    return;
}

int main()
{
    vector<int> A;
    int n;
    cin >> n;
    A.assign(n, 0);

    for (int i = 0; i < n; ++i)
        cin >> A[i];

    QuickSort(A, 0, n - 1);

    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}