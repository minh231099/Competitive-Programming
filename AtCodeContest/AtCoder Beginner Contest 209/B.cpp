#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    int total = 0;
    cin >> N >> X;

    for (int i = 1; i <= N; ++i) {
        int t;
        cin >> t;
        if (i%2)
            total += t;
        else
            total += t - 1;
    }

    if (total <= X)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}