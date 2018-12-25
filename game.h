#ifndef __GAME_H__
#define __GAME_H__
#include "cell.h"
#include <vector>
#include<iostream>
#include<map>
class Game{
    static const int width = 20;
    static const int height = 20;
    static const int bombsCount = 30;
    std::vector<std::vector<Cell> > board;
    std::map<std::pair<int,int>,int> bombs; // all of the elements has 1 as its second value
    std::map<std::pair<int,int>,int> markedBombs; //if unmarked, then remove from map. if marked is correct, 1, otherwise mark 2
    bool win;

   public:
    Game();
    ~Game();
    bool checkAvailable(int x, int y);
    void markReveal(int x, int y);
    void markBomb(int x, int y);
    void unMarkBomb(int x, int y);
    //check win is a method that updates 
    bool keepPlayin();
    void print();
    friend std::ostream& operator<<(std::ostream& out, Game & g);
};

std::ostream& operator<<(std::ostream& out , Game &  g);

#endif
