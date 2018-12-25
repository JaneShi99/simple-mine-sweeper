#include <iostream>
#include "game.h"
#include <ctime>
#include "cell.h"
Game::Game(){
	//initialize board
	std::vector<std::vector<Cell>> board(Game::width,
			std::vector<Cell>(Game::height));

	//initialize the cell add neighbours
	for(int i = 0; i < width; ++i){
		for(int j = 0; j < width; ++ j){
			for (int xIndex = i - 1; xIndex <= i + 1; ++ xIndex)
			{
				for(int yIndex = j - 1; yIndex <= j + 1; ++ yIndex){
					if (checkAvailable(xIndex,yIndex) && (xIndex !=i || yIndex != j) ){
						std::cout<<"adding neighbour "<<xIndex<<","<<yIndex<<" to the cell "<<i<<","<<j<<std::endl;
						board[i][j].addNeighbour(&board[xIndex][yIndex]);
					}
				}
			}
		}
	}
	//set up bombs
	while(bombs.size() != bombsCount){
		int x = rand() % width;
		int y = rand() % height;
		bombs[std::make_pair(x,y)] = 1;
		std::cout<<x<<" "<<y<<std::endl;
		board[x][y].setIsBomb(true);
	}   
	//set the number of bomb neighbours right for each cell
	for(auto &col: board){
		for(auto &elem: col){
			elem.countBombsAroundMe();
		}
	}

	std::cout<<"****INIT THE BOARD PRINTING*****"<<std::endl;

	for(int i = 0; i < height; ++i){
		for(int j = 0; j < width;++j){
			std::cout<<board[i][j].getPrintChar();
		}
		std::cout<<std::endl;
	}
}

Game::~Game(){}


void Game::markBomb(int x, int y){
	if(checkAvailable(x,y)){

		if (bombs.count(std::make_pair(x,y)) ==0 )
		{
			markedBombs[std::make_pair(x,y)] = 2;
		}
		else{
			markedBombs[std::make_pair(x,y)] = 1;
		}

		board[x][y].setIsBomb(true);
	}
}
void Game::unMarkBomb(int x, int y){
	if(markedBombs.count(std::make_pair(x,y))){
		markedBombs.erase(std::make_pair(x,y));
	}

}

bool Game::checkAvailable(int x, int y){
	return (0 <= x && x < width && 0 <= y && y < height);
}

void Game::markReveal(int x, int y){
	if(checkAvailable(x , y)){
		board[x][y].markCellReveal();     
	}
}

bool Game::keepPlayin(){
	//1. if a cell is revealed and it is marked as bomb THEN GG
	for(int i = 0; i < width ; ++ i){
		for(int j = 0; j < height; ++j){
			if(board[i][j].getIsBomb() && board[i][j].getIsRevealed())
			{
				//welp you lost you gg
				win = false;
				return false;
			}
		}
	}
	//2. if markedBombs equal real Bombs then return WIN

	bool checkWin = true;
	if (markedBombs.size() != bombsCount) { checkWin = false;} 
	for(auto &it: markedBombs){
		if(it.second == 2){checkWin = false;}
	}
	if(checkWin){
		win = true;
		return false;
	}
	//3. otherwise keep playing
	return true;
}

std::ostream& operator<<(std::ostream& out , Game& g){
	std::cout<<"****TEST PRINTING ****"<<std::endl;
	for(int i = 0 ; i < g.width; ++i)
	{
		std::cout<<i<<std::endl;
		for(int j = 0; j < g.height; ++j){
			std::cout<<j<<std::endl;
			std::cout<<"*****TEST******"<<((g.board)[i][j]).getPrintChar();
			char c = (g.board)[i][j].getPrintChar();
			out<<c;
		}
		out<<std::endl;
	}
	return out;
}

