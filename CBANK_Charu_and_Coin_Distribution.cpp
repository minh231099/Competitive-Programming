//https://www.spoj.com/problems/CBANK/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<float> coins = {0.25, 0.5, 1, 2};
    long long int N;
    cin >> N;
    long long int rs = N/2;
    N/=2;
    for (int i = 4; i >= 1; --i)
    {
        rs += N*2;
        N *= 2;
    }
    cout << rs << endl;

    return 0;
}