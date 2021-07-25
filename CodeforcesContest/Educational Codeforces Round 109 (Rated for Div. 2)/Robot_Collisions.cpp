//https://codeforces.com/contest/1525/problem/C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m;
    vector<int> robot;
    vector<int> times;
    vector<char> waysofbot;
    vector<int> robotTurnLeft;
    vector<int> robotTurnRight;

    cin >> n >> m;
    robot.assign(n, 0);
    waysofbot.assign(n, ' ');
    times.assign(n, -1);
    for (int i = 0; i < n; ++i) 
        cin >> robot[i];
    for (int i = 0; i < n; ++i)
        cin >> waysofbot[i];
    int time = 0;
    
    while (true) {
        time++;
        for (int i = 0; i < n; ++i) {
            
        }
    }

    return 0;
}