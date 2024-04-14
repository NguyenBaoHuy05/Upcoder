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
    Character(string na, string ty, int le, int co, int h, int phys, int magic):name(na),type(ty),level(le),coins(co),hp(h),physical_dame(phys),magic_dame(magic){}
    // Khởi tạo giá trị ban đầu
    Character() : Character("", "", 0, 0, 0, 0, 0) {}
    int getdame(){
        return (physical_dame + magic_dame)*level;
    }
    void takeDame(int dame)
    {
        hp -= dame;
        if (hp < 0)
        {
            hp = 0;
        }
    }
    bool Survive()
    {
        return hp > 0;
    }

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
    void info(){
        cout <<"{ "<< name << " }:{ " << type << " }:{ " << level  << " }:{ "<< coins<<" }:{ "<< hp<<" } "<<endl ;
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
    float multiplier; // 0: normal, 1: elite, 2: boss
public:
    // Hàm Khởi tạo
    Monster(string na, string ty, int le, int co, int h, int phys, int magic) : Character(na, ty, le, co, h, phys, magic) {}

    // Khởi tạo giá trị ban đầu
    Monster() : Character("", "", 0, 0, 0, 0, 0) {}
    ///
    void Update()
    {
        if(name=="normal"){
            multiplier=0;
        }
        else if(name=="elite"){
            multiplier=0.5;
        }
        else if(name=="boss"){
            multiplier=1;
        }
        hp=hp+hp*multiplier;
        physical_dame=physical_dame+physical_dame*multiplier;
        magic_dame=magic_dame+magic_dame*multiplier;
    }
    void nhap(){
        Character::nhap();
    }
};
class Hero : public Character {
private:
    int exp;
    int totalexp;
    int dame;
    // khai báo các hàm cho class hero 
public:
    Hero(){
        exp = 0;
        totalexp= 0;
    }
    void Update_Totalexp(Monster& monster){
        totalexp= exp + (monster.gethp()+monster.getdame())*
        (monster.getlevel())/level;
        /* hàm tính tổng số lượng exp của nhân vật với tham số là class monster
        được truyền vào bởi hàm getlevel */ 
    }
    void Update(int level_now){
        int p,m;
        hp = hp + level_now*100;
        if(type=="mage"){p=50;m=70;}
        else {
            p=70;m=50;
        }
        physical_dame = physical_dame + level_now*p;
        magic_dame = magic_dame + level_now*p;
    }
    void Update_Level(){
        while(true){
            int expNeedToUpdrage = level*100; 
            totalexp -= expNeedToUpdrage;
            if(totalexp < expNeedToUpdrage ) break;
            else    {
                level++;
                Update(level);
            }
        }  // có tăng level ko 
    }

    void getbonus (Monster& monster){
        coins = coins + monster.getcoins(); 
    }
    /* truyền tham số monster và sự dụng dữ liệu từ hàm getcoins 
    của class monster*/
    void nhap(){
        Character::nhap();
    } 
};
bool Attack(Hero &a,Monster &b){
    a.Update_Level();
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
                return true;
            }
            if(a.Survive()){}
            else {
                return false;
            }        
        }
}
int main(){
    Hero hero;
    hero.nhap();
    hero.info();
    Monster monster[100];
    int so,dem=0;
    bool kt=true;
    cin>>so;
    for(int i=0;i<so;i++){
        monster[i].nhap();
        monster[i].info();
    }
    while(dem<so && kt){
        kt=Attack(hero,monster[dem]);
        dem++;
    }
    if(dem==so){
        cout<<"Win"<<endl;
        hero.info();
    }
    else{
        cout<<"Lose: Match "<<dem;
    }
    return 0;
}


