#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Hàm loại bỏ khoảng trắng không cần thiết từ một chuỗi
string removeExtraSpaces(string str) {
    // Xóa các khoảng trắng thừa ở đầu và cuối chuỗi
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);

    // Loại bỏ khoảng trắng thừa ở giữa chuỗi
    string::iterator new_end = unique(str.begin(), str.end(), [](char a, char b) {
        return a == ' ' && b == ' ';
    });

    // Xóa các khoảng trắng thừa sau khi đã loại bỏ
    str.erase(new_end, str.end());

    // Thay thế các dấu xuống dòng bằng một khoảng trắng
    replace(str.begin(), str.end(), '\n', ' ');

    return str;
}

int main() {
    string input;
    string line;

    cout << "Nhập chuỗi (Nhấn Enter 2 lần để kết thúc nhập):\n";
    // Đọc dữ liệu đầu vào từng dòng cho đến khi nhận được 2 dấu kết thúc nhập (Enter)
    while (getline(cin, line) && !line.empty()) {
        input += line + '\n';
    }

    // Loại bỏ các khoảng trắng không cần thiết từ chuỗi đã nhập
    string result = removeExtraSpaces(input);

    cout << "Chuỗi sau khi loại bỏ khoảng trắng không cần thiết: \n" << result;

    return 0;
}
