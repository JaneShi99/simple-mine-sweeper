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
    g->print();

    while(cin >> p && cin>> x && cin>>y ){
   
        if(p == 'm'){
        
            g->markBomb(x,y);
	    g->print();
        }
        else if (p == 'u'){
            g->unMarkBomb(x,y);
	    g->print();
        }
        else if (p == 's'){
            g->markReveal(x,y);
            g->print();        
        }
        else{cout<<"Wrong commands!";}
    }
    delete g;
}
