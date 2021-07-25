#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;
vector<string> w;
vector<int> lw;

void split(string text) {
    int sw = 0;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            w.push_back(text.substr(sw, i - sw));
            lw.push_back(text.substr(sw, i - sw).size());
            sw = i+1;
        }
    }
    w.push_back(text.substr(sw, text.size()));
}

int printSolution (int p[], int n)
{
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution (p, p[n]-1) + 1;
    cout<<"Line number "<<k<<": From word no. "<<p[n]<<" to "<<n<<endl;
    return k;
}

void processText (vector<int> l, int n, int M)
{
    // For simplicity, 1 extra space is used in all below arrays
 
    // extras[i][j] will have number of extra spaces if words from i
    // to j are put in a single line
    int extras[n+1][n+1];
 
    // lc[i][j] will have cost of a line which has words from
    // i to j
    int lc[n+1][n+1];
 
    // c[i] will have total cost of optimal arrangement of words
    // from 1 to i
    int c[n+1];
 
    // p[] is used to print the solution.
    int p[n+1];
 
    int i, j;
 
    // calculate extra spaces in a single line. The value extra[i][j]
    // indicates extra spaces if words from word number i to j are
    // placed in a single line
    for (i = 1; i <= n; i++)
    {
        extras[i][i] = M - l[i-1];
        for (j = i+1; j <= n; j++)
            extras[i][j] = extras[i][j-1] - l[j-1] - 1;
    }
 
    // Calculate line cost corresponding to the above calculated extra
    // spaces. The value lc[i][j] indicates cost of putting words from
    // word number i to j in a single line
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (extras[i][j] < 0)
                lc[i][j] = INF;
            else if (j == n && extras[i][j] >= 0)
                lc[i][j] = 0;
            else
                lc[i][j] = extras[i][j]*extras[i][j];
        }
    }
 
    // Calculate minimum cost and find minimum cost arrangement.
    // The value c[j] indicates optimized cost to arrange words
    // from word number 1 to j.
    c[0] = 0;
    for (j = 1; j <= n; j++)
    {
        c[j] = INF;
        for (i = 1; i <= j; i++)
        {
            if (c[i-1] != INF && lc[i][j] != INF &&
                           (c[i-1] + lc[i][j] < c[j]))
            {
                c[j] = c[i-1] + lc[i][j];
                p[j] = i;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        cout << p[i] << " ";
    cout << endl;
}
 


int main() {
    string text = "Call me Ishmael. Some years ago, never mind how long precisely, having little or no money in my purse, and nothing particalar to interest me on shore, I thought I would sail about a little and see the watery part of the world.";
    split(text);

    processText(lw, lw.size(), 8);

    return 0;
}