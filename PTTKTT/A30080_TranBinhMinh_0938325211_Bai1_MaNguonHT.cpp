#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
vector<int> path;
vector<int> rs;
int N, M;
vector<bool> visited;
bool flag = false;

void HamiltonPath (int u) {
    if (path.size() == N) {
        rs = path;
        flag = true;
        return;
    }

    for (int v : graph[u]) {
        if (!visited[v]) {
            visited[v] = true;
            path.push_back(v);
            HamiltonPath(v);
            if (flag)
                return;
            path.pop_back();
            visited[v] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    graph.assign(N, vector<int>());
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    visited.assign(N, false);
    visited[0] = true;
    path.push_back(0);
    HamiltonPath(0);

    for (int i = 0; i < rs.size(); ++i) {
        cout << rs[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}