#include<iostream>
using namespace std;
struct ql{
    string a,b;
    long long c;
};
int main(){
    ql s[100];
    long long dem=0,max=-10000000000,vt;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        getline(cin,s[i].a,'-');
        getline(cin,s[i].b,'-');
        cin>>s[i].c;
        if(s[i].c>=0) {
            dem++;
            if(max<s[i].c){
                max=s[i].c;
                vt=i;
            }
        }
    }
    cout<<dem;
    cout<<s[vt].a<<" - "<<s[vt].b<<" - "<<s[vt].c;
    return 0;
}
/*
Xây dựng cấu trúc (hoặc lớp) Khách hàng với những thông tin mô tả như sau:
+ Mã khách hàng: chuỗi có độ dài cố định 3 kí tự.
+ Tên khách hàng: chuỗi có độ dài tối đa 25 kí tự.
+ Số tiền đang có: số nguyên. Có thể âm, dương hoặc = 0
Yêu cầu:
Đọc thông tin khách hàng theo cú pháp như sau:
Dòng 1: Số lượng khách hàng
N dòng tiếp theo là thông tin của mỗi khách hàng theo định dạng Mã khách hàng - Tên khách hàng - Số tiền đang có.
Xuất thông tin khách hàng với cú pháp như sau:
Dòng 1: Số lượng khách hàng hợp lệ (dựa vào số tiền đang có >= 0).
Dòng 2: Thông tin khách hàng có số tiền đang có lớn nhất.
Ví dụ:
input
5
100 - Tran Cong Bang - 15000000
200 - Dang Thanh Hai - -75950000
300 - Truong Gia Binh - 90000000
400 - Le Hien Linh - 0
500 - Ly Tieu Long - -300000000

output
3
300 - Truong Gia Binh - 90000000

Giải thích: Khách hàng có mã 200, tên Dang Thanh Hai và khách hàng có mã 500, tên Ly Tieu Long số tiền đang có âm.
*/