//https://leetcode.com/contest/weekly-contest-248/problems/build-array-from-permutation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> rs;
        for (int i = 0; i < nums.size(); ++i)
            rs.push_back(nums[nums[i]]);
        return rs;
    }
};

int main() {
    Solution A;
    vector<int> nums = {5, 0, 1, 2, 3, 4};
    vector<int> a = A.buildArray(nums);
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
}