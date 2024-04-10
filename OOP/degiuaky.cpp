#include<iostream>
using namespace std;
class Character{
protected:
    string name;
    int age, hp, dame, level;
public:
    friend ostream& operator <<(ostream& os,Character& s){
        os<<"{"<<s.name<<":"<<"{"<<s.age<<"}"<<s.level<<"}";
        return os;
    }
    ////khoitao
    Character(string _name="Noname", int _age=1,int _hp=100,int _dame=100,int _level=1){
        name=_name;age=_age;hp=_hp;dame=_dame;level=_level;
    }
    Character(const Character& s){
        name=s.name;age=s.age;hp=s.hp;dame=s.dame;level=s.level;
    } 
    ~Character(){}
    
};
class Human:public Character{
    int healing;///biến lưu trữ lượt dùng healing
    int power,power_buff;//power: biến lưu trữ lượt dùng power up; power_buff: biến lưu trữ lượt đang sử dụng power up
    int dracula;///biến lưu trữ lượt dùng dracula
public:

    ///
    Human(string _name, int _age,int _hp,int _dame,int _level):Character(_name,_age,_hp,_dame,_level){
        healing=4;power=3;power_buff=0;dracula=6;
    }
    Human(const Human& a):Character(a){ }
    ~Human(){}
    ///////     
    friend istream& operator >>(istream & in, Human &a){
        string name;
        int age,hp,dame,level;
        getline(in,name);
        in.ignore();
        in>>age>>hp>>dame>>level;
        a=Human(name,age,hp,dame,level);
        return in;            
    }
    ////
    
    void Healing(Human& a,Human goc){
        healing++;
        if(healing%4==0 && a.hp<=0.8*goc.hp) {
            a.hp+=0.2*(goc.hp-a.hp);
        }
    }
    void Power(Human& a){
        if(power==3) power_buff++;
        if(power_buff==0) power++;
        if (power_buff){
            a.dame+=0.5*a.dame;
        }
        if(power_buff==1) power_buff=0;
    }
    void Dracula(Human& a){
        if(dracula%6==0){
            a.hp+=a.dame*0.05;
        }
        dracula++;
    }
};
class Monster:public Character{
public:
    Monster(string _name, int _age,int _hp,int _dame,int _level):Character(_name,_age,_hp,_dame,_level){}
    Monster(const Monster& a):Character(a){}
    ~Monster(){}
    ///////
    friend istream& operator >>(istream & in, Monster &a){
        int floor;
        string name;
        int age,hp,dame,level;
        in>>floor;
        in.ignore();
        getline(in,name);
        in.ignore();
        in>>age>>hp>>dame>>level;
        a=Monster(name,age,hp,dame,level);
        return in;            
    }
};
class Boss:public Monster{
    int healing;
    int power,power_buff;
public:
    Boss(const Monster&a):Monster(a){healing=5;power=5;power_buff=0;}
    void Healing(Boss& a,Boss goc){
        healing++;
        if(healing%5==0 && a.hp<=0.5*goc.hp) {
            a.hp+=0.3*(goc.hp-a.hp);
        }
    }
    void Power(Boss& a){
        if(power==5) power_buff++;
        if(power_buff==0) power++;
        if (power_buff){
            a.dame+=0.1*a.dame;
        }
        if(power_buff==2) power_buff=0;
    }
};
int main(){
    return 0;
}