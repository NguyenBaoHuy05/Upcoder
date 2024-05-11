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
/*Của Đức
#include<bits/stdc++.h>
using namespace std;
int x[1000011], n, k, s, kq=0;
void gn() {
    int res=0, d=0;
    for (int i=1;i<=n;i++) {
        if (x[i]==1) res+=i, d++;
        if (d>k) return ;
    }
    if (res==s && d==k) kq++;
}
void ql(int i) {
    for (int j=0;j<=1;j++) {
        x[i]=j;
        if (i==n) gn();
        else ql(i+1);
    }
}
signed main() 
{
    cin >> n >> k >> s;
    ql(1);
    cout << kq;
}
*/