#include <iostream>
#include <iomanip>
using namespace std;

struct SinhVien {
    char* hoTen;
    int namSinh;
    float diem[3];
    SinhVien() {
        hoTen = new char[100];
        namSinh = 0;
        diem[0] = diem[1] = diem[2] = 0;
    }
};

istream& operator >>(istream& in, SinhVien& sv) {
    char t[100];
    in.ignore();
    in.getline(t, sizeof(t));
    for (int i = 0; i < sizeof(t); i++) {
        sv.hoTen[i] = t[i];
    }
    cin >> sv.namSinh;
    for (int i = 0; i < 3; i++) {
        cin >> sv.diem[i];
    }
    return in;
}
float DTB(SinhVien sv) {
    return (sv.diem[0] + sv.diem[1] + sv.diem[2]) / 3;
}

ostream& operator <<(ostream& out, SinhVien sv) {
    out << " - " << sv.hoTen << " - " << sv.namSinh << " - " << DTB(sv) << endl;
    return out;
}

int main() {
    cout << setprecision(2) << fixed;
    int n;
    cin >> n;
    SinhVien s[100];
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (DTB(s[i]) < DTB(s[j])) {
                swap(s[i], s[j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout<<i<<s[i];
    }

    return 0;
}
