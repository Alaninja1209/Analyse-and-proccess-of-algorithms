// _Act 1.6.3_
// Francisco Aldaco
// Alejandro Flores
// Abraham De Alba
// Alfredo Onofre
// Pablo Ortega
#include <bits/stdc++.h>

using namespace std;


float cost_fun(float x) {
  return -(sin(x-20)+10-abs(x-20)+pow(cos(x-20),2)+25*cos(0.05*x));
}


// Se observa que con el recocido simulado podemos encontrar a la vez varios mínimos. De igual forma vemos que al poder dar brincos aleatorios, hay situaciones en dónde encontramos los mínimos con menos iteraciones que con el hill climb
vector<float> sim_annealing(vector<float> gamma) {
  vector<float> cost_curr(gamma.size());
  vector<float> cost_next(gamma.size());
  vector<float> gamma_next(gamma.size());
  vector<float> delta(gamma.size());
  for (int i = 0; i < 10; i++)
    cost_curr[i] = cost_fun(gamma[i]);
  for (int temp = 100; temp >= 0; temp -= 10) {
    for (int k = 0; k < 100; k++) {
      for (int i = 0; i < 10; i++) {
        gamma_next[i] = gamma[i] + 2*pow(-1,rand() % 2);
        cost_next[i] = cost_fun(gamma_next[i]);
        delta[i] = cost_next[i] - cost_curr[i];
        if (delta[i] > 0) {
          double r = rand() / (RAND_MAX + 1.0);
          if (r <= exp(-1 * delta[i] / temp)){
            gamma[i] = gamma_next[i];
            cost_curr[i] = cost_next[i];
          }
        } else {
          gamma[i] = gamma_next[i];
          cost_curr[i] = cost_next[i];
        }
      }
    }
  }
  return gamma;
}

int main() {
  srand(time(NULL));
  vector<float> gamma(10);
  vector<float> gamma_out(10);
  for (int i = 0; i < 10; i++)
    gamma[i] = rand() % 100 - 50;
  gamma_out = sim_annealing(gamma);
  cout << "Input:" << endl;
  for (int i = 0; i < 10; i++)
    cout << gamma[i] << " " << endl;
  cout << "\nOutput:" << endl;
  for (int i = 0; i < 10; i++)
    cout << gamma_out[i] << " " << endl;
  return 0;
}
