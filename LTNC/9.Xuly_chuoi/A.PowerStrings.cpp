#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    while(true){
        cin>>a;
        if(a==".") return 0;
        int n=1;
        while(n<=a.size()){
            if(a.size()%n==0){
                string s1=a.substr(0,n),s=a;
                while(true){
                    if(s1==s.substr(0,n)) s.erase(0,n);
                    else break;
                }
                if(s.empty()) {
                    cout<<a.size()/n<<endl;
                    break;
                }
            }
            n++;
            
        }
    }
    return 0;
}