#include <iostream>

#include "floyd-warshall_algorithm.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  for (int index = 0; index < argc; index++) {
    cout << index << ": " << argv[index] << endl;
  }
  return 0;
}