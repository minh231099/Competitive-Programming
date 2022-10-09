// https://leetcode.com/contest/weekly-contest-251/problems/largest-number-after-mutating-substring/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        vector<int> numbers;
        for (int i = 0; i < num.size(); ++i)
            numbers.push_back(num[i] - '0');
        
        string rs = "";
        bool check = false;
        for (int i = 0; i < numbers.size(); ++i) {
            if (change[numbers[i]] > numbers[i] || ( check && i < numbers.size() - 1  && change[numbers[i]] == numbers[i] && change[numbers[i + 1]] >= numbers[i + 1])) {
                numbers[i] = change[numbers[i]];
                check = true;
            }
            else if (check) {
                break;
            }
        }
        
        for (int i = 0; i < numbers.size(); ++i)
            rs += numbers[i] + '0';

        return rs;
    }
};

int main() {
    Solution A;
    vector<int> change = {0,9,2,3,3,2,5,5,5,5};
    cout << A.maximumNumber("334111", change);

    return 0;
}