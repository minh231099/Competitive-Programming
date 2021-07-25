#include <bits/stdc++.h>
using namespace std;

int max(long long int a, long long int b)
{
    if (a > b) 
        return a;
    return b;
}

long long int nonFibonacciNth(int N) {
    long long int f[100001];
    f[0] = 0; f[1] = 1;
    int index = 0;
    for (int i = 2; i <= 100001; ++i) 
    {
        f[i] = f[i-1] + f[i-2];
        N -= max(0,f[i] - f[i-1] - 1);
        if (f[i] + N < f[i] + f[i-1])
            return (f[i] + N);
    }
}

int main() {
    int N;
    cin >> N;
    cout << nonFibonacciNth(N) << endl;
    return 0;
}