#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    stringstream ss;
    int a;
    cin>>a;
    for(int i=1;i<=a;i++){
        ss<<i;
    }
    string s,s1;
    ss>>s;
    ss<<a;
    s1=to_string(a);
    cout<<s.find(s1)+1;
}
/*Viết các số thập phân 1,2, ... liên tiếp thu được dãy số như sau :

12345678910111213141516171819202122 ...

Viết chương trình tìm vị trí xuất hiện đầu tiên của số N trong dãy trên.

Input

Gồm duy nhất 1 số N, 1 ≤ N ≤ 100,000.

Output

Số duy nhất là vị trí xuất hiện đầu tiên của số N trong dãy.*/