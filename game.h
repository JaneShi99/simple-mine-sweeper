#include "cell.h"
#include<iostream>

class textDisplay;
class game{
    textDisplay * pImpl;
    static const int width = 20;
    static const int height = 20;
    std::vector<std::vector<Cell>> board;
    std::vector<std::pair<int,int>> bombs;
    std::vector<std::pair<int,int>> markedBombs;
    bool gameOn;
    bool win;

   public:
    game();
    ~game();
    bool checkAvailable(int x, int y);
    void markReveal(int x, int y);
    void markBomb(int x, int y);
    void unMarkBomb(int x, int y);

    //check win is a method that updates 
    void checkWin();
    friend std::ostream& operator<<(std::ostream& out, game g);
};

std::ostream& operator<<(std::ostream& out , game g);
