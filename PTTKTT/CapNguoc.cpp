// A30080 Trần Bình Minh

#include <bits/stdc++.h>
using namespace std;

int MAX = 1e6 + 1;
long long int rs = 0;
vector<int> a, b;

void CapNguoc (int l, int r) {
    if (l == r)
        return;
    
    int mid = l + (r - l)/2;
    int i = l, j = mid + 1, k = l;
    CapNguoc(l, mid);
    CapNguoc(mid + 1, r);

    while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else {
            b[k++] = a[j++];
            rs ++;
        }
    }

    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= r) {
        b[k++] = a[j++];
    }
    for (int i = l; i <= r; ++i) {
        a[i] = b[i];
    }
}

int main() {
    int n;
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    CapNguoc(0, n);
    cout << rs << endl;
    return 0;
}