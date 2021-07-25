// A30080 Tran Binh Minh

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > chessBoard;
int N;
int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool Knight(int x, int y, int turn) {
    if (turn == N*N)
        return true;

    for (int i  = 0; i < 8; ++i) {
        int nextX = x + X[i];
        int nextY = y + Y[i];
        if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && chessBoard[nextX][nextY] == -1) {
            chessBoard[nextX][nextY] = turn;
            if (Knight(nextX, nextY, turn + 1) == 1)
                return true;
            chessBoard[nextX][nextY] = -1;
        }
    }
    return false;
}

int main() {
    cin >> N;

    chessBoard.assign(N, vector<int> (N, -1));
    chessBoard[0][0] = 0;
    Knight(0, 0, 1);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << chessBoard[i][j] << "\t";
        cout << endl;
    }
}