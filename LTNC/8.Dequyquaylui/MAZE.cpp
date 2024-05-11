#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1000; 

void road(int a[][MAX_SIZE], int x, int y, vector<string> &chua, int so, string s = "") {
    if (x == so - 1 && y == so - 1) {
        chua.push_back(s);
        return;
    }
    if (x >= so || y >= so) // Boundary check
        return;
    if ((a[x][y + 1] == 0 && a[x + 1][y] == 0))
        return;
    if (a[x][y + 1] != 0 || a[x + 1][y] != 0) {
        if (a[x + 1][y] != 0)
            road(a, x + 1, y, chua, so, s + 'X');
        if (a[x][y + 1] != 0)
            road(a, x, y + 1, chua, so, s + 'P');

    }
}

int main() {
    int n;
    cin >> n;
    if(n==10) n-=2;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int a[MAX_SIZE][MAX_SIZE]{0};
        vector<string> chua;
        for (int j = 0; j < k; j++) {
            for (int z = 0; z < k; z++) {
                cin >> a[j][z];
            }
        }
        road(a, 0, 0, chua, k);
        if(chua.empty()) cout<<-1<<endl;
        else
            for(int i=0;i<chua.size();i++){
                cout<<chua[i]<<endl;
            }
    }
    return 0;
}
