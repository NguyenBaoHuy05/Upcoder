#include<iostream>
#include<vector>
#include<random>
#include<ctime>
#include<stdlib.h>
#include <chrono>
#include <thread>
#include<windows.h>

#define for(i,n) for(int i=1;i<=n;i++)
using namespace std;
void time(int n){ this_thread::sleep_for(chrono::milliseconds(n)); }///ham dung thoi gian
void COLOR(int color)///ham tao mau sac
{
	WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}

class Board{
public:
    enum class Cell{None,X,O,Draw};///class gia tri tai 1 cell
private:
    vector<Cell> board;
    Cell valueCell;
    mt19937 rng;
public:
    Board():board(10,Cell::None), valueCell(Cell::X),rng(time(nullptr)){}

    /// Draw bang
    void drawBoard(int n=1){
        if(n){
            for(i,9){
                COLOR(7);
                if(i==1) cout<<"\t\t\t-------------\n\t\t\t";
                if(i%3==1) cout<<"| "; 
                if(board[i]==Cell::None)   {cout<<" ";}
                else if(board[i]==Cell::X) {COLOR(3);cout<<"X";}
                else                       {COLOR(14);cout<<"O";}
                if(i%3!=0)                 {COLOR(7);cout<<" | ";}
                else                       {COLOR(7);cout<<" | \n\t\t\t-------------\n\t\t\t";}
            }
            COLOR(6);cout<<endl;
        }
        else for(i,9){
            COLOR(7);
                if(i==1)      cout<<"\t\t\t-------------\n\t\t\t";
                if(i%3==1)    cout<<"| "; 
                cout<<i;
                if(i%3!=0)    cout<<" | ";
                else  cout<<" | \n\t\t\t-------------\n\t\t\t";
            }
        cout<<endl;          
    }
    
    ///Kiem tra move hop le
    bool makeMove(int number){
        if(number<1 || number>9 || board[number]!=Cell::None) return false;
        board[number] = valueCell;
        valueCell=(valueCell==Cell::X)? Cell::O : Cell::X ;
        return true;
    }
    ///Kt ai chien thang
    Cell checkWinner(){
        ///Check rows
        for(i,3){
            if(  board[i*3-2]!=Cell::None && board[i*3-2]==board[i*3-1] && board[i*3-2]==board[i*3])  return board[i*3-2];
        }
        ///Check columns
        for(i,3){
            if(  board[i]!=Cell::None && board[i]==board[i+3] && board[i]==board[i+6])  return board[i];
        }
        ///Check dcheo
        if(board[1]!=Cell::None && board[1]==board[5] && board[1]==board[9]) return board[1];
        if(board[3]!=Cell::None && board[3]==board[5] && board[3]==board[7]) return board[3];
        ///Check draw
        bool ktDraw=true;
        for(i,9){
            if(board[i]==Cell::None) {
                ktDraw=false;
                break;
            }        
        }
        if(ktDraw) return Cell::Draw;
        ///Check not winner
        return Cell::None;
    }
    /// Kiem tra co ket thuc game ko
    bool ktFinished()           {return checkWinner()!=Cell::None;}
    ///Lay gia tri hien tai, dang X hay O
    Cell getvalueCell()         {return valueCell;}
    ///Qua tai []
    Cell &operator[] (int i)    {return board[i];}
};

class Player{
public:
///ham thuan ao move quan li nuoc di
    virtual void Move(Board &boa)=0; 
};

class ComputerPlayer:public Player{
private:
    int may;///may1 hay may2
    Board::Cell computerCell; // Cell mà máy tính đang chơi
    Board::Cell opponentCell; // Cell của đối thủ
public:
    ComputerPlayer(int _may=0,Board::Cell _computerCell=Board::Cell::O) : Player(),may(_may),computerCell(_computerCell) {
        opponentCell = (computerCell == Board::Cell::X) ? Board::Cell::O : Board::Cell::X;
    }
    ///thuat toan minimax
    int minimax(Board &board, int depth, bool isMaximizing) {
            Board::Cell winner = board.checkWinner();
            // Đánh giá điểm của trạng thái hiện tại của bảng
            if (winner == computerCell) return 50 - depth;
            else if (winner == opponentCell) return depth - 50;
            else if (winner == Board::Cell::Draw) return 0;
            // Nếu không có ai thắng, tiếp tục tìm kiếm trạng thái tiếp theo
            if (isMaximizing) {
                int bestScore = -1000;
                for (i,9) {
                    if (board[i] == Board::Cell::None) {
                        board[i] = computerCell;
                        int score = minimax(board, depth + 3, false);
                        board[i] = Board::Cell::None;
                        bestScore = max(bestScore, score);
                    }
                }
                return bestScore;
            } else {
                int bestScore = 1000;
                for (i,9) {
                    if (board[i] == Board::Cell::None) {
                        board[i] = opponentCell;
                        int score = minimax(board, depth + 3, true);
                        board[i] = Board::Cell::None;
                        bestScore = min(bestScore, score);
                    }
                }
                return bestScore;
            }
        }
    //move cua may
    void Move(Board &board){
        int bestMove = -1;
        int bestScore = -1000;
        int chose;
        vector<int> ableMoves;
        ///khoi tao vector chua cac o di duoc
        for (i,9) {
            if (board[i] == Board::Cell::None) {
                ableMoves.push_back(i);
            }
        }
        ///Nuoc dau random de tranh trung lap khi dung minimax
        if(ableMoves.size()>=8 && computerCell==Board::Cell::X){
            int randomIndex = rand() % ableMoves.size();
            board.makeMove(ableMoves[randomIndex]);
            chose=ableMoves[randomIndex];
        }
        else{
            // Lặp qua tất cả các ô trống và tính toán điểm tối ưu
            for (i,9) {
                if (board[i] == Board::Cell::None) {
                    board[i] = computerCell;
                    int score = minimax(board, 0, false);
                    board[i] = Board::Cell::None;
                    if (score > bestScore) {
                        bestScore = score;
                        bestMove = i;
                    }
                }
            }
                    // Thực hiện nước đi tốt nhất
            board.makeMove(bestMove);
            chose=bestMove;
        }
        ////Xuat ra man hinh
        COLOR(11);
        cout<<"May ";
        if(may) cout<<may<<" ";
        cout<<"choi: "<<chose<<endl<<endl;
        board.drawBoard();
    }
};

class HumanPlayer:public Player{
private:
    string so;
    int nguoi;///nguoi choi 1 hay nguoi choi 2
public:
    HumanPlayer(int _nguoi=0) : Player(),nguoi(_nguoi) {}

    ///move cu nguoi choi
    void Move(Board &boa){
        COLOR(4);
        cout<<"\nNguoi choi ";
        if(nguoi) cout<<nguoi<<" ";
        cout<<"nhap so (1-9): ";
        
        ///Nhap so, kiem tra tinh hop le cua so và show bang
        while(true){
             cin>>so;
            cout<<endl;
            while (true)
            {
                ///Kiem tra chu
                bool isDigit=true;
                for(i,so.size()-1)  if(isalpha(so[i])) {
                    isDigit=false;  break;
                }               
                if(isDigit)  break;
                else  { 
                    cout<<"Khong chap nhan chu! Hay nhap so: " ;
                    cin>>so;
                    cout<<endl;
                }
            }                     
            int number=stoi(so);          
            bool kt=boa.makeMove(number);
            if(kt){
                ///Kiem tra tinh hop le cua so
                cout<<"\n";
                boa.drawBoard();  cout<<"\n"; 
                break;
            }
            else cout<<"So khong hop le! Hay nhap lai: ";
        }
    }
};

class Game{
public:

///ham chay chuong trinh
    void run(){
        system ("cls");///Xoa man hinh
        system("color E");///Mau ban dau
        srand(time(nullptr));///Thoi gian thuc

        while(true){
            Board board;
            string type;
            Player *s1,*s2;

            ///Nguoi dung chon the loai muon choi
            time(300);
            cout<<"\t\t\t\t\tChao mung den voi game TICTACTOE!\n\nThe loai ban muon choi (1x1: Human vs Human || 1x0: Human vs Computer || 0x0: Computer vs Computer): ";
            while(true){
                cin>>type; 
                if(type=="1x1" || type=="1x0" || type=="0x0") break;
                else cout<<"\nHay nhap lai: ";
            }

            ///Bat dau game
            cout<<"\n\n--------------------------Game start-----------------------\n\n";
            board.drawBoard(0);

            ///4 truong hop=> khai bao khac nhau
            if(type=="1x1"){
                s1=new HumanPlayer (1);
                s2=new HumanPlayer (2);                    
            }
            else if(type=="1x0"){
                s1=new HumanPlayer ();
                s2=new ComputerPlayer ();         
            }
            else if(type=="0x0"){
                s1=new ComputerPlayer (1,Board::Cell::X);
                s2=new ComputerPlayer (2,Board::Cell::O);         
            }
            ///Choi
            while(!board.ktFinished()){
                    if(board.getvalueCell()==Board::Cell::X) {
                        time(800);s1->Move(board);
                    } 
                    else {
                            time(800);//Thoi gian cho
                            s2->Move(board);
                        }                
            }
                ///Show ra nguoi chien thang
            cout<<"\n\n---------------------------Game End---------------------\n\n";
            if(board.checkWinner()==Board::Cell::X)          cout<<"\t\t\t   WINNER: X\n\n";
            else if(board.checkWinner()==Board::Cell::O)     cout<<"\t\t\t   WINNER: O\n\n";
            else if(board.checkWinner()==Board::Cell::Draw)  cout<<"\t\t\t   X DRAW O\n\n";
            board.drawBoard();
            delete s1,s2;

            ///Tiep tuc hay khong
            cout<<"\n\n\t\tBan co muon choi nua khong? \n\t  Nhap 1 de tiep tuc, 0 de ket thuc: ";
            int a; 
            cin>>a;
            system("cls");
            if(!a){
                cout<<"\n\n\t\t\tCam on quy khach da su dung dich vu TICTACTOE cua nhom WIBU \n\n";                
                break;
            }
        }           
    }
};
int main(){
    Game TicTacToe;
    TicTacToe.run();
}

