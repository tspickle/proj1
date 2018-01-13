#include <stdlib.h>
#include "minunit.h"
#include "impl.h"

#define MAXSIZE 10

char *theEmptyArray[] = {NULL};

char *theStaticArray[] = {"this", "is", "an", "array", "of", "strings", NULL};
int sortedIndices[] = {2,3,1,4,5,0}; // use to check array sorting

char *theArray[MAXSIZE];

char * test_array_len_0() {
  mu_assert("error, array_len !=0", array_len(theEmptyArray)==0);
  return 0;
}

char * test_array_len_6() {
  mu_assert("error, array_len !=6", array_len(theStaticArray)==6);
  return 0;
}

char *test_cmp_array_true() {
    mu_assert("error, com array returned false", array_cmp(theStaticArray, theStaticArray));
    return 0;
}

char * test_copy_array() {
    mu_assert("error, array_copy failed.", array_copy(theArray, theStaticArray, MAXSIZE, TRUE));
    return 0;
}

char * test_array_swap() {
    array_element_swap(theArray, theArray+2); // should swap "this" and "an"
    mu_assert("error, swap failed", (theArray[0] == theStaticArray[2]) && (theArray[2] == theStaticArray[0]));
    return 0;
}

char * test_array_sort1() {
    int len = array_len(theArray);
    array_sort(theArray, len);
    int result = 1;
    for (int i=0; (i<len) && result; i++) {
        result = result && (theArray[i] == theStaticArray[sortedIndices[i]]);
    }
    mu_assert("sort1 failed", result);
    return 0;
}

char * test_array_sort2() {
    int len = array_len(theArray);
    array_sort2(theArray, len);
    int result = 1;
    for (int i=0; (i<len) && result; i++) {
        result = result && (theArray[i] == theStaticArray[sortedIndices[i]]);
    }
    mu_assert("sort2 failed", result);
    return 0;
}
    
char * all_tests() {
  mu_run_test(test_array_len_0);
  mu_run_test(test_array_len_6);
  mu_run_test(test_cmp_array_true);
  mu_run_test(test_copy_array);
  mu_run_test(test_array_swap);
  mu_run_test(test_array_sort1);
  mu_run_test(test_array_sort2);
  return 0;
}
