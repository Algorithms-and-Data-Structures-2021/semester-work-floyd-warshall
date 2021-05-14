#include <iostream>

#include "floyd-warshall_algorithm.hpp"

using namespace std;

int main() {
  vector<vector<int>> w = {{0, 5, 9, 100}, {100, 0, 2, 8}, {100, 100, 0, 7}, {4, 100, 100, 0}};
  itis::floyd(w);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << w[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}