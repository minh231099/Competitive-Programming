// https://leetcode.com/contest/biweekly-contest-56/problems/count-square-sum-triples/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> X = {0, 0, 1, -1}, Y = {1, -1, 0, 0};
        int n = maze.size(), m = maze[0].size();
        vector<vector<int> > dist;
        dist.assign(n, vector<int> (m, INF));

        queue<pair<int, int> > queue;
        dist[entrance[0]][entrance[1]] = 0;
        queue.push(make_pair(entrance[0], entrance[1]));

        while (!queue.empty()) {
            pair<int, int> p = queue.front();
            queue.pop();

            int x  = p.first, y = p.second;
            for (int i = 0; i < 4; ++i) {
                int x1 = x + X[i], y1 = y + Y[i];
                if ((x1 >= 0 && x1 < n) && (y1 >= 0 && y1 < m) && maze[x1][y1] == '.' && dist[x1][y1] == INF) {
                    dist[x1][y1] = dist[x][y] + 1;
                    queue.push(make_pair(x1, y1));
                }
            }
        }
        int rs = INF;
        for (int i = 0; i < n; ++i) {
            if (dist[i][0] != 0)
                rs = min(rs, dist[i][0]);
            if (dist[i][m - 1] != 0)
                rs = min(rs, dist[i][m - 1]);
        }

        for (int i = 0; i < m; ++i) {
            if (dist[0][i] != 0)
                rs = min(rs, dist[0][i]);
            if (dist[n-1][i] != 0)
                rs = min(rs, dist[n - 1][i]);
        }

        if (rs == INF)
            return -1;
        return rs;
    }
};

int main() {
    Solution A;
    vector<vector<char> > maze;
    vector<int> entrance = {8, 4};
    fstream fin ("test.txt");
    int n, m;
    fin >> n >> m;
    maze.assign(n, vector<char> (m, ' '));
    for (int i = 0; i < n; i++) {
        string s;
        fin >> s;
        for (int j = 0; j < m; j++)
            maze[i][j] = s[j];
    }
    cout << A.nearestExit(maze, entrance) << endl;

    return 0;
}