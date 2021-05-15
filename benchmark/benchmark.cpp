#include <fstream>
#include <chrono>
#include <floyd-warshall_algorithm.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace itis;

static constexpr auto kProjectPath = string_view{PROJECT_DATASET_DIR};

void time_for_merge(int x, int a) {
  const auto path = string(kProjectPath);
  ifstream fin;
  string num_of_incoming_data = to_string(x);
  string set_num = to_string(a);
  vector<vector<int>> graph;
  fin.open(path + "/" + num_of_incoming_data + "(" + set_num + ").txt");
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < x; ++j) {
      vector<int> vector;
      for (int k = 0; k < x; ++k) {
        if (!fin.is_open()) {
          cout << "Error" << endl;
        } else {
          int q;
          fin >> q;
          vector.push_back(q);
        }
      }
      graph.push_back(vector);
    }
  }
  fin.close();
  const auto time_point_before = chrono::high_resolution_clock::now();
  itis::floyd(graph);
  const auto time_point_after = chrono::high_resolution_clock::now();

  const auto time_diff = time_point_after - time_point_before;
  const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

  cout << "time wasted to use algorithm on ints in file " + num_of_incoming_data + "(" + set_num + ").txt ="
       << time_elapsed_ns << '\n';
}

int main() {
  int a[14] = {100, 500, 1000, 2500, 5000, 10000, 25000, 50000, 75000, 100000, 250000, 500000, 750000, 1000000};
  for (int i = 0; i < 14; i++) {
    for (int j = 1; j < 11; j++) {

    }
  }

  return 0;
}