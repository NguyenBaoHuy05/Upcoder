#include<iostream>
#include<algorithm>
#include<sstream>
#include<queue>
#include<fstream>
using namespace std;
int main(){
    ifstream in ("inDaoNguoc2.txt");
    string s,s1;
    queue<int> luu;
    int n,max=-1,dem=0;
    stringstream ss,sss;
    while(in>>s){
        reverse(s.begin(),s.end());
        ss<<s<<" ";
        sss<<s<<" ";
        ss>>n;
        if(n>max) {
            max=n;
            while(!luu.empty()){
                luu.pop();
            }
            luu.push(dem);
        }
        else if(n==max){
            luu.push(dem);
        }
        dem++;
    }
    ss<<max;
    ss>>s;
    reverse(s.begin(),s.end());
    in.close();
    ofstream out("outDaoNguoc2.txt");
    out<<s<<endl;
    if(luu.size()>1){
        while(!luu.empty()){
            out<<luu.front()<<" ";
            luu.pop();
        }
    }
    return 0;
}