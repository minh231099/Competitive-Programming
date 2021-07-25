//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=438

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
    int t, ai;
    vector <long long int> A;
    cin >> t;
    cin.ignore();
    string blank;
    int counter = 0;
    getline(cin, blank);
    while (t--) {
        A.clear();
        path.clear();
        if (counter != 0)
            cout << endl;
        while (true) {
            string temp;
            getline(cin, temp);
            if (temp.empty())
                break;
            ai = stoi(temp);
            A.push_back(ai);
        }
        int mark = LIS(A);
        vector<long long int> ans;
        ans.push_back(A[mark]);
        mark = path[mark];
        while (mark != -1) {
            ans.push_back(A[mark]);
            mark = path[mark];
        }

        cout << "Max hits: " << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; --i)
            cout << ans[i] << endl;
        counter++;
    }
    
    
    return 0;
}