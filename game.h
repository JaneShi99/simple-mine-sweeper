#include "cell.h"
#include<iostream>

class game{
    const int width = 20;
    const int height = 20;
    std::vector<std::vector<Cell>> board;
    bool gameOn;
    bool win;

   private:
    bool detectWin();
    void markBomb(int x, int y);
  public:
    game();
    ~game();
    bool checkAvailable(int x, int y);
    void markReveal(int x, int y);
     


};
