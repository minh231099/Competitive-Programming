// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=422

#include <bits/stdc++.h>
using namespace std;
vector<long long int> path;
int LIS(vector<long long int> &A) {
    int n = A.size();
    vector<long long int> lis, pos;
    path.assign(n, -1);
    long long int j;
    for (int i = 0; i < n; ++i) {
        j = upper_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
        if (j == 0 || A[i] > lis[j - 1])
            if (j == lis.size()) {
                lis.push_back(A[i]);
                pos.push_back(i);
                if (j != 0)
                    path[i] = pos[j - 1];
            }
            else{
                lis[j] = A[i];
                path[i] = -1;
                if (j != 0)
                    path[i] = pos[j - 1];
                pos[j] = i;
            }
    }
    return pos[pos.size() - 1];
}

int main() {
    vector <long long int> A;
    int ai;
    while (cin >> ai)
        A.push_back(ai);
    int mark = LIS(A);
    vector<long long int> ans;
    ans.push_back(A[mark]);
    mark = path[mark];
    while (mark != -1) {
        ans.push_back(A[mark]);
        mark = path[mark];
    }

    cout << ans.size() << "\n-" << endl;
    for (int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] << endl;
    return 0;
}