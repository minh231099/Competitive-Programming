https://atcoder.jp/contests/abc208/tasks/abc208_c

#include <bits/stdc++.h>
using namespace std;

int compare(const pair<int, int> &A, const pair<int, int> &B) {
    return A.second < B.second;
}

int main() {
    int N;
    long long int K;
    vector<pair <int, int> > citizens;

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int ID;
        cin >> ID;
        citizens.push_back(make_pair(i, ID));
    }

    sort(citizens.begin(), citizens.end(), compare);

    long long int same = K/N;
    K -= same*N;
    vector<long long int> rs;
    rs.assign(N, same);
    int i = 0;
    while (K > 0) {
        rs[citizens[i].first] += 1;
        K -= 1;
        i++;
    }
    for (int i = 0; i < N; ++i)
        cout << rs[i] << endl;
    return 0;
}