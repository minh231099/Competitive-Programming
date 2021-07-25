#include <bits/stdc++.h>

using namespace std;

long long int min( long long int a, long long int b )
{
    if (a < b) return a;
    return b;
}

long long int sumofRange(long long int left, long long int right) {
    long long int range = 0;
    if (left*right < 0)
        range = min(abs(left), abs(right))*2 + max(abs(left), abs(right));
    else
        range = max(abs(left), abs(right));

    return range;   
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long int> x;
    x.assign(n, 0);
    for (int i = 0; i < n; i++){
       cin >> x[i];
    }
    sort(x.begin(), x.end());
    long long int rs = 1e18;

    for (int i = 0; i < n; i++)
    {
        if (i + k > n)
            break;
        rs = min(sumofRange(x[i], x[i + k - 1]), rs); 
    }
    cout << rs << endl;
    return 0;
}