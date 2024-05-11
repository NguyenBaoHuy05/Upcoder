#include <iostream>

using namespace std;

void bd(){

}
int maximalRectangle(char matrix[100][100], int n, int m) {
    if(n == 0 || m == 0) return 0;

    int maxArea = 0;
    int dp[100][100] = {0}; // Khởi tạo mảng dp và lưu chiều dài của hình chữ nhật lớn nhất

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(matrix[i][j] == '1') {
                // Chiều dài của hình chữ nhật tại ô (i, j) được tính dựa trên ô trên và ô bên trái
                dp[i][j] = (j == 0) ? 1 : dp[i][j-1] + 1;
                int width = dp[i][j];
                for(int k = i; k >= 0; --k) {
                    width = min(width, dp[k][j]);
                    maxArea = max(maxArea, width * (i - k + 1));
                }
            }
        }
    }

    return maxArea;
}

int main() {
    int n, m;
    cin >> n >> m;
    char matrix[100][100];

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << maximalRectangle(matrix, n, m) << endl;

    return 0;
}
