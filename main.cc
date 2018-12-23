#include<iostream>
#include "game.h"

using namespace std;
int main()
{
    game * g = new game();
    char p;
    int x;
    int y;

    while(cin >> p && cin>> x && cin >> y){
    
        if(p == 'm'){}
        else if (p == 's'){}
        else{cout<<"Wrong commands!";}

    
    }

    delete g;

}
