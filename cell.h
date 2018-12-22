#include<iostream>
#include<vector>

class Cell{
    std::vector<Cell *> neighbours;
    bool isBomb;
    bool isRevealed;
    int bombsAroundMe;
    bool initialized;

    public:
    void setIsBomb(bool b){isBomb = b;}
    
    void setIsRevealed(bool b){isRevealed = b;}

    void countBombsAroundMe(){
      if(!initialized)
      {
        for(auto& it: neighbours){
            bombsAroundMe += it->notify();
        }
    }
    }
    int notify(){return isBomb? 1 :  0;}
};
