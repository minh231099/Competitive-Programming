#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<long long int> > &A, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void split(vector<vector<long long int> > &matrix, int n, vector<vector<long long int> > &A, vector<vector<long long int> > &B, vector<vector<long long int> > &C, vector<vector<long long int> > &D) {
    int row = n, col = n;
    row = row/2 + 1*(n%2), col = col/2 + 1*(n%2);
    A.assign(row, vector<long long int>(row, 0)); 
    B.assign(row, vector<long long int>(row, 0));
    C.assign(row, vector<long long int>(row, 0));
    D.assign(row, vector<long long int>(row, 0));
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j) {
            A[i][j] = matrix[i][j];
            B[i][j] = matrix[i][j + row];
            C[i][j] = matrix[i + row][j];
            D[i][j] = matrix[i + row][j + col];
        }
}

void DifferenceMatrix(vector<vector<long long int> > &A, vector<vector<long long int> > &B, vector<vector<long long int> > &C) {
    C.assign(A.size(), vector<long long int>(A.size(), 0));
    for (unsigned int i = 0; i < A.size(); i++)
        for (unsigned int j = 0; j < A.size(); j++)
            C[i][j] = A[i][j] - B[i][j];
}

void SumMatrix(vector<vector<long long int> > &A, vector<vector<long long int> > &B, vector<vector<long long int> > &C) {
    C.assign(A.size(), vector<long long int>(A.size(), 0));
    for (unsigned int i = 0; i < A.size(); i++)
        for (unsigned int j = 0; j < A.size(); j++)
            C[i][j] = A[i][j] + B[i][j];
}


void VolkerStrassen(vector<vector<long long int> > &X, vector<vector<long long int> > &Y, int n, vector<vector<long long int> > &XY) {
    if (n == 1) {
        XY[0][0] = X[0][0] * Y[0][0];
        return;
    }
    vector<vector<long long int> > A, B, C, D, E, F, G, H, temp1, temp2;
    split(X, n, A, B, C, D);
    split(Y, n, E, F, G, H);
    vector<vector<long long int> > P1(n/2, vector<long long int>(n/2, 0)),
                                    P2(n/2, vector<long long int>(n/2, 0)),
                                    P3(n/2, vector<long long int>(n/2, 0)),
                                    P4(n/2, vector<long long int>(n/2, 0)),
                                    P5(n/2, vector<long long int>(n/2, 0)),
                                    P6(n/2, vector<long long int>(n/2, 0)),
                                    P7(n/2, vector<long long int>(n/2, 0));
    DifferenceMatrix(F, H, temp1);
    VolkerStrassen(A, temp1, n/2, P1);
    SumMatrix(A, B, temp1);
    VolkerStrassen(temp1, H, n/2, P2);
    SumMatrix(C, D, temp1);
    VolkerStrassen(temp1, E, n/2, P3);
    DifferenceMatrix(G, E, temp1);
    VolkerStrassen(D, temp1, n/2, P4);
    SumMatrix(A, D, temp1);
    SumMatrix(E, H, temp2);
    VolkerStrassen(temp1, temp2, n/2, P5);
    DifferenceMatrix(B, D, temp1);
    SumMatrix(G, H, temp2);
    VolkerStrassen(temp1, temp2, n/2, P6);
    DifferenceMatrix(A, C, temp1);
    SumMatrix(E, F, temp2);
    VolkerStrassen(temp1, temp2, n/2, P7);

    vector<vector<long long int> > XY1, XY2, XY3, XY4;
    SumMatrix(P5, P4, temp1);
    DifferenceMatrix(temp1, P2, temp2);
    SumMatrix(temp2, P6, XY1);
    SumMatrix(P1, P2, XY2);
    SumMatrix(P3, P4, XY3);
    SumMatrix(P1, P5, temp1);
    DifferenceMatrix(temp1, P3, temp2);
    DifferenceMatrix(temp2, P7, XY4);

    for (int i = 0; i < n/2; ++i)
        for (int j = 0; j < n/2; ++j) {
            XY[i][j] = XY1[i][j];
            XY[i][j + n/2] = XY2[i][j];
            XY[i + n/2][j] = XY3[i][j];
            XY[i + n/2][j + n/2] = XY4[i][j];
        }
    return;
}

int main() {
    vector<vector<long long int> > A, B, AB;
    int n, sz = 2, temp = 1;
    cin >> n;
    while (sz <= n) {
        temp++;
        sz = pow(2,temp);
    }
    A.assign(sz, vector<long long int>(sz, 0));
    B.assign(sz, vector<long long int>(sz, 0));
    AB.assign(sz, vector<long long int>(sz, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> B[i][j];
    
    VolkerStrassen(A, B, sz, AB);
    printMatrix(AB, n);
    return 0;
}