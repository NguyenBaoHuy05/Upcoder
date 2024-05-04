#include<iostream>
using namespace std;
int main(){
    int a,b=0,c=0,luu;
    cin>>a;
    int dem=0;
    for(int i=1;i<=a;i++){
        luu=i;
        while(luu%2==0){
            b++;
            luu/=2;
        }
        luu=i;
        while(luu%5==0){
            c++;
            luu/=5;
        }
    }
    cout<<min(b,c);
    return 0;
}
/*Cho một số nguyên n. Hãy đếm xem trong kết quả của số n! có bao nhiêu chữ số 0 liên tiếp tính từ hàng đơn vị (hay bao nhiêu số 0 liên tiếp bên phải).
Dữ liệu nhập:
- Là số nguyên n (1 ≤ n ≤ 1 000)
Dữ liệu xuất:
- Là số lượng chữ số 0 liên tiếp tính từ hàng đơn vị của n!.

Ví dụ:
input
4
output
0        => vì 4! = 24

input
8
output
1        => vì 8! = 5040

input
20
output
4        => vì 20! = 2.432.902.008.176.640.000*/