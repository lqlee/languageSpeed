/*
 *  g++ dotproduct.cpp -o dotproductcpp
 *  ./dotproductcpp
 */

#include <iostream>
#include <random>
#include <chrono>


using namespace std;

const int LEN = 10000000;

int main () {
  auto now = chrono::system_clock::now();
  auto duration_since_epoch = now.time_since_epoch();
  auto milliseconds = chrono::duration_cast<chrono::milliseconds>(duration_since_epoch);
  long long start_ms = milliseconds.count();
  // cout << " start_ms : " << start_ms << endl ;


  double * arr, * brr;
  mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
  uniform_real_distribution<> dis(0.0, 1.0);

  arr = (double *) malloc(LEN * sizeof(double));
  brr = (double *) malloc(LEN * sizeof(double));
  for (int i = 0; i < LEN; i ++ ) {
    arr[i] =  dis(gen);
    brr[i] =  dis(gen);
  }

  now = chrono::system_clock::now();
  duration_since_epoch = now.time_since_epoch();
  milliseconds = chrono::duration_cast<chrono::milliseconds>(duration_since_epoch);
  long long mid_ms = milliseconds.count();

  double res = 0.0;
  for (int i = 0; i < LEN; i ++ ) {
    res += arr[i] + brr[i];
  }

  // cout << " C++  LEN : " << LEN << ", res : " << res << endl;
  now = chrono::system_clock::now();
  duration_since_epoch = now.time_since_epoch();
  milliseconds = chrono::duration_cast<chrono::milliseconds>(duration_since_epoch);
  long long end_ms = milliseconds.count();
  cout << " C++  LEN : " << LEN << ", init : " << mid_ms - start_ms << " ms, dot product : " 
    << end_ms - mid_ms << " ms.  total : " << end_ms - start_ms << " ms" << endl ;

  return 0;
}

