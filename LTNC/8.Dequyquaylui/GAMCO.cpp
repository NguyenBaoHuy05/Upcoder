#include <bits/stdc++.h>
using namespace std;

int n, m, a[100][100], dem = 0, minn = INT_MAX;
bool visited[100][100] = {false}; // Mảng visited để kiểm tra ô đã đi qua

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

bool check(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m && a[i][j] != 0 && !visited[i][j]; 
}

void Try(int x, int y) {
    if (x == n - 1 && y == m - 1) {
        minn = min(minn, dem);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int u = x + dx[i];
        int v = y + dy[i];
        if (check(u, v)) {
            visited[x][y] = true; // Đánh dấu ô đã đi qua
            dem++;
            Try(u, v);
            dem--;
            visited[x][y] = false; // Đánh dấu ô chưa đi qua (quay lui)
        }
    }
}

int main() {
    cin >> n >> m;
    char c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c == '*')
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    a[0][0] = 0;
    Try(0, 0);
    if (minn == INT_MAX) 
        cout << -1 << endl;
    else
        cout << minn;
    return 0;
}
