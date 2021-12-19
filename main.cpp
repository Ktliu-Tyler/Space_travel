#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "game_tools.h"

using namespace std;

Rocket rk1(15,rol/2);
Planet p1(70,4,1);
Planet p2(90,13,3);
Planet p3(80,22,2);
int vx=0,vy=0,vz=0;
bool gameover=false;
bool death=false;
int score=0;
int death_number=0;
int Time;
bool tryagain=true;
int target=1000;

void border(int col,int rol){
    gotoxy(1,-1);cout <<"Score:        ";
    gotoxy(col-20,-1);cout <<"Health: @@@@@@@@@@";
    for(int i=0;i<rol+1;i++){
        gotoxy(col,i);cout<<"|";
        gotoxy(0,i);cout<<"|";
    }
    for(int i=0;i<col+1;i++){
        gotoxy(i,rol+1);cout<<"=";
        gotoxy(i,0);cout<<"=";
    }
}


void get_key(){
	if(_kbhit()){
        switch(getch()){
            case 'w':
            	if(rk1.y>3){
                    //rk1.Erase();
                    rk1.y-=2;
	        	}
            break;

            case 's':
            	if(rk1.y<rol-3){
                    //rk1.Erase();
                    rk1.y+=2;
	        	}

            break;
        }
    }

}

void set_up(){
    border(col,rol);
    health=10;
    score=0;
    death_number=0;
    gameover=false;
    death=false;
    Time=30;
    rk1.xy(15,rol/2);
    p1.xy(70,4);
    p2.xy(90,13);
    p3.xy(80,22);
}

void Option(){
    gotoxy(8,-1);cout<<score;
    for (int i=0;i<(10-health);i++){
        gotoxy(col-13+10-i,-1);cout<<" ";
    }
    if(health<1){
        gameover=true;
        death=true;
        rk1.Erase();
    }
    if(score>target){
        gameover=true;
        death=false;
    }
}

void bomb(){
    while(death==true && death_number<25){

        if(death_number%2==0){
            gotoxy(rk1.x-3,rk1.y-2);cout <<"        ";
            gotoxy(rk1.x-3,rk1.y-1);cout <<"         ";
            gotoxy(rk1.x-4,rk1.y);  cout <<"          ";
            gotoxy(rk1.x-4,rk1.y+1);cout <<"          ";
            gotoxy(rk1.x-3,rk1.y+2);cout <<"         ";
            gotoxy(rk1.x-3,rk1.y+3);cout <<"        ";

            gotoxy(rk1.x-3,rk1.y-2);cout <<" ^^ ^ ^ ";
            gotoxy(rk1.x-3,rk1.y-1);cout <<"\\*| |*/";
            gotoxy(rk1.x-4,rk1.y);  cout <<"-- * * --";
            gotoxy(rk1.x-4,rk1.y+1);cout <<"-- * * --";
            gotoxy(rk1.x-3,rk1.y+2);cout << "/*| |*\\";
            gotoxy(rk1.x-3,rk1.y+3);cout <<"/___---";
        }
        else if(death_number%2==1){
            gotoxy(rk1.x-3,rk1.y-2);cout <<"        ";
            gotoxy(rk1.x-3,rk1.y-1);cout <<"         ";
            gotoxy(rk1.x-4,rk1.y);  cout <<"          ";
            gotoxy(rk1.x-4,rk1.y+1);cout <<"          ";
            gotoxy(rk1.x-3,rk1.y+2);cout <<"         ";
            gotoxy(rk1.x-3,rk1.y+3);cout <<"        ";
            gotoxy(rk1.x-3,rk1.y-1);cout <<"\\ | | /";
            gotoxy(rk1.x-4,rk1.y);  cout <<"--     --";
            gotoxy(rk1.x-4,rk1.y+1);cout <<"--     --";
            gotoxy(rk1.x-3,rk1.y+2);cout << "/ | | \\";
        }
        death_number++;
        Sleep(100);
    }
    //system("cls");
    //border(col,rol);
    //Option();
}

void win(){
    while(death==false && death_number<50){
        rk1.x+=2;
        rk1.y=rol/2;
        //p1.xy(80,20);
        //p2.xy(90,4);
        p1.Move();
        p2.Move();
        rk1.Move();
        Sleep(Time);
        if(rk1.x>col-6){
            for(int i=rk1.y-3;i<rk1.y+4;i++){
                        gotoxy(col,i);cout<<"|               ";
            }
        }
        if(rk1.x>col+3){
            death_number=50;
        }
    }
    system("cls");
    border(col,rol);
    Option();
}

void Start_view(){
    gotoxy(1,rol/2-3); cout <<" ------   ------   ------   ------   ------     ------   ------   ------ --     -- ------  --      ";
    gotoxy(1,rol/2-2); cout <<"|------| |------| | ---- | |------| |------|   |__  __| | ---- | | ---- |\\\\     //|------| ||      ";
    gotoxy(1,rol/2-1); cout <<"||_____  ||____|| ||____|| ||       ||_____       ||    ||____|| ||____|| \\\\   // ||_____  ||      ";
    gotoxy(1,rol/2);   cout <<"|_____ | | _____| | ---- | ||       | _____|      ||    | ___  / | ---- |  |\\_/|  | _____| ||      ";
    gotoxy(1,rol/2+1); cout <<" _____|| ||       ||    || ||_____  ||_____       ||    ||   \\\\  ||    ||  \\\\ //  ||_____  ||_____ ";
    gotoxy(1,rol/2+2); cout <<"|______| ||       ||    || |______| |______|      ||    ||    \\\\ ||    ||   |_|   |______| |______|";
    gotoxy(1,rol/2+3); cout <<"===================================================================================================";
    gotoxy(1,rol/2+4); cout <<"     Input any key to start~~~                                      Making by Liu Ty 2021/6/10"     ;
}

void end_view(){
    gotoxy(col/2-35,rol/2-3); cout <<" ------   ------   ------   ------      ------  --    --  ------               ";
    gotoxy(col/2-35,rol/2-2); cout <<"|------| |------| |------| |------\\    | ---- \\  \\\\  //  |------|              ";
    gotoxy(col/2-35,rol/2-1); cout <<"||    || ||    || ||    || ||    ||    ||____|/   \\\\//   ||_____     ___     _ ";
    gotoxy(col/2-35,rol/2);   cout <<"||    _  ||    || ||    || ||    ||    | ____ \\    ||    | _____|   /___\\   // ";
    gotoxy(col/2-35,rol/2+1); cout <<"||___| | ||____|| ||____|| ||____||    ||____||    ||    ||_____   //   \\\\-//  ";
    gotoxy(col/2-35,rol/2+2); cout <<"|______/ |______| |______| |______/    |______/    ||    |______|              ";
    gotoxy(col/2-35,rol/2+3); cout <<"===============================================================================";
    gotoxy(col/2-35,rol/2+4); cout <<"     Input any key to quit~~~                                                  ";
}

void Gameover(){
    if(death==true){
        gotoxy(col/2-31,rol/2-3); cout <<"--    -- ------  --    --    --        ------   ------   ------ ";
        gotoxy(col/2-31,rol/2-2);cout<<" \\\\  // |------| ||    ||    ||       |------| |------| |------|";
        gotoxy(col/2-31,rol/2-1);cout<<"  \\\\//  ||    || ||    ||    ||       ||¡@¡@|| ||_____  ||_____";
        gotoxy(col/2-31,rol/2);   cout <<"   ||   ||    || ||    ||    ||       ||    || |_____ | | _____|";
        gotoxy(col/2-31,rol/2+1); cout <<"   ||   ||____|| ||____||    ||_____  ||____||  _____|| ||_____ ";
        gotoxy(col/2-31,rol/2+2); cout <<"   ||   |______| |______|    |______| |______| |______| |______|";
        gotoxy(col/2-31,rol/2+3); cout <<"================================================================";
        gotoxy(col/2-27,rol/2+4);cout <<"Your score is "<<score<<".      You are "<<target-score<<" away from finish line.";
        gotoxy(col/2-27,rol/2+5);

    }else {
        gotoxy(col/2-27,rol/2-3); cout <<"--    -- ------  --    --    --    --  ==  ---  --";
        gotoxy(col/2-27,rol/2-2);cout<<" \\\\  // |------| ||    ||    || -- ||  ==  |-\\\\ ||";
        gotoxy(col/2-27,rol/2-1);cout<<"  \\\\//  ||    || ||    ||    || || ||  ||  || \\\\||";
        gotoxy(col/2-27,rol/2);   cout <<"   ||   ||    || ||    ||    || || ||  ||  ||  \\\\|";
        gotoxy(col/2-27,rol/2+1); cout <<"   ||   ||____|| ||____||    \\\\_/\\_//  ||  ||   ||";
        gotoxy(col/2-27,rol/2+2); cout <<"   ||   |______| |______|     \\_/\\_/   ||  ||   ||";
        gotoxy(col/2-27,rol/2+3);cout <<"=====================================================";
        gotoxy(col/2-27,rol/2+4);cout <<"Thanks for your playing!!!!!!!!!!!!";
        gotoxy(col/2-27,rol/2+5);

    }
    system("pause");
    gotoxy(col/2-27,rol/2+6);cout<<"Try again ?  or quit(Q/q)";
    char chr=getch();
    if(chr=='q'||chr=='Q'){
        tryagain=false;
    }
    system("cls");
    border(col,rol);
    Option();

}



int main()
{
    while(tryagain){
        set_up();
        Option();
        Start_view();
        getch();
        system("cls");
        set_up();
        Option();
        p1.Move();
        p2.Move();
        rk1.Move();
        getch();
        while(!gameover){
            score++;
            get_key();
            rk1.Move();
            p3.Pmove();
            p3.Move();
            p2.Pmove();
            p2.Move();
            p1.Pmove();
            p1.Move();
            p1.hit(&rk1);
            p2.hit(&rk1);
            p3.hit(&rk1);
            Option();
            Sleep(Time-score/100);
        }
        bomb();
        win();
        Gameover();
        end_view();
    }
    gotoxy(0,rol+2);
    system("pause");
    return 0;
}

