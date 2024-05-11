#include <iostream>
#include <string>
using namespace std;

string tmp, res = "111111111111";
int n, arr[100][100];
int dx[] = {0, 1};
int dy[] = {1, 0};

int binaryToDecimal(string binary) {
    int decimal = 0;
    int base = 1;
    int len = binary.length();
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1')
            decimal += base;
        base *= 2;
    }
    return decimal;
}

bool check(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n ;
}

void Try(int i, int j) {
    if (i == n-1 && j == n-1) {
        res = (res < tmp ? res : tmp);
        return;
    }

    for (int x = 0; x < 2; x++) {
        int u = i + dx[x];
        int v = j + dy[x];
        if (check(u, v)) {
            tmp += arr[u][v] + '0';
            Try(u, v);
            tmp.pop_back(); 
        }
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
            
    tmp += (arr[0][0] + '0');
    Try(0, 0);
    cout << binaryToDecimal(res);
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// int n, a[100][100];
// string maxx="";
// void np(int x,int y,string s){
//     if(x==n-1 && y==n-1){
//         maxx=max(maxx,s);
//         return;
//     }
//     if(y<n-1) np(x,y+1,s+to_string(a[x][y+1]));
//     if(x<n-1) np(x+1,y,s+to_string(a[x+1][y]));
// }
// int main(){
//     string s="";
//     int l=1,h=0;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin>>a[i][j];
//         }
//     }
//     np(0,0,s+to_string(a[0][0]));
//     for(int i=maxx.size()-1;i>=0;i--){
//         if(maxx[i]=='1') h+=l;
//         l*=2;
//     }
//     cout<<h;
//     return 0;
// }