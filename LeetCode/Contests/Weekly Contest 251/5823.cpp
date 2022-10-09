// https://leetcode.com/contest/weekly-contest-251/problems/sum-of-digits-of-string-after-convert/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        int rs = 0;
        for (int i = 0; i < s.length(); ++i) {
            int num = s[i] - 'a' + 1;
            while (num) {
                temp += num%10 + 48;
                num /= 10;
            }
        }
        
        for (int i = 0; i < temp.length(); ++i) {
            rs += temp[i] - 48;
        }

        for (int i = 0; i < k -1; ++i) {
            int t = 0;
            while (rs) {
                t += rs % 10;
                rs /= 10;
            }
            rs = t;
        }
        return rs;
    }
};

int main() {
    Solution A;
    cout << A.getLucky("leetcode", 2);
}