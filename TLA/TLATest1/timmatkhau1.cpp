#include <bits/stdc++.h>
using namespace std;

int isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i < sqrt(n) + 1; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    string t;
    cin >> t;
    int maxPrime = 0;
    for (int i = 0; i < t.length(); i++) {
        if (isdigit(t[i]))
        {
            int j = i;
            int sum = 0;
            while (isdigit(t[j]))
            {
                sum = sum * 10 + int(t[j]) - 48;
                if (sum > maxPrime && isPrime(sum))
                    maxPrime = sum;
                j++;
                if (j - i > 4)
                    break;
            }
        }
    }


    cout << maxPrime << endl;

    return 0;
}