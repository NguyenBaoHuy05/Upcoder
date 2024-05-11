#include <bits/stdc++.h>
using namespace std;

int n, k, s;
int dem = 0, ds[100] = {0};

void so(int j, int k, int sum) {
    if (k == 0) {
        if (sum == s) {
            dem++;
        }
        return;
    }
    for (int i = j; i < n; i++) {
        if (ds[i] == 0) {
            ds[i] = 1;
            so(i + 1, k - 1, sum + i + 1);
            ds[i] = 0;
        }
    }
}

int main() {
    cin >> n >> k >> s;
    so(0, k, 0);
    cout << dem;
    return 0;
}
