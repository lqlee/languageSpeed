/*
 * gcc dotproduct.c -o dotproductc
 * ./dotprodutc
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h> // For uint64_t

const int LEN = 10000000;

int main () {
  struct timespec spec;
  uint64_t start_ms, mid_ms, end_ms;

  srand(time(NULL));
  double * arr,  * brr;

  if (clock_gettime(CLOCK_REALTIME, &spec) == -1) {
    perror("clock_gettime");
    return 1;
  }

  // Convert seconds and nanoseconds to milliseconds
  start_ms = (uint64_t)spec.tv_sec * 1000 + (uint64_t)spec.tv_nsec / 1000000;

  // printf("Current time in ms : %lu\n", start_ms);

  arr = (double*) malloc(LEN * sizeof(double));
  brr = (double*) malloc(LEN * sizeof(double));
  for (int i = 0; i < LEN; i ++ ) {
      arr[i] = 0.01; // (double)rand() / (RAND_MAX + 1.0);
      brr[i] = 0.01; // (double)rand() / (RAND_MAX + 1.0);
  }

  if (clock_gettime(CLOCK_REALTIME, &spec) == -1) {
    perror("clock_gettime");
    return 1;
  }

  // Convert seconds and nanoseconds to milliseconds
  mid_ms = (uint64_t)spec.tv_sec * 1000 + (uint64_t)spec.tv_nsec / 1000000;
  int start = (int) (start_ms % 100000); 
  int mid = (int) (mid_ms % 100000); 

  //printf("Current time in ms : %lu, array init takes : %d ms. \n", 
  //  mid_ms, (int)(mid_ms  - start_ms ) );

  double res = 0.0;
  for (int i = 0; i < LEN; i ++ ) {
    res += arr[i] * brr[i];
  }

  if (clock_gettime(CLOCK_REALTIME, &spec) == -1) {
    perror("clock_gettime");
    return 1;
  }

  // Convert seconds and nanoseconds to milliseconds
  end_ms = (uint64_t)spec.tv_sec * 1000 + (uint64_t)spec.tv_nsec / 1000000;
  int end = (int) (end_ms % 100000); 

  /* printf("Current time in ms : %lu, dot product takes  : %d ms, total : %d . \n", 
    end_ms, (int)(end_ms  - mid_ms ) , (int)(end_ms  - start_ms ) );
  printf (" LEN : %d,  res : %f \n", LEN, res );
  */
  printf(" C  LEN : %d, init : %d ms, dot product : %d ms, total : %d ms\n", LEN,
    (int)(mid_ms - start_ms), (int)(end_ms - mid_ms), (int)(end_ms - start_ms) );
  return 0;
}

