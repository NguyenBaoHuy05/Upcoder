#include <iostream>
#include <vector>
using namespace std;

const int N = 9;
bool row[N][N + 1], col[N][N + 1], subgrid[3][3][N + 1];

void printSudoku(int s[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}

bool canPlace(int s[][N], int x, int y, int num) {
    return !row[x][num] && !col[y][num] && !subgrid[x / 3][y / 3][num];
}

void placeNumber(int s[][N], int x, int y, int num) {
    s[x][y] = num;
    row[x][num] = true;
    col[y][num] = true;
    subgrid[x / 3][y / 3][num] = true;
}

void removeNumber(int s[][N], int x, int y, int num) {
    s[x][y] = 0;
    row[x][num] = false;
    col[y][num] = false;
    subgrid[x / 3][y / 3][num] = false;
}
////x hàng y cột
bool solveSudoku(int s[][N], int x, int y) {
    if (x == N) {
        return true; 
    }
    if (y == N) {
        return solveSudoku(s, x + 1, 0);
    }
    if (s[x][y] != 0) {
        return solveSudoku(s, x, y + 1);
    }
    for (int num = 1; num <= N; num++) {
        if (canPlace(s, x, y, num)) {
            placeNumber(s, x, y, num);
            if (solveSudoku(s, x, y + 1)) {
                return true;
            }
            removeNumber(s, x, y, num);
        }
    }
    return false; 
}

int main() {
    int sudoku[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] != 0) {
                placeNumber(sudoku, i, j, sudoku[i][j]);
            }
        }
    }
    if (solveSudoku(sudoku, 0, 0)) {
        printSudoku(sudoku);
    } else {
        cout << -1 << endl;
    }
    return 0;
}
