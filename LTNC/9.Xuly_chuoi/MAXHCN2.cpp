#include<bits/stdc++.h>
using namespace std;
int xa,ya,xc,yc;

int maximalRectangle(char matrix[1000][1000], int n, int m, vector<char> kt) {
    if(n == 0 || m == 0) return 0;

    int maxArea = 0;
    for(int k=0;k<kt.size();k++){
        int dp[100][100] = {0}; // Khởi tạo mảng dp và lưu chiều dài của hình chữ nhật lớn nhất

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(matrix[i][j] == kt[k]) {
                    // Chiều dài của hình chữ nhật tại ô (i, j) được tính dựa trên ô trên và ô bên trái
                    dp[i][j] = (j == 0) ? 1 : dp[i][j-1] + 1;
                    int width = dp[i][j];
                    for(int k = i; k >= 0; --k) {
                        width = min(width, dp[k][j]);
                        if (maxArea < width * (i - k + 1)) {
                            xc = i+1;
                            yc = j + 1;
                            ya = j - min(width, dp[k][j]) + 1+1;
                            xa = k+1;
                        }  
                        maxArea = max(maxArea, width * (i - k + 1));

                    }
                }
            }
        }
    }

    return maxArea;
}

int main() {
    ifstream cin("CNMAX.INP");
    ofstream cout("CNMAX.OUT");
    int m,i=0;
    cin >> m;
    char matrix[1000][1000],n;
    vector<char> kt;

    while(cin>>n) {
        matrix[i][0]=n;
        for(int j = 1; j < m; ++j) {
            cin >> matrix[i][j];
            bool dos=true;
            for(int k=0;k<kt.size();k++){
                if(matrix[i][j]==kt[k]) dos=false;
            }
            if(dos) kt.push_back(matrix[i][j]);
        }
        i++;
    }
    
    cout << maximalRectangle(matrix, i, m, kt) << endl;
    cout << xa << " " << ya<<endl;
    cout << xc << " " << yc<<endl; 
    return 0;
}
/*
5
bcccd
accbd
0123d
dddac
*/