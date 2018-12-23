#include <iostream>
#include <vector>
class Cell;
class textDisplay{
    std::vector<std::vector<Cell> > board;
    
    public:
    textDisplay();
    ~textDisplay();
    void print(std::vector<std::vector<Cell>> );

};
