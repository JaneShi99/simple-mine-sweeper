#include "game.h"
#include <iostream>

game::game(){
    //initialize board
    std::vector<std::vector<Cell>> board(game::width,
            std::vector<Cell>(height));

    //initialize the cell add neighbours
    for(int i = 0; i < width; ++i){
        for(int j = 0; j < width; ++ j){

        }
    }
    
    //set the number of bomb neighbours right for each cell
    for(auto &col: board){
        for(auto &elem: col){
            elem.countBombsAroundMe();
        }
    }

    //set up bombs
}

game::~game(){}


void game::markBomb(int x, int y){}

void game::unMarkBomb(int x, int y){}

bool game::checkAvailable(int x, int y){
    return (0 <= x && x < width && 0 <= y && y < height);
}

bool game::markReveal(int x, int y){}

void game::checkWin(){
    //1. if a cell is revealed and it is marked as bomb THEN GG
    //2. if markedBombs equal real Bombs then return WIN
    //3. otherwise keep playing
}


std::ostream& operator<<(std::ostream&out , game g){
    for(int i = 0 ; i < g.width; ++i)
    {
        for(int j = 0; j < g.height; ++j){
            char c = (g.board)[i][j].getPrintChar();
            out<<c;
        }
        out<<std::endl;
    }

}

