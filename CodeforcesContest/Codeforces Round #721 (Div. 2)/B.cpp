// https://codeforces.com/contest/1527/problem/B1

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;
    bool flag = true;
    int cntz = 0;
    vector<int> indexz;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0')
            indexz.push_back(i);
        if (s[i] != s[n - i - 1]) {
            flag = false;
            break;
        }
    }

    

    return 0;
}