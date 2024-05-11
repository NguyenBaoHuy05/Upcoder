#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int getNum(vector<string> v){
    int max=0,dem=1;
    for (int i=1;i<v.size();i++){
        if (v[i].length()==v[i-1].length()){
            dem++;
        }
        else {
            if (max<dem)   {max=dem;}
            dem=1;
        }
    }
    if (max<dem)    max=dem;
    return max;
}
int main(){
    int n;
    cin>>n;
    cin.ignore();
    for (int i=0;i<n;i++){
        vector<string> v;
        string s;
        getline(cin,s);
        for (int i=0;i<s.length();i++){
            if (!isalpha(s[i])) s[i]=' ';
        }
        stringstream ss(s);
        string word;
        while(ss>>word){
            v.push_back(word);
        }
        cout<<getNum(v)<<endl;
    }
}