#include<windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int health=10;
int rol=26,col=100;

void gotoxy(double x, double y) // allows to move inside the terminal using coordinates
{	// the type is double, so objects can move less than 1 unit
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x+10; // start from 0
	dwPos.Y = y+2; // start from 0
	SetConsoleCursorPosition(hCon, dwPos);
}
class Rocket
{
    private:
        int xx;
        int yy;
    public:
        int x;
        int y;
        bool visible=true;
        Rocket(int _x,int _y):x(_x),y(_y),xx(_x),yy(_y){};
        void draw(){
                gotoxy(x-3,y-2);  cout<<" >\\\\ ";
                gotoxy(x-3,y-1);  cout<<" >=\\\\ ";
                gotoxy(x-4,y);  cout<<">}[]=[]>";
                gotoxy(x-3,y+1);  cout<<" >=// ";
                gotoxy(x-3,y+2);  cout<<" >// ";

        }
        void Erase(){
                gotoxy(xx-3,yy-2);cout<<"     ";
                gotoxy(xx-3,yy-1);cout<<"      ";
                gotoxy(xx-5,yy);cout<<"         ";
                gotoxy(xx-3,yy+1);cout<<"      ";
                gotoxy(xx-3,yy+2);cout<<"     ";
                xx=x;
                yy=y;
        }
        void Move(){
            Erase();
            draw();
        }
        void xy(int _x,int _y){
            x=_x;
            y=_y;
        }
};

class Planet
{
    private:
        int xx;
        int yy;
        int value;
    public:
        int x;
        int y;
        bool visible=true;
        Planet(int _x,int _y,int _value):x(_x),y(_y),xx(_x),yy(_y),value(_value){};
        void draw(){
                gotoxy(x-7,y);cout<<"[][][][][][][]";
                gotoxy(x-7,y+1);cout<<"\\[][][][][][]/";
                gotoxy(x-5,y+2);cout<<"\\[][][][]/";
                gotoxy(x-4,y+3);cout<<"--------";
                gotoxy(x-7,y-1);cout<<"/[][][][][][]\\";
                gotoxy(x-5,y-2);cout<<"/[][][][]\\";
                gotoxy(x-4,y-3);cout<<"--------";
                if(x>col-10){
                    for(int i=y-3;i<y+4;i++){
                        gotoxy(col,i);cout<<"|               ";
                    }
                    for(int i=y-3;i<y+4;i++){
                        gotoxy(-10,i);cout <<"          |";
                    }
                }else if(x<8){
                    for(int i=y-3;i<y+4;i++){
                        gotoxy(-10,i);cout <<"          |";
                    }
                }
        }
        void Erase(){
                gotoxy(x-8,y);  cout<<"                  ";
                gotoxy(x-7,y+1);cout<<"                 ";
                gotoxy(x-5,y+2);cout<<"              ";
                gotoxy(x-4,y+3);cout<<"            ";
                gotoxy(x-7,y-1);cout<<"                 ";
                gotoxy(x-5,y-2);cout<<"             ";
                gotoxy(x-4,y-3);cout<<"           ";
                xx=x;
                yy=y;
        }
        void Move(){
            Erase();
            if(visible==true){
                draw();
            }
        }
        void Pmove(){
            x-=value;
            if(x<-3){
                x=col+6;
                for(int i=1;i<rol;i++){
                    gotoxy(0,i);cout <<"|       ";
                }
            }
        }
        void hit(Rocket *rk){
            if(visible==true){
                if((rk->x > x-5)&&(rk->x < x+4)&&(rk->y > y-5)&&(rk->y < y+5)){
                    health-=1;
                    cout<<"\a";
                }
            }
        }
        void xy(int _x,int _y){
            x=_x;
            y=_y;
        }
};


