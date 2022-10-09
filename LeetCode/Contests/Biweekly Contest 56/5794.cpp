#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int countleft = 0, countright = 0, sumleft = 0, sumright = 0;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '?') {
                if (i < n/2)
                    countleft++;
                else
                    countright++;
            }

            else {
                if (i < n/2)
                    sumleft += num[i] - '0';
                else
                    sumright += num[i] - '0';
            }
        }

        if (abs(sumleft - sumright) > 9*abs(countleft - countright) && abs(sumright - sumleft) > 9*abs(countright - countleft))
            return true;
        else
            return false;
    }
};

int main(){

    return 0;
}