//  Created by Alan Alfredo Onofre Chavez on 18/10/22.
//Referencia: https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
#include "ratMaze.hpp"

void ratMaze::printBoard(int solution[N2][N2]){
    for(int i = 0; i < N2; i++){
        for(int j = 0; j < N2; j++){
            cout<<solution[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool ratMaze::isSafe(int board[N2][N2], int x, int y){
    if(x >= 0 && x < N2 && y >= 0 && y < N2 && board[x][y] == 1){
        return true;
    }
    return false;
}

bool ratMaze::solveMaze(int board[N2][N2], int x, int y, int solution[N2][N2]){
    if(x == N2 - 1 && y == N2 - 1 && board[x][y] == 1){
        solution[x][y] = 1;
        return true;
    }
    
    if(isSafe(board, x, y) == true){
        if(solution[x][y] == 1){
            return false;
        }
        solution[x][y] = 1;
        if(solveMaze(board, x + 1, y, solution) == true){
            return true;
        }
        if(solveMaze(board, x, y + 1, solution) == true){
            return true;
        }
        if(solveMaze(board, x - 1, y, solution) == true){
            return true;
        }
        if(solveMaze(board, x, y - 1, solution) == true){
            return true;
        }
        solution[x][y] = 0;
        return false;
    }
    return false;
}
