#include<bits/stdc++.h>
using namespace std;

int a[100][100], n, m;
int dx[] = {0, 1};////xuống, phải
int dy[] = {1, 0};////xuống, phải
int maxx = 0, sl = 4;/// sl=4 trong đó có 2 cái là ở khúc đầu bị 0->3, 3->0

bool check(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m && a[i][j] != -1;
}

void Try(int x, int y) {
    if (sl <= 0 && x == n - 1 && y == m - 1) {
        maxx++;
        return;
    }
    for (int i = 0; i < 2; i++) {
        int u = x + dx[i];
        int v = y + dy[i];
        if (check(u, v)) {
            bool kt = false;
            if (a[u][v] != a[x][y]) {
                sl--;
                kt=true;
            }
            Try(u, v);
            if (kt) sl++;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    Try(0, 0);
    if(maxx) cout << maxx;
    else cout<<-1;
    return 0;
}
