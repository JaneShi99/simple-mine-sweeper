#include<iostream>
#include "game.h"
#include "cell.h"
using namespace std;
int main()
{
    Game * g = new Game();
 //   char p;
 //   int x;
 //   int y;
    g->print();

    delete g;
    /*
    while(cin >> p && cin>> x && cin>>y ){
   
        g->print();
        if(p == 'm'){
        
            g->markBomb(x,y);
        }
        else if (p == 'u'){
            g->unMarkBomb(x,y);
        }
        else if (p == 's'){
            g->markReveal(x,y);
        
        }
        else{cout<<"Wrong commands!";}
    }

*/

}
