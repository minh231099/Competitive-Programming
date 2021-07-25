// https://atcoder.jp/contests/abc208/tasks/abc208_a

#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    if (A*6 >= B && B >= A)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}