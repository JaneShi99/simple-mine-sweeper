#ifndef __CELL_H__
#define __CELL_H__

#include<iostream>
#include<vector>

class Cell{
    std::vector<Cell *> neighbours;
    bool isBomb;
    bool isRevealed;
    int bombsAroundMe;
    bool initialized;
    bool flagged;

    public:

    Cell():isBomb{false},isRevealed{false},bombsAroundMe{0},initialized{false}{}
    ~Cell(){} 
    void addNeighbour(Cell * n ){neighbours.emplace_back(n);}

    void setIsBomb(bool b){isBomb = b;}

    void setIsRevealed(bool b){isRevealed = b;}

    void countBombsAroundMe(){
        if(!initialized)
        {
            for(auto& it: neighbours){
                bombsAroundMe += it->notify();
            }
        }
        initialized = true;
    }
    int notify(){return isBomb? 1 :  0;}

    bool getIsBomb(){return isBomb;}

    bool getIsRevealed(){return isRevealed;}

    int getBombsAroundMe(){return bombsAroundMe;}

    char getPrintChar(){
        if(!isRevealed && !flagged){
            return '.';
        }
        else if (!isRevealed && flagged){
            return 'F';
        }
        else if(isBomb && isRevealed){
            return '*';
        }
        else if(!isBomb && isRevealed){
            if (bombsAroundMe == 0) {return ' ';}
            else {return static_cast<char>(bombsAroundMe);}
        }   
        else
        {   //this case should not happen
            //then it is marked as bomb
            return 'F';
        }
    } 

    void markCellReveal(){
        if(!isBomb){
            isRevealed = true;
            for(auto &it: neighbours){
                it->markCellReveal();
            }
        }
    }

};
#endif
