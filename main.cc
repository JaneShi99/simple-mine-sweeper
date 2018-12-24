#include<iostream>
#include "game.h"
#include "cell.h"
using namespace std;
int main()
{
    Game * g = new Game();
    char p;
    int x;
    int y;

    Cell * c = new Cell();
    delete c;
    while(cin >> p && cin>> x && cin >> y){
    
        if(p == 'm'){}
        else if (p == 's'){}
        else{cout<<"Wrong commands!";}

    
    }

    delete g;

}
