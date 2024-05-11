#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<long long> > m(n + 1, vector<long long>(n + 1, 0));
    m[0][0]=1;
    for(int last=1;last<=n;last++){
        for(int left=0;left<=n;left++){
            m[last][left] = m[last-1][left];
            if(left>=last){
                m[last][left] += m[last - 1][left - last];
            }
        }
    }
    cout<<m[n][n]-1;
    return 0;
}