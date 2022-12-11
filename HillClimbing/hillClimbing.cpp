// _Act 1.6.3_
// Francisco Aldaco
// Alejandro Flores
// Abraham De Alba
// Alfredo Onofre
// Pablo Ortega
#include <bits/stdc++.h>
#include "limits.h"

using namespace std;

float hard_cost(int x) {
  return -(sin(x-20)+10-abs(x-20)+pow(cos(x-20),2)+25*cos(0.05*x));
}

float ez_cost(int x) {
  return -(-0.1*pow(x,4)+0.2*pow(x,3)+pow(x,2)-x);
}

vector<int> generate_neighbours(int origin){
  
  vector<int> result;
  result.push_back(origin+1);
  result.push_back(origin-1);
  return result;
  
}
// Complejidad O(n)
// La precisión de del algortimo de hill_climb depende enteramente del número de iteraciones, por lo que apesar de ser un algoritmo lineal su uso requiere de más poder computacional.
// De igual manera, es altamente dependiente del punto inicial, siendo que solo encontrará el maximo local dentro del rango provisto.
int hill_climb_min(function<float(int)> cost, const int MAX_ITERATIONS, const int upperLimit, const int lowerLimit) {
  srand(time(NULL));
  int iter = 0;
  int localMax = rand() % (upperLimit-lowerLimit + 1) + lowerLimit;
  cout << "Initial point " << localMax << endl;
  while (iter < MAX_ITERATIONS) {
    // Find neighbours for current value
    vector<int> neighbours = generate_neighbours(localMax);
    // Find best neighbour
    for(int neighbour : neighbours){
      if(cost(neighbour) < cost(localMax)){
        localMax = neighbour;
      }
    }
    iter++;
  }
  return localMax;
}

int main() {
  cout << hill_climb_min(ez_cost, 100,10,-10) << endl;
  return 0;
  
}
