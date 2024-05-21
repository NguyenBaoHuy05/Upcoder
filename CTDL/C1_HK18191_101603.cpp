#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
#define pb push_back
#define mod 1000000009
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORn(i, a, b) for (int i = (a) - 1; i >= (b); i--)
 
int main() {
    int n, x, k = -1, max = INT_MIN; cin >> n >> x;
    int arr[n]; FOR(i,0,n) cin >> arr[i];
    FOR(i, 0, n) if (arr[i] == x) {
        cout << "Y\n" << i; return 0;
    }
    FOR(i, 0, n) if (arr[i] < x && arr[i] >= max) 
        max = arr[i], k = i;
    (k != -1) ? cout << "N\n" << k : cout << "N\n" << -1;
    return 0;
}