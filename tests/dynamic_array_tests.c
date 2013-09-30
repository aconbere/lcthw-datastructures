#include "minunit.h"
#include <dynamic_array.h>
#include <assert.h>

static DArray *darray = NULL;

char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";

char *test_create() {
  darray = DArray_create(sizeof(char *), 100);
  mu_assert(darray != NULL, "Failed to create dynamic array");
  return NULL;
}

// char *test_destroy() {
//   DArray_clear_destroy(darray);
//   return NULL;
// }
// 
// char *test_push_pop() {
//   int x = 1;
//   mu_assert(x == 0, "fail");
//   DArray_push(darray, test1);
//   mu_assert(DArray_last(darray) == test1, "Wrong last value");
// 
//   DArray_push(darray, test2);
//   mu_assert(DArray_last(darray) == test2, "Wrong last value");
// 
//   DArray_push(darray, test3);
//   mu_assert(DArray_last(darray) == test3, "Wrong last value.");
// 
//   char *val = DArray_pop(darray);
//   mu_assert(val == test3, "Wrong value on pop.");
// 
//   val = DArray_pop(darray);
//   mu_assert(val == test2, "Wrong value on pop.");
// 
//   val = DArray_pop(darray);
//   mu_assert(val == test1, "Wrong value on pop.");
//   return NULL;
// }
 

char *all_tests() {
  mu_suite_start();

  mu_run_test(test_create);
  // mu_run_test(test_destroy);
  // mu_run_test(test_push_pop);

  return NULL;
}

RUN_TESTS(all_tests);
