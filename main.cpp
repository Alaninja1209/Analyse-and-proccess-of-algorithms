//  Created by Alan Alfredo Onofre Chavez on 18/10/22.
// Complejidad laberinto O(2^(n^2))
// 
#include "queenProblem.hpp"
#include "ratMaze.hpp"

int main() {
    queenProblem* Queen = nullptr;
    ratMaze* Rat = nullptr;
    int board[N][N] = {{0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0}};
    if(Queen -> solveQueen(board, 0) == false){
        cout<<"No solution "<<endl;
        return 0;
    }
    cout<<"----Queen Problem-----"<<endl;
    Queen -> printBoard(board);
    
    int boardRat[N2][N2] = {{1,0,0,0,0,0,0,0,0,0},
                            {1,1,1,0,0,1,1,1,0,0},
                            {0,0,1,1,0,0,0,1,0,0},
                            {1,1,1,0,1,1,1,1,0,0},
                            {1,0,0,0,1,0,0,1,1,0},
                            {1,1,1,1,1,0,1,1,0,0},
                            {0,0,0,0,0,0,1,0,0,0},
                            {0,0,1,1,1,1,1,0,0,1},
                            {0,0,0,0,1,0,1,1,1,1},
                            {0,0,0,0,1,0,0,0,0,1}};
    
    cout<<"---Laberynth to troubleshoot---"<<endl;
    Rat -> printBoard(boardRat);
    
    int boardSolution[N2][N2] = {{0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0}};
    
    cout<<"--Laberynth solved--"<<endl;
    if(Rat -> solveMaze(boardRat, 0, 0, boardSolution) == false){
        cout<<"No solution "<<endl;
        return 0;
    }
    Rat -> printBoard(boardSolution);
    cout<<"----------Cheeseeeee!!!!--------"<<endl;
    return 0;
}

