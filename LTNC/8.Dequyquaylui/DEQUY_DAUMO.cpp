#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_M = 15;
const int MAX_N = 15;

int M, N;
int grid[MAX_M][MAX_N];
int dp[MAX_M][MAX_N];

void findMaxOil() {
    dp[0][0] = grid[0][0];

    // Fill the first row
    for (int j = 1; j < N; ++j)
        dp[0][j] = dp[0][j - 1] + grid[0][j];

    // Fill the first column
    for (int i = 1; i < M; ++i)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    // Fill the remaining cells
    for (int i = 1; i < M; ++i) {
        for (int j = 1; j < N; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
}

void printPath() {
    int i = M - 1, j = N - 1;
    vector<pair<int, int>> path;
    path.push_back({i, j});

    while (i > 0 || j > 0) {
        if (i == 0)
            --j;
        else if (j == 0)
            --i;
        else if (dp[i - 1][j] > dp[i][j - 1])
            --i;
        else
            --j;
        path.push_back({i, j});
    }

    for (auto it = path.rbegin(); it != path.rend(); ++it)
        cout << it->first + 1 << " " << it->second + 1 << endl;
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j];

    findMaxOil();
    cout << dp[M - 1][N - 1] << endl;
    printPath();

    return 0;
}
