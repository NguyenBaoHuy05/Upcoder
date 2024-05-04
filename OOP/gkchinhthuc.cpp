#include<iostream>
#include<vector>
using namespace std;
class Character
{
protected:
    string name;
    string type;
    int level;
    int coins;
    int hp;
    int physical_dame;
    int magic_dame;
public:
    // Khởi tạo 
    Character(string na, string ty, int le, int co, int h, int phys, int magic):name(na),type(ty),level(le),coins(co),hp(h),physical_dame(phys),magic_dame(magic){}
    Character() : Character("", "", 0, 0, 0, 0, 0) {}
    ///Hàm nhận dame
    void takeDame(int dame)
    {
        hp -= dame;
        if (hp < 0)
        {
            hp = 0;
        }
    }
    /// Kiểm tra sống hay chết
    bool Survive()
    {
        return hp > 0;
    }
    /// Nhap thong tin
    void nhap()
    {
        cin >> name;
        cin >> type;
        cin >> level;
        cin >> coins;
        cin >> hp;
        cin >> physical_dame;
        cin >> magic_dame;
    }
    //Xuat thong tin
    void info(){
        cout <<"{ "<< name << " }:{ " << type << " }:{ " << level  << " }:{ "<< coins<<" }:{ "<< hp<<" } "<<endl ;
    }
    /// hàm lấy giá trị dame, coins, level,hp
    int getdame(){
        return (physical_dame + magic_dame)*level;
    }
    int getcoins(){
        return coins;
    }
    int getlevel(){
        return level;
    }
    int gethp(){
        return hp;
    }
};
class Monster : public Character
{
private:
    float multiplier; //chỉ số tăng theo loại quái
public:
    // Hàm Khởi tạo
    Monster(string na, string ty, int le, int co, int h, int phys, int magic) : Character(na, ty, le, co, h, phys, magic) {}
    Monster() : Character("", "", 0, 0, 0, 0, 0) {}
    ///Hàm Update chỉ số theo loại quái
    void Update()
    {
        if(type=="normal"){
            multiplier=0;
        }
        else if(type=="elite"){
            multiplier=0.5;
        }
        else if(type=="boss"){
            multiplier=1;
        }
        //Update các chỉ số
        hp=hp+hp*multiplier;
        physical_dame+=physical_dame*multiplier;
        magic_dame+=magic_dame*multiplier;
    }
};
class Hero : public Character {
private:
    int totalexp;// biến kinh nghiệm
public:
    // Khởi tạo giá trị ban đầu
    Hero(string na, string ty, int le, int co, int h, int phys, int magic) : Character(na, ty, le, co, h, phys, magic) {totalexp= 0;}
    Hero() : Character("", "", 0, 0, 0, 0, 0) {totalexp= 0;}

    ///Hàm nâng kinh nghiệm khi đánh thắng quái
    void Update_Totalexp(Monster& monster){
        totalexp+= (monster.gethp()+monster.getdame()) * (monster.getlevel())/level;
        //Kinh nghiệm tăng theo chuẩn công thức trên
    }

    ///Hàm Update chỉ số khi level tăng
    void Update(int level_now){
        int p,m;
        hp = hp + level_now*100;
        if(type=="mage"){p=50;m=70;}
        else {
            p=70;m=50;
        }
        physical_dame += level_now*p;
        magic_dame += level_now*m;
    }

    ///  Hàm Update level
    void Update_Level(){
        while(true){
            int expNeedToUpdrage = level*100;    //Mức để lên level mới         
            if(totalexp < expNeedToUpdrage ) break;
            else    {
                totalexp -= expNeedToUpdrage;
                level++;
                Update(level);
            }
        }
    }

    /// Hàm lấy tiền khi thắng quái
    void getbonus (Monster& monster){
        coins = coins + monster.getcoins(); 
    }
 
};

//Hàm xử lý main combat với quái
bool Attack(Hero &a,Monster &b){
    Monster c=b;
    b.Update();
        while(true){
            b.takeDame(a.getdame());
            if(b.Survive()){
                a.takeDame(b.getdame());
            }
            else {
                a.getbonus(b);
                a.Update_Totalexp(c);
                a.Update_Level();
                return true;
            }
            if(!a.Survive())
            {
                return false;
            }        
        }
}
int main(){
    //Khai báo và nhập/xuất hero
    Hero hero;
    hero.nhap();
    hero.info();

    // Khai báo mảng chứa monster
    Monster monster[100];
    int so,dem=0;
    cin>>so;
    bool kt=true;

    //Nhập/xuất thông tin cho các monster
    for(int i=0;i<so;i++){
        monster[i].nhap();
        monster[i].info();
    }

    /// Quá trình đánh quái và kết quả
    while(dem<so && kt){
        kt=Attack(hero,monster[dem]);
         if(kt) dem++;
    }
    if(dem==so){
        cout<<"Win"<<endl;
        hero.info();
    }
    else{
        cout<<"Lose: Match "<<dem+1;
    }
    return 0;
}


