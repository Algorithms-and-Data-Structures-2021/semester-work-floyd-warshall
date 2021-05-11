#pragma once
#include <vector>
using namespace std;

// Заголовочный файл с объявлением структуры данных

namespace itis {

  //нахождение кратчайших длин по алгоритму Флойда–Уоршелла
  void floyd(vector<vector<int>> &w);

  //получение самого пути (кратчайшего) между вершинами
  int getShortestPath(int u, int v);

}  // namespace itis