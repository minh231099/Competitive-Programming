#include <iostream>

using namespace std;

int main() {
    int a[26], b[26];
    for (int i = 0; i < 26; i++)
    {
        a[i] = 0; b[i] = 0;
    }

    string s, t;
    cin >> s >> t;

    for (int i = 0; i < max(s.length(), t.length()); i++)
    {
        if (i < s.length())
            a[s[i] - 'a'] ++;
        if (i < t.length())
            b[t[i] - 'a'] ++;
    }
    int rs = 0;
    
    for (int i = 0; i < 26; i++)
        rs += abs(a[i] - b[i]);

    cout << rs << endl;
    return 0;
}