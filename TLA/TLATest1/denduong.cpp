#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long int n, L;
    cin >> n >> L;
    vector<int> a;
    a.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    double rs = 0;
    for (int i = 0; i < n -1; ++i)
    {
        rs = max(rs, (a[i+1] - a[i])/2.0);
    }
    cout << fixed << setprecision(2) << rs << endl;
    

    return 0;
}