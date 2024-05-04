#include<iostream>
#include<random>
#include<vector>
#include<ctime>
using namespace std;
class Board{
protected:
    char a[3][3];
public:
    Board(){
        int dem=1;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) {
                a[i][j]=char(dem+int('0'));
                dem++;
            }
        }
    }
    void Show(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int Kt(){
        int x=0,o=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(a[i][j]=='X') x++;
                else if(a[i][j]=='O') o++;
            }
            if(x==3) return 1;
            if(o==3) return 2;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(a[j][i]=='X') x++;
                else if(a[j][i]=='O') o++;
            }
            if(x==3) return 1;
            if(o==3) return 2;
        }
        if(a[0][2]==a[2][0] && a[2][0]==a[1][1] && a[1][1]=='X') return 1;
        else if(a[0][2]==a[2][0] && a[2][0]==a[1][1] && a[1][1]=='O') return 2;
        if(a[0][2]==a[2][0] && a[2][0]==a[1][1] && a[1][1]=='X') return 1;
        else if(a[0][2]==a[2][0] && a[2][0]==a[1][1] && a[1][1]=='O') return 2;
        return 0;
    }
    bool Update(char so,char kt){
        if(so>'9' ||so<'1') return false;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(a[i][j]==so) {
                    if(a[i][j]=='X' || a[i][j]=='O') return false;
                    else {a[i][j]=kt;return true;}
                }
            }
        }
    }
    vector<int> Exist(){
        vector<int> tmp;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(a[i][j]=='X' || a[i][j]=='O') tmp.push_back((i+1)*(j+1));
            }
        }
        return tmp;
    }
};
class Player{
protected:
    char so;
public:

    int Winner(Board &boa){
        return boa.Kt();
    }

};
class HumanPlayer:public Player{
    int a=1;
    char kt;
public:
    void seta(int _a){
        a=_a;
    }
    void Nhap(Board &boa){
        if(a==1) kt='X';
        else if(a==2) kt='O';
        cout<<endl;
        cout<<"Nguoi choi "<<a<<" hay nhap so cua ban: ";
        cin>>so;
        bool kt=boa.Update(so,kt);
        while(!kt){
            cout<<endl;
            cout<<"Nhap co van de! Hay nhap so khac: ";
            cin>>so;
            if(boa.Update(so,kt)) break;
        }
    }
};
int random_number(vector<int> existed_numbers){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribution(1, 9 - existed_numbers.size());

    int rand_number= distribution(gen);

    for(int number: existed_numbers){
        if (rand_number >= number) {
            rand_number++;
        } else {
            break;
        }
    }

    return rand_number;
}

class ComputerPlayer:public Player{
    int a=2;
    char kt;
public:
    void seta(int _a){
        a=_a;
    }
    void Nhap(Board &boa){
        vector<int> luu;
        if(a==1) kt='X';
        else if(a==2) kt='O';
        /// Các số đã có rồi, random bỏ
        vector<int> existed_numbers=boa.Exist();

        ///Tạo số ngẫu nhiên, tránh số đã có
        int random_num = random_number(existed_numbers);
        cout<<"So cua may: ";
        bool kt=boa.Update(random_num,kt);
    }
};
class Game{
public:
    void run(){
        Board boa;
        string type;
        cout<<"Hay nhap the loai ma ban muon choi (1x1: nguoi vs nguoi; 1x0: nguoi vs may; 0x0: may vs may): ";
        cin>>type;
        while(type!="1x0" && type!="1x1" && type!="0x0"){
            cout<<endl;
            cout<<"Nhap khong dung! Hay nhap lai: ";
            cin>>type;
        }
        if(type=="1x1"){
            HumanPlayer a1,b2;
            a1.seta(1);
            b2.seta(2);
            while(true){
                a1.Nhap(boa);
                cout<<endl;
                boa.Show();
                cout<<endl;
                if(a1.Winner(boa)==1) {cout<<"Nguoi choi 1 thang!";break;}
                b2.Nhap(boa);
                cout<<endl;
                boa.Show();
                cout<<endl;
                if(b2.Winner(boa)==2) {cout<<"Nguoi choi 2 thang!";break;}
            }
        }
        else if(type=="1x0"){
            HumanPlayer a1;
            ComputerPlayer c2;
            a1.seta(1);
            c2.seta(2);
            while(true){
                a1.Nhap(boa);
                if(a1.Winner(boa)==1) {cout<<"Nguoi choi 1 thang!";break;}
                c2.Nhap(boa);
                if(c2.Winner(boa)==2) {cout<<"May tinh thang!";break;}
            }
        }
        else if(type=="0x0"){
            ComputerPlayer c1,c2;
            c1.seta(1);
            c1.seta(2);
            while(true){
                c1.Nhap(boa);
                if(c1.Winner(boa)==1) {cout<<"May tinh 1 thang!";break;}
                c2.Nhap(boa);
                if(c2.Winner(boa)==2) {cout<<"May tinh 2 thang!";break;}
            }
        }
    }
};
int main() {
    Game ame;
    ame.run();
    return 0;
}