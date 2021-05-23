#include <fstream>
#include <chrono>
#include <floyd-warshall_algorithm.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace itis;

static constexpr auto kProjectPath = string_view{PROJECT_DATASET_DIR};

void time_for_algorithm(int x, int a) {
  const auto path = string(kProjectPath);
  ifstream fin;
  string num_of_incoming_data = to_string(x);
  string set_num = to_string(a);
  fin.open(path + "/" + num_of_incoming_data + "(" + set_num + ").txt");
  x =(int) sqrt(x);
  vector<vector<int>> graph(x, vector<int>(x));

  for (int j = 0; j < x; ++j) {
    for (int k = 0; k < x; ++k) {
      if (!fin.is_open()) {
        cout << "Error" << endl;
      } else {
        int q;
        fin >> q;
        graph[j][k] = q;
      }
    }
  }

  fin.close();
  const auto time_point_before = chrono::high_resolution_clock::now();
  itis::floyd(graph);
  const auto time_point_after = chrono::high_resolution_clock::now();

  const auto time_diff = time_point_after - time_point_before;
  const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

  string str = to_string(time_elapsed_ns);

  cout << "time wasted to use algorithm on ints in file " + num_of_incoming_data + "(" + set_num + ").txt =" << str << '\n';
}

void time_for_getShortestPath(int x, int a) {
  const auto path = string(kProjectPath);
  ifstream fin;
  string num_of_incoming_data = to_string(x);
  string set_num = to_string(a);
  fin.open(path + "/" + num_of_incoming_data + "(" + set_num + ").txt");
  x =(int) sqrt(x);
  vector<vector<int>> graph(x, vector<int>(x));

  for (int j = 0; j < x; ++j) {
    for (int k = 0; k < x; ++k) {
      if (!fin.is_open()) {
        cout << "Error" << endl;
      } else {
        int q;
        fin >> q;
        graph[j][k] = q;
      }
    }
  }

  fin.close();
  int q;
  int w;
  itis::floyd(graph);
  if(x<32000){
    q = rand() % x;
    w = rand() % x;
  } else{
    q = rand();
    w = rand();
  }
  const auto time_point_before = chrono::high_resolution_clock::now();
  itis::getShortestPath(q, w);
  const auto time_point_after = chrono::high_resolution_clock::now();

  const auto time_diff = time_point_after - time_point_before;
  const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

  string str = to_string(time_elapsed_ns);

  cout << "time wasted to get shorted path in file " + num_of_incoming_data + "(" + set_num + ").txt =" << str << '\n';
}

int main() {
  int a[14] = {100, 625, 1024, 2500, 5041, 10000, 24964, 50176, 75076, 99856, 250000, 499849, 749956, 1000000};
  for (int i = 0; i < 14; i++) {
    for (int j = 1; j < 11; j++) {
      for (int k = 0; k < 10; ++k) {
        time_for_algorithm(a[i], j);
        //time_for_getShortestPath(a[i], j);
      }
    }
  }

  return 0;
}