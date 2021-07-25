#include <bits/stdc++.h>
using namespace std;
int INF = INT_MAX;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> divisors;
    vector<int> count;

    for (int i = 2; i <= k; ++i)
        if (k%i == 0)
            divisors.push_back(i);

    count.assign(n+1, 0);

    vector<int> dp;
    dp.assign(n+1, 0);
    dp[0] = 1;
    dp[1] = 0;

    for (int i = 1; i <= divisors.size(); ++i)
        for (int j = divisors[i - 1]; j <= n; ++j)
            if (j % divisors[i - 1] == 0)
                dp[j] = 1;

    int i = divisors.size();
    bool flag = true;
    while (n > 0)
    {
        if (n >= divisors[i-1] && dp[n - divisors[i-1]] == 1)
        {
            count[divisors[i-1]]++;
            n -= divisors[i-1];
        }
        else
        {
            i--;
        }

        if (i == 0)
        {
            flag = false;
            break;
        }
    }

    if (flag)
        for (int i = divisors.size(); i >= 1; --i) {
            if (count[divisors[i - 1]] > 0)
                cout << divisors[i-1] << " " << count[divisors[i - 1]] << endl;
        }     
    else 
        cout << 0 << endl;
    
    return 0;
}