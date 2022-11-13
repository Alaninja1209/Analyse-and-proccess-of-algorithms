// 1.5.1 Actividad en clase
/*
Francisco José Ramírez Aldaco A01634262
Pablo Agustín Ortega-Kral A003444664
Abraham De Alba Franco A01634133
Alejandro Flores Madriz A01634167
Alan Alfredo Onofre Chávez A01632858
Asumiendo un número infinito de denominaciones y dada una cantidad C. Regresa la
forma más eficiente de formar C con el menor número de denominaciones usadas
*/
#include <cmath>
#include <iostream>
#include <limits.h>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;
int give_change_inf(vector<int> denominations, int amount) {
  vector<int> solution(amount + 1);
  vector<int> coins_count(denominations.size());
  vector<int> choice_taken(denominations.size());
  for (int i = 1; i <= amount; i++) {
    int temp = INT_MAX;
    int j = 0;
    while (j < denominations.size() && i >= denominations[j]) {
      temp = min(solution[i - denominations[j]], temp);
      j++;
    }
    solution[i] = temp + 1;
  }
  return solution[amount];
}
int main(int argc, char *argv[]) {
  int sol;
  srand(time(NULL));
  int testcase = atoi(argv[1]);
  vector<int> pesos = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
  switch (testcase) {
  case 1: {
    cout << "Prueba 1: 10 pesos\n";
    sol = give_change_inf(pesos, 10);
    break;
  }
  case 2: {
    cout << "Prueba 1: 40 pesos\n";
    sol = give_change_inf(pesos, 40);
    break;
  }
  case 3: {
    cout << "Prueba 1: 157 pesos\n";
    sol = give_change_inf(pesos, 157);
    break;
  }
  case 4: {
    int r = random() % 10000;
    cout << "Prueba random con " << r << endl;
    sol = give_change_inf(pesos, r);
    break;
  }
  case 5: {
    cout << "Prueba con  1888" << endl;
    sol = give_change_inf(pesos, 1888);
    break;
  }
  default:
    cout << "Not a valid test case\n" << endl;
  }
  printf("Monedas necesitadas: %d \n", sol);
}
