#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int diff(const string &a, const string &b) {
    int count = 0;
    for (int i = 0; i < a.length(); i++)
        if (a[i] != b[i]) count++;
    return count;
}

int main() {
    vector<string> C;
    ifstream fin("test.txt");
    int N;
    fin >> N;
    for (int i = 0; i < N; ++i) {
        string s;
        fin >> s;
        C.push_back(s);
    }
    int ans = INT_MAX;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int tmp = diff(C[i], C[j]);
            if (ans > tmp) ans = tmp;
        }
    }

    cout << ans << endl;

    return 0;
}