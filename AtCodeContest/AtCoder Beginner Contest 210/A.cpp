// https://atcoder.jp/contests/abc210/tasks/abc210_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, X, Y;
    cin >> N >> A >> X >> Y;

    int total = min(N, A) * X + max(0, N - A) * Y;

    cout << total << endl;

    return 0;
}