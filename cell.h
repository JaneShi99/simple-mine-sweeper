#include<iostream>
#include<vector>

class Cell{
    std::vector<Cell *> neighbours;
    bool isBomb;
    bool isRevealed;
    int bombsAroundMe;
    bool initialized;

    public:

    Cell():isBomb{false},isRevealed{false},bombsAroundMe{0},initialized{false}{}
    
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
};
