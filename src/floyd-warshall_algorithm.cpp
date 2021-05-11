#include "floyd-warshall_algorithm.hpp"

// файл с определениями

namespace itis {

  void floyd(vector<vector<int>> &w) {
    vector<vector<int>> next = w;
    for (int i = 0; i < w.size(); ++i) {
      for (int u = 0; u < w.size(); ++u) {
        for (int v = 0; v < w.size(); ++v) {
          if (w[u][i] + w[i][v] < w[u][v]) {
            w[u][v] = w[u][i] + w[i][v];
            next[u][v] = next[u][i];
          }
        }
      }
    }
  }

}  // namespace itis