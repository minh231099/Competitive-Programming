#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream fout("test.txt");
    srand(time(NULL));
    int n = rand() % 20 + 1;
    fout << n << endl;
    for (int i = 0; i < n; ++i)
        fout << rand()%20 + 1 << ", ";
}