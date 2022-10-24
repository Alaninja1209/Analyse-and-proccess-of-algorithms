//  Created by Alan Alfredo Onofre Chavez on 18/10/22.
#ifndef queenProblem_hpp
#define queenProblem_hpp
#include <iostream>
#define N 10
using namespace std;

class queenProblem{
public:
    void printBoard(int[N][N]);
    bool solveQueen(int [N][N], int);
private:
    bool isSafe(int[N][N], int, int);
};

#endif /* queenProblem_hpp */
