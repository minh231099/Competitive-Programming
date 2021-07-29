// https://leetcode.com/contest/weekly-contest-251/problems/maximum-compatibility-score-sum/

#include <bits/stdc++.h>
using namespace std;

int Count( const vector<int> &a, const vector<int> &b) {
    int rs = 0;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] == b[i]) rs++;
    return rs;
}

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int maxPoint = 0;
        vector<int> per;
        for (int i = 0; i < students.size(); i++)
            per.push_back(i);
        do {
            int same = 0;
            for (int i = 0; i < students.size(); ++i)
                same += Count(students[i], mentors[per[i]]);
            maxPoint = max(same, maxPoint);
        }   while (next_permutation(per.begin(), per.end()));
        return maxPoint;
    }
};

int main() {
    Solution A;
    vector<vector<int> > students = {{1,1, 0},{1, 0, 1},{0, 0, 1}}, mentors = {{1,0,0},{0,0,1},{1,1,0}};
    cout << A.maxCompatibilitySum(students, mentors) << endl;
    return 0;
}