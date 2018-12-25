#include<iostream>
#include "game.h"
#include "cell.h"
using namespace std;
int main()
{
    Game g;
    char p;
    int x;
    int y;

    cout<<g;
    while(cin >> p && cin>> x && cin>>y ){
   
        cout<<g;
        if(p == 'm'){
        
            g.markBomb(x,y);
        }
        else if (p == 'u'){
            g.unMarkBomb(x,y);
        }
        else if (p == 's'){
            g.markReveal(x,y);
        
        }
        else{cout<<"Wrong commands!";}
    }


}
