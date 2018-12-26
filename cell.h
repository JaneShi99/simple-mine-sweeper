#ifndef __CELL_H__
#define __CELL_H__

#include<iostream>
#include<vector>
#include<string>
class Cell{
    std::vector<Cell *> neighbours;
    bool isBomb;
    bool isRevealed;
    int bombsAroundMe;
    bool initialized;
    bool flagged;

    public:

    Cell():isBomb{false},isRevealed{false},bombsAroundMe{0},initialized{false},flagged{false}{}
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

    void  setFlagged(bool b){flagged = b;}	
    char getPrintChar(){

        //the following is for tests
        //
        //std::cout<<bombsAroundMe;
        /*
        if(isBomb){return '*';}
        else if (!isBomb){

            //in here also make sure!!!
            std::string s = std::to_string(bombsAroundMe);    
            if( s.at(0) == '0'){return ' ';}
            else {return s.at(0);}
        }
        else{return '.';}
        */
        //testing if blocks ends here

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
            std::string s = std::to_string(bombsAroundMe);    
            if( s.at(0) == '0'){return ' ';}
            else {return s.at(0);}
        }   
        else
        {   //this case should not happen
            //then it is marked as bomb
            return 'F';
        }
    } 

    void markCellReveal(){
       // std::cout<<"revealing cell"<<std::endl;
        if(!isBomb){
            if(bombsAroundMe != 0 ){
                isRevealed = true; 
            }
            if(bombsAroundMe == 0){
            isRevealed = true;
            for(auto &it: neighbours){
                if(!it->getIsBomb())
                {
                it->markCellReveal();
                }
            }}
        }
    }

};
#endif
