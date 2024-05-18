#include<bits/stdc++.h>
using namespace std;
int md[1000][1000];
int n,m,a,b,c,d;
const int dx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
const int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
queue <pair<int,int> > s;
pair<int,int> s2;
int main(){
    cin>>n>>m>>a>>b>>c>>d;
    s.push(s2);
    s.front().first=a;
    s.front().second=b;
    while(!s.empty()){
        s2.first=s.front().first;
        s2.second=s.front().second;
        s.pop();
        for(int i=0;i<8;i++){
            int u=s2.first+dx[i];
            int v=s2.second+dy[i];
            if(u>0 && u<=n && v>0 && v<=m && md[u][v]==0){
                md[u][v]=md[s2.first][s2.second]+1;
                s.push({u,v});
            }
        }
    }
    if(md[c][d]==0) cout<<-1;
    else cout<<md[c][d];
    return 0;
}