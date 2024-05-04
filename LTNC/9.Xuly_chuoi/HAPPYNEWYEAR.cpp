#include <iostream>
#include <string>
using namespace std;

int main() {
    long long n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        long long count = 0;
        size_t pos = 0;
        while ((pos = s.find("Happy new year 2017", pos)) != string::npos) {
            count++;
            pos += 19; // Di chuyển tới vị trí kế tiếp sau kết quả trùng khớp
        }
        cout << count << endl;
    }
    return 0;
}