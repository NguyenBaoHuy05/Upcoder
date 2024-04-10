#include <iostream>
#include <algorithm>
#include<math.h>
#include <vector>
using namespace std;

int main() {
    vector<int> a;
    int i;
    while(cin >> i) {
        a.push_back(i);
    }
    
    a.erase(remove_if(a.begin(), a.end(), [](int i) { return i % 2 != 0; }), a.end());
    a.erase(remove_if(a.begin(), a.end(), [](int i) { return sqrt(i)*sqrt(i)==i; }), a.end());
    sort(a.begin(),a.end(),1);
    for(int x : a) {
        cout << x << " ";
    }
    return 0;
}
