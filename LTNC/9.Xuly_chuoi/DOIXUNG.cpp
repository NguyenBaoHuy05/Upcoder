#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s, s1 = " ";
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin, s);
        while ((s.find(s1, 1)) != string::npos) {
            s.erase(s.find(s1), 1);
        }
        for(char &c:s){
            c=toupper(c);
        }
        string s2=s;
        reverse(s2.begin(), s2.end());
        if (s2==s) cout<<1;
        else cout<<0;
        cout<<endl;
    }
    return 0;
}
