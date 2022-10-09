// https://leetcode.com/contest/biweekly-contest-56/problems/count-square-sum-triples/

#include <bits/stdc++.h>
using namespace std;

int square (int a) {
    return a*a;
}

class Solution {
public:
    int countTriples(int n) {
        int triples = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    if (square(i) + square(j) == square(k))
                        triples++;
        
        return triples;
    } 
};

int main() {
    Solution A;
    int n;
    cin >> n;

    cout << A.countTriples(n) << endl;

    return 0;
}