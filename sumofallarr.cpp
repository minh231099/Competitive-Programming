#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector <int> sum;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < sum.size(); ++j)
            sum.push_back(sum[j] + k);
        sum.push_back(k);
    }

    return 0;
}