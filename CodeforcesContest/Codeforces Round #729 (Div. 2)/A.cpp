#include <bits/stdc++.h>
using namespace std;



int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int countodd = 0, counteven = 0;
        for (int i = 0; i < 2*n; ++i) {
            int a;
            cin >> a;
            if (a % 2 == 0)
                counteven += 1;
            else
                countodd += 1;
        }

        if (counteven == countodd)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}