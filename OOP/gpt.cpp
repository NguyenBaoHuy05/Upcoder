#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include <thread>
#include <windows.h>

using namespace std;
void time(int n) { this_thread::sleep_for(chrono::milliseconds(n)); } /// hàm dụng thời gian
void COLOR(int color)                                                 /// hàm tạo màu sắc
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

class Board
{
public:
    enum class Cell
    {
        None,
        X,
        O,
        Draw
    }; /// class giá trị tại 1 cell
private:
    vector<Cell> board;
    Cell valueCell;
public:
    Board() : board(10, Cell::None), valueCell(Cell::X){}

    /// Draw bang
    void drawBoard(int n = 1)
    {
        if (n)
        {
            for (int i = 1; i <= 9; i++)
            {
                COLOR(7);
                if (i == 1)
                    cout << "\t\t\t-------------\n\t\t\t";
                if (i % 3 == 1)
                    cout << "| ";
                if (board[i] == Cell::None)
                {
                    COLOR(8);
                    cout << i;
                }
                else if (board[i] == Cell::X)
                {
                    COLOR(3);
                    cout << "X";
                }
                else
                {
                    COLOR(14);
                    cout << "O";
                }
                if (i % 3 != 0)
                {
                    COLOR(7);
                    cout << " | ";
                }
                else
                {
                    COLOR(7);
                    cout << " | \n\t\t\t-------------\n\t\t\t";
                }
            }
            COLOR(6);
            cout << endl;
        }
        else
            for (int i = 1; i <= 9; i++)
            {
                COLOR(7);
                if (i == 1)
                    cout << "\t\t\t-------------\n\t\t\t";
                if (i % 3 == 1)
                    cout << "| ";
                cout << i;
                if (i % 3 != 0)
                    cout << " | ";
                else
                    cout << " | \n\t\t\t-------------\n\t\t\t";
            }
        cout << endl;
    }

    /// kiểm tra nước đi có hợp lệ không
    bool makeMove(int number)
    {
        if (number < 1 || number > 9 || board[number] != Cell::None)
            return false;
        board[number] = valueCell;
        valueCell = (valueCell == Cell::X) ? Cell::O : Cell::X;
        return true;
    }
    /// kiểm tra ai chiến thắng
    Cell checkWinner()
    {
        /// kiểm tra dòng
        for (int i = 1; i <= 3; i++)
        {
            if (board[i * 3 - 2] != Cell::None && board[i * 3 - 2] == board[i * 3 - 1] && board[i * 3 - 2] == board[i * 3])
                return board[i * 3 - 2];
        }
        /// kiểm tra cột 
        for (int i = 1; i <= 3; i++)
        {
            if (board[i] != Cell::None && board[i] == board[i + 3] && board[i] == board[i + 6])
                return board[i];
        }
        /// kiểm tra đường chéo 
        if (board[1] != Cell::None && board[1] == board[5] && board[1] == board[9])
            return board[1];
        if (board[3] != Cell::None && board[3] == board[5] && board[3] == board[7])
            return board[3];
       /// Kiểm tra xem có đang hòa hay không 
        bool ktDraw = true;
        for (int i = 1; i <= 9; i++)
        {
            if (board[i] == Cell::None)
            {
                ktDraw = false;
                break;
            }
        }
        if (ktDraw)
            return Cell::Draw;
        /// kiểm tra không phải là chiến thắng 
        return Cell::None;
    }
    /// Kiem tra co ket thuc game ko
    bool ktFinished() { return checkWinner() != Cell::None; }
    /// Lay gia tri hien tai, dang X hay O
    Cell getvalueCell() { return valueCell; }
    /// Qua tai []
    Cell &operator[](int i) { return board[i]; }
};

class Player
{
protected:
    int stt;/// kt số thứ tự của người với máy
    bool isComputer;
public:
    /// ham thuan ao move quan li nuoc di
    Player(int _stt=0):stt(_stt){}
    bool NotHuman(){return isComputer;}
    virtual void Move(Board &boa) = 0;
};

class ComputerPlayer : public Player
{
public:
    ComputerPlayer(int _stt = 0) : Player(_stt){isComputer=true;}
    int Random_number(Board &board){
        int chose;
        vector<int> ableMoves;
        /// Khởi tạo Vector chứa các ô đi được
        for (int i = 1; i <= 9; i++)
        {
            if (board[i] == Board::Cell::None)
            {
                ableMoves.push_back(i);
            }
        }
        /// Random nước đi
        int randomIndex = rand() % ableMoves.size();
        board.makeMove(ableMoves[randomIndex]);
        chose = ableMoves[randomIndex];    
        return chose;    
    }
    // move cua may
    void Move(Board &board)
    {
        int number_chose=Random_number(board);
        ////Xuất ra màn hình
        COLOR(11);
        cout << "May ";
        if (stt)
            cout << stt << " ";
        cout << "choi: " << number_chose << endl
             << endl;
        board.drawBoard();
    }
};

class HumanPlayer : public Player
{
private:
    string so;
public:
    HumanPlayer(int _stt = 0) : Player(_stt){isComputer=false;}

    void Exception_Handling(Board &boa){
                /// Nhập số và kiểm tra tính hợp lệ của số và trình bày bảng
        while (true)
        {
            cin >> so;
            cout << endl;
            while (true)
            {
                /// kiểm tra dữ liệu có phải là chữ không 
                bool isDigit = true;
                for (int i = 0; i <so.size(); i++)
                    if (isalpha(so[i]))
                    {
                        isDigit = false;
                        break;
                    }
                if (isDigit)
                    break;
                else
                {
                    cout << "Khong chap nhan chu! Hay nhap so: ";
                    cin >> so;
                    cout << endl;
                }
            }
            stringstream ss;
            ss<<so;
            int number;
            ss>>number;
            bool kt = boa.makeMove(number);
            if (kt)
            {
                /// kiểm tra dữ liệu có phải là số hợp lệ không 
                cout << "\n";
                boa.drawBoard();
                cout << "\n";
                break;
            }
            else
                cout << "So khong hop le! Hay nhap lai: ";
        }
    }
    /// move của nguoi choi
    void Move(Board &boa)
    {
        COLOR(4);
        cout << "\nNguoi choi ";
        if (stt)
            cout << stt << " ";
        cout << "nhap so (1-9): ";

        /// Nhập số và kiểm tra tính hợp lệ của số và trình bày bảng
        Exception_Handling(boa);
    }
};

class Game
{
private:
    Board board;
    Player *s1, *s2;
    string type;
public:
    /// Hàm chạy chương trình
    void Establish(){
        cout << "\033[2J\033[1;1H";       /// Xóa Màn Hình 
        system("color E");    /// Màu Ban Đầu
        // srand(time(nullptr)); /// Thời Gian Thực
    }
    void Chosetype(){
        type="";
            ///Người dùng chọn chế độ muốn chơi
            cout << "\t\t\t\t\tChao mung den voi game TICTACTOE!\n\nThe loai ban muon choi (1x1: Human vs Human || 1x0: Human vs Computer || 0x0: Computer vs Computer): ";
            while (true)
            {
                cin >> type;
                if (type == "1x1" || type == "1x0" || type == "0x0")
                    break;
                else
                    cout << "\nHay nhap lai: ";
            }
    }
    void Updvariable(){
        if (type == "1x1")
        {
            s1 = new HumanPlayer(1);
            s2 = new HumanPlayer(2);
        }
        else if (type == "1x0")
        {
            s1 = new HumanPlayer();
            s2 = new ComputerPlayer();
        }
        else if (type == "0x0")
        {
            s1 = new ComputerPlayer(1);
            s2 = new ComputerPlayer(2);
        }
    }
    void Play(){
        while (!board.ktFinished())
            {
                if (board.getvalueCell() == Board::Cell::X)
                {
                    if(s1->NotHuman()) time(700);
                    s1->Move(board);
                }
                else
                {
                    if(s2->NotHuman()) time(700);
                    s2->Move(board);
                }
            }
    }
    void printWinner(){
                    cout << "\n\n---------------------------Game End---------------------\n\n";
            if (board.checkWinner() == Board::Cell::X)
                cout << "\t\t\t   WINNER: X\n\n";
            else if (board.checkWinner() == Board::Cell::O)
                cout << "\t\t\t   WINNER: O\n\n";
            else if (board.checkWinner() == Board::Cell::Draw)
                cout << "\t\t\t   X DRAW O\n\n";
            board.drawBoard();
    }
    bool Continue(){
            /// Hỏi người dùng muốn tiếp tục hay không 
            cout << "\n\n\t\tBan co muon choi nua khong? \n\t  Nhap 1 de tiep tuc, 0 de ket thuc: ";
            int a;
            cin >> a;
            system("cls");
            if (!a)
            {
                cout << "\n\n\t\t\tCam on quy khach da su dung dich vu TICTACTOE cua nhom WIBU \n\n"; 
                return false;            
            }
            return true;
    }
    void run()
    {
        Establish();
        while (true)
        {
            Chosetype();
            board=Board();
            /// Bắt đầu game
            cout << "\n\n--------------------------Game start-----------------------\n\n";
            board.drawBoard(0);
            ///Nâng cấp biến
            Updvariable();
            /// Choi
            Play();
            /// Trình ra ai là người chiến thắng 
            printWinner();
            delete s1, s2;

            /// Hỏi người dùng muốn tiếp tục hay không 
            bool kt=Continue();
            if(!kt) break;
        }
    }
};
int main()
{
    Game TicTacToe;
    TicTacToe.run();
}