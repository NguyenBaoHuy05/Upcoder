#include<iostream>
using namespace std;
class Robot{
    string name,username;
    int power,x,y;
public:
    int getpower(){return power;}
    void setpower(int a){power-=a;}
    int getx(){return x;}
    void setx(int a){x+=a;}
    int gety(){return y;}
    void sety(int a){y+=a;}
    Robot(string _name, string _username,int _power=100, int _x=0, int _y=0){
        name=_name; username=_username; x=_x;y=_y;power=_power;
    }
    Robot(string _name, string _username){
        name=_name; username=_username;x=0;y=0;power=100;
    }
    Robot(){
        name="Robot";
        username="NoName";
        x=0;y=0;power=100;
    }
    Robot(const Robot&s){
        name=s.name; username=s.username; x=s.x;y=s.y;power=s.power;
    }
    void Charge() {power+=10;}
    virtual bool Move(int direction)=0;
    void Display(){
        cout<<"{"<<name<<"}:{"<<username<<"}";
    }
    friend ostream& operator<<(ostream& os,Robot &a){
        os<<"{"<<a.name<<"}:{"<<a.username<<"}"<<endl;
        os<<"("<<a.x<<","<<a.y<<")"<<endl;
        os<<a.power;
    }
};
class NormalRobot:public Robot{
public:
    NormalRobot(string _name, string _username,int _power=100, int _x=0, int _y=0):Robot(_name,_username,_power,_x,_y){}
    bool Move(int direction)  {
        if (direction==4) setpower(-10);
        bool check=(0<=direction && direction<=3  && getpower()>0)?true:false;
        if (check)   {
            setpower(5);
            switch (direction)
            {
            case 0:
                setx(-1);
                break;
            case 1:
                setx(1);
                break;
            case 2:
                sety(1);
                break;
            case 3:
                sety(-1);
                break;          
            default:
                break;
            }
        }
        return check;
    }
};
class AdaptiveRobot:public Robot{
public:
    AdaptiveRobot(string _name, string _username,int _power=100, int _x=0, int _y=0):Robot(_name,_username,_power,_x,_y){}
    bool Move(int direction)  {
        if (direction==4) setpower(-10);
        bool check=(0<=direction && direction<=3  && getpower()>0)?true:false;
        if (check)   {
            switch (direction)
            {
            case 0:
                setx(-1);
                break;
            case 1:
                setx(1);
                break;
            case 2:
                sety(1);
                break;
            case 3:
                sety(-1);
                break;          
            default:
                break;
            }
        }
        return check;
    }
};
int main(){
    int a,b[100],d;
    string name,username;
    int power,x,y;
    cin>>a;
    cin.ignore(); 
    Robot *p[100];
    for (int i=0;i<a;i++){   
        getline(cin,name);
        getline(cin,username);
        cin>>power>>x>>y;
        p[i]=new NormalRobot(name,username,power,x,y);
        if(name[0]!='A'){
            while(cin>>d){
                bool c=p[i]->Move(d);
            }
        }
        else {
            p[i]=new AdaptiveRobot(name,username,power,x,y);
            bool f=true;
            while(f){
                cin>>d;
                if(p[i]->getpower()>50 && d!=-1){
                for(int j=0;j<3;j++){
                    bool c=p[i]->Move(d);
                    cin>>d;
                }
                p[i]->setpower(12);
                }
                if(p[i]->getpower()>20 && p[i]->getpower()<=50 && d!=-1){
                for(int j=0;j<2;j++){
                    bool c=p[i]->Move(d);cin>>d;
                }
                p[i]->setpower(9);
                }
                if(p[i]->getpower()<=20 && p[i]->getpower()>0 && d!=-1){
                for(int j=0;j<1;j++){
                    bool c=p[i]->Move(d);cin>>d;
                }
                p[i]->setpower(6);
                }
                if( d==-1) f=false;
            }
        }
        cin.ignore();
        cin.clear();
    }
    for (int i=0;i<a;i++){
        cout<<*p[i]<<endl;
        delete p[i];
    }
    return 0;
}