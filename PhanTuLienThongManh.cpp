#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> low, num;
vector<bool> found;
stack<int> st;
vector<string> namesByIndex;
map<string, int> names;

int n,m;
int counter;

void dfs (int u) {
    counter++;
    num[u] = low[u] = counter;
    st.push(u);

    for (int v : graph[u]) {
        if (!found[v]) {
            if (num[v] > 0)
                low[u] = min(low[u], num[v]);
            else {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }

    if (num[u] == low[u]) {
        int v;
        do {
            v = st.top();
            st.pop();
            cout << namesByIndex[v - 1];
            found[v] = true;
            if (v != u)
                cout << ", ";
        } while (v != u);
        cout << '\n';
    }
}

void tarjan() {
    counter = 0;
    low.assign(n + 1, 0);
    num.assign(n + 1, 0);
    found.assign(n + 1, false);
    st = stack<int>();

    for (int i = 1; i <= n; ++i)
        if (!num[i])
            dfs(i);
}

int main() {
    int dataset = 1;
    
    while (true) {
        graph.clear();
        low.clear();
        num.clear();
        found.clear();
        names.clear();
        namesByIndex.clear();
        cin >> n >> m;
        graph.assign(n + 1, vector<int>());
        if (n == 0 && m == 0)
            break;
        if (dataset > 1)
            cout << endl;
        int c = 1;
        for (int i = 0; i < m; ++i) {
            string u, v;
            cin >> u >> v;
            if (!names[u]) {
                names[u] = c++;
                namesByIndex.push_back(u);
            }
            if (!names[v]) {
                names[v] = c++;
                namesByIndex.push_back(v);
            }
            graph[names[u]].push_back(names[v]);
        }
        cout << "Calling circles for data set " << dataset++ << ":\n";
        if (m != 0)
            tarjan();
    }
    return 0;
}