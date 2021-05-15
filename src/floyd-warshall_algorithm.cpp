#include "floyd-warshall_algorithm.hpp"

// файл с определениями

namespace itis {

  vector<vector<int>> floyd(vector<vector<int>> &w) {
    d = w;
    //заполнение массива next
    next.resize(w.size());
    for (int u = 0; u < w.size(); ++u) {
      for (int v = 0; v < w.size(); ++v) {
        next[u].push_back(v);
      }
    }

    for (int i = 0; i < d.size(); ++i) {
      for (int u = 0; u < d.size(); ++u) {
        for (int v = 0; v < d.size(); ++v) {
          if ((d[u][i] != -1 && d[i][v] != -1) && (d[u][i] + d[i][v] < d[u][v])) {
            d[u][v] = d[u][i] + d[i][v];
            next[u][v] = next[u][i];
          }
        }
      }
    }
    return d;
  }

  string getShortestPath(int u, int v) {
    //-1 значит, что до двух вершин нет пути
    if (d[u][v] == -1) {
      return "No path found";
    }

    string result = "";
    int c = u;
    while (c != v) {
      result = result + to_string(c) + " ";
      c = next[c][v];
    }
    result += to_string(v);
    return result;
  }

}  // namespace itis