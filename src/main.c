#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
#include "test_pointers_arrays.h"

int tests_run = 0;  // global variable used by minunit
 
int main(int argc, char **argv) {
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);
 
  return result != 0;
}

