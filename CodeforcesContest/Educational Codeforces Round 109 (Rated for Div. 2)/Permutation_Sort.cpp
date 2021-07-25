// https://codeforces.com/contest/1525/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n; 
    vector <int> a;
    cin >> t;
    while (t--) {
        cin >> n;
        a.clear();
        a.assign(n, 0);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        int i = 0;
        int flag = true;
        for (int i = 0; i < n - 1; ++i)
            if (a[i] != a[i + 1] - 1) {
                flag = false;
                break;
            }
        
        if (flag)
            cout << 0 << endl;
        else {
            if (a[0] == n && a[n - 1] == 1)
                cout << 3 << endl;
            else if (a[0] == 1 || a[n - 1] == n)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }

    return 0;
}