// https://atcoder.jp/contests/abc208/tasks/abc208_d

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
    int N, M;
    vector<vector<int> > graph;

    cin >> N >> M;
    graph.assign(N, vector<int> (N, INF));
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    vector<vector<vector<int> > > dp;
    dp.assign(N, )

    for (int s = 0; s < N; ++s) {
        for (int t = i + 1; t < N; ++t) {
            for (int k = 1; k <= N; ++k) {

            }
        }
    }
    return 0;
}