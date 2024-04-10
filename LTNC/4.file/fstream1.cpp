#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Đọc dữ liệu từ file input.txt
    ifstream inputFile("input.txt");
    int a, b;
    inputFile >> a >> b;
    inputFile.close();

    // Tính tổng của hai số nguyên
    int total = a + b;
    cout<<total;
    // // Ghi kết quả vào file output.txt


    return 0;
}
