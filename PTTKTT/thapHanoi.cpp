// A30080 - Tran Binh Minh

#include <bits/stdc++.h>
using namespace std;

void Hanoi(int n, int src, int dst, int tmp)
{
    if (n > 0) {
        Hanoi(n - 1, src, tmp, dst);
        cout << "Move disk " << n << " from " << src << " to " << dst << endl;
        Hanoi(n - 1, tmp, dst, src);
    }
    return;
}

int main() {
    int n;
    cin >> n;
    Hanoi(n, 1, 3, 2);
    return 0;
}