#include <iostream>

#include "floyd-warshall_algorithm.hpp"

using namespace std;

int main() {
  vector<vector<int>> w = {{0, 5, 9, 100}, {100, 0, 2, 8}, {100, 100, 0, 7}, {4, 100, 100, 0}};
  vector<vector<int>> d = itis::floyd(w);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << d[i][j] << " ";
    }
    cout << endl;
  }

  cout << itis::getShortestPath(0, 3);
  return 0;
}