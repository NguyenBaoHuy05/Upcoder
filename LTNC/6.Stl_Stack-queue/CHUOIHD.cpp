#include <iostream>
#include <stack>
using namespace std;

int main() {
    int a, so = 0;
    cin >> a;
    string s[100];
    for (int i = 0; i < a; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < a; i++) {
            stack<char> sl;
            for (int j = 0; j < s[i].size(); j++) {
                if (!sl.empty() && s[i][j] == sl.top())
                    sl.pop();
                else
                    sl.push(s[i][j]);
            }
            if (!sl.empty()) {
                s[i]="0";
            }
            else so++;
    }
    cout << so<<endl;
    for(int i=0;i<a;i++){
        if(s[i]!="0") cout<<s[i]<<endl;
    }
    return 0;
}