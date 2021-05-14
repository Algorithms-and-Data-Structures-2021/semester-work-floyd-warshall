#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

void create_data_for_split_delete_find(string path, int x) {
  ofstream fout;
  fout.open(path);

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
  int a[14] = {100, 500, 1000, 2500, 5000, 10000, 25000, 50000, 75000, 100000, 250000, 500000, 750000, 1000000};
  cout << "Процесс генерации тестовых данных начат! Ожидайте..." << endl;
  for (int j = 0; j < 14; ++j) {
    for (int k = 1; k < 11; ++k) {
      string s1 = to_string(a[j]);
      string s2 = to_string(k);
      create_data_for_split_delete_find(path + "/" + s1 + "(" + s2 + ").txt", a[j]);
    }
  }
  cout << "Данные успешно сгенерированы" << endl;

  return 0;
}