// https://atcoder.jp/contests/abc210/tasks/abc210_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int badpos;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            badpos = i;
            break;
        }
    }

    if (badpos % 2 == 0)
        cout << "Takahashi" << endl;
    else
        cout << "Aoki" << endl;

    return 0;
}