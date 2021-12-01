/*
Run executable with flag such as
-a : add
-p : print
-m : merge
-c : complete
etc

*/

// scratch ...

#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
int main() {
  auto start = std::chrono::system_clock::now();
  std::time_t stime = std::chrono::system_clock::to_time_t(start);
  cout << std::ctime(&stime) << endl;
}