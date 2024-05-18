#include <iostream>
#include <string>
using namespace std;

int main() {
    int m, s;
    cin >> m >> s;
    if (s == 0) {
        if (m == 1) cout << "0" << endl<<"0";
        else cout << "-1" << endl;
        return 0;
    }
    string smallest, largest;
    int sum = s;
    for (int i = 0; i < m; ++i) {
        int digit = min(9, sum);
        largest += char('0' + digit);
        sum -= digit;
    }
    if (sum > 0) {
        cout << "-1" << endl;
        return 0;
    }
    for (int i = m - 1; i >= 0; --i) {
        smallest += largest[i];
    }
    if (smallest[0] == '0') {
        for (int i = 1; i < m; ++i) {
            if (smallest[i] != '0') {
                ++smallest[0];
                --smallest[i];
                break;
            }
        }
    }
    cout << smallest << endl << largest << endl;
    return 0;
}
