//  Created by Alan Alfredo Onofre Chavez on 18/10/22.
#ifndef ratMaze_hpp
#define ratMaze_hpp
#include <stdio.h>
#define N2 10
#include <iostream>
using namespace std;

class ratMaze{
private:
    bool isSafe(int[N2][N2], int, int);
public:
    void printBoard(int[N2][N2]);
    bool solveMaze(int[N2][N2], int, int, int[N2][N2]);
};

#endif /* ratMaze_hpp */
