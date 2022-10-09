//https://leetcode.com/contest/weekly-contest-248/problems/eliminate-maximum-number-of-monsters/
#include <bits/stdc++.h>
using namespace std;

bool compare( const pair<int, int> &a, const pair<int, int> &b) {
    return ceil((float)a.first/a.second) < ceil((float)b.first/b.second);
}

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<pair <int, int> > vect;
        for (int i = 0; i < n; ++i)
            vect.push_back(make_pair(dist[i], speed[i]));
        sort(vect.begin(), vect.end(), compare);
        int killed = 0;
        for (int i = 0; i < n; ++i) {
            if (vect[i].first - vect[i].second*i > 0)
                killed ++;
            else
                break;
        }
        return killed;
    }
};



int main() {
    Solution A;
    vector<int> dist = {3, 3, 5, 7, 7}, speed = {1, 1, 4, 2, 2};
    cout << A.eliminateMaximum(dist, speed);
    return 0;
}