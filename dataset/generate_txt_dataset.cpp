#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>
#include <cmath>

using namespace std;
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

void create_matrix(string path, int x) {
  ofstream fout;
  fout.open(path);
  x = sqrt(x);
  if (!fout.is_open()) {
    cout << "Error" << endl;
  } else {
    if (x < 500) {
      this_thread::sleep_for(std::chrono::nanoseconds(700000000));
    }
    srand(time(nullptr));
    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < x; j++) {
        int c = rand();
        if(j!=x-1){
          fout << c << " ";
        } else{
          if(i!=x-1){
            fout << c << endl;
          } else{
            fout << c;
          }
        }
      }
    }
  }
  fout.close();
}

int main() {
  const auto path = string(kDatasetPath);  // конвертация string_view в string
  int a[14] = {100, 625, 1024, 2500, 5041, 10000, 24964, 50176, 75076, 99856, 250000, 499849, 749956, 1000000};
  cout << "Started! Wait..." << endl;
  for (int j = 0; j < 14; ++j) {
    for (int k = 1; k < 11; ++k) {
      string s1 = to_string(a[j]);
      string s2 = to_string(k);
      create_matrix(path + "/" + s1 + "(" + s2 + ").txt", a[j]);
    }
  }
  cout << "Completed!" << endl;

  return 0;
}