#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

struct Entry {
    int node, cost;
    Entry(int node = 0, int cost = 0) : node(node), cost(cost) {};

    bool operator < (const Entry& other) const {
        return cost > other.cost;
    }
};

vector<int> dist;
vector<vector<Entry> > adj;

int n, m;

void Dijkstra(int s) {
    dist.assign(n, INF);
    priority_queue<Entry> pq;

    pq.push(Entry(s, 0));

    dist[s] = 0;
    while (!pq.empty()) {
        Entry tmp = pq.top();
        pq.pop();

        int u = tmp.node;

        if (tmp.cost != dist[u]) continue;

        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].node;
            int w = adj[u][i].cost;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(Entry(v, dist[v]));
            }
        }
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    n = N;
    m = N - 1;
    adj.assign(n, vector<Entry>());
    int u, v, w = 1;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u - 1].push_back(Entry(v - 1, w));
        adj[v - 1].push_back(Entry(u - 1, w));
    }

    Dijkstra(0);

    int c, d;
    for (int i = 0; i < Q; ++i) {
        cin >> c >> d;
        if ((dist[c - 1] % 2 == 0 && dist[d - 1] % 2 == 0) || (dist[c - 1] % 2 != 0 && dist[d - 1] % 2 != 0))
            cout << "Town" << endl;
        else
            cout << "Road" << endl;
    }

    return 0;
}