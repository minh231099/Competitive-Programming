//A30080 Tran Binh Minh

#include <bits/stdc++.h>

using namespace std;

vector<string> dictionary = {"it", "was", "the", "best", "of", "time"};

bool dict (string w) {
    for (int i = 0; i < dictionary.size(); ++i)
        if (dictionary[i] == w)
            return true;
    return false;
}

bool isText(string w) {
    vector<bool> dp(w.size() + 1, false);
    for (int i = 1; i < w.size() + 1; ++i) {
        if (dp[i] == false && dict(w.substr(0, i)))
            dp[i] = true;
        if (dp[i] == true)
        {
            if (i == w.size())
                return true;
            
            for (int j = i + 1; j < w.size() + 1; ++j) {
                if (dp[j] == false && dict(w.substr(i, j-i)))
                    dp[j] = true;

                if (dp[j] == true && j == w.size())
                    return true;
            }
        }
    }
    return false;
}

int main() {
    vector<string> w = {"itwasthebestoftime", "JonnyDang"};
    for (int i = 0; i < w.size(); ++i) {
        if (isText(w[i]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}