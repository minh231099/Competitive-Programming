#include <bits/stdc++.h>
using namespace std;

bool isOp(char c) { 
    return (c == '+' || c == 'x');
}

int MinValueOfExpression (string exp) {
    vector<int> numbers;
    vector<int> ops;
    string tmp;

    for (int i = 0; i < exp.length(); i++) {
        if (isOp(exp[i])) {
            ops.push_back(exp[i]);
            numbers.push_back(atoi(tmp.c_str()));
            tmp = "";
        }
        else {
            tmp += exp[i];
        }
    }

    numbers.push_back(atoi(tmp.c_str()));

    int len = numbers.size();
    vector<vector<int> > minValues;
    minValues.assign(len, vector<int> (len, INT_MAX));

    for (int i = 0; i < len; ++i)
        minValues[i][i] = numbers[i];

    for (int L = 2; L <= len; ++L) {
        for (int i = 0; i < len - L + 1; ++i) {
            int j = i + L - 1;
            for (int k = i; k < j; ++k) {
                if (ops[k] == '+')
                    minValues[i][j] = min(minValues[i][k] + minValues[k + 1][j], minValues[i][j]);
                else
                    minValues[i][j] = min(minValues[i][k] * minValues[k + 1][j], minValues[i][j]);
            }
        }
    }

    return minValues[0][len-1];
}

int main () {
    string exp = "3+4x5+6";
    cout << MinValueOfExpression(exp) << endl;
}